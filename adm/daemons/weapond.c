// weapond.c
// moved slash weapon and poison hit here.
// by snowman@SJ.
// Modified by snowman@SJ 01/05/2001

#include <ansi.h>
#include <combat.h>

mapping	weapon_actions = ([
	"slash": ([
		"damage_type":	"����",
		"action":		"$N�Ӷ�$w��ն��$n��$l",
		"parry":		20,
		]),
	"slice": ([
		"damage_type":	"����",
		"action":		"$N��$w��$n��$l��ȥ",
		"dodge":		20,
		]),
	"chop":	([
		"damage_type":	"����",
		"action":		"$N��$w����$n��$l������ȥ",
		"parry":		-20,
		]),
	"hack":	([
		"action":		"$N����$w����׼$n��$lһ���ҿ�",
		"damage_type":	"����",
		"damage":		30,
		"dodge":		30,
		]),
	"thrust": ([
		"damage_type":	"����",
		"action":		"$N��$w��$n��$l��ȥ",
		"dodge":		15,
		"parry":		-15,
		]),
	"pierce": ([
		"action":		"$N��$w��$n��$l�ݺݵ�һͱ",
		"damage_type":	"����",
		"dodge":		-30,
		"parry":		-30,
		]),
	"whip":	([
		"action":		"$N��$wһ���$n��$l��ȥ",
		"damage_type":	"����",
		"dodge":		-20,
		"parry":		30,
		]),
	"impale": ([
		"action":		"$N��$w��$n��$lֱ����ȥ",
		"damage_type":	"����",
		"dodge":		-10,
		"parry":		-10,
		]),
	"bash":	([
		"action":		"$N����$w����$n��$l����һ��",
		"damage_type":	"����",
		]),
	"crush": ([
		"action":		"$N�߸߾���$w����$n��$l��ͷ����",
		"damage_type":	"����",
		]),
	"slam":	([
		"action":		"$N����$w����¶�׹⣬�͵ض�׼$n��$l���˹�ȥ",
		"damage_type":	"����",
		]),
	"throw": ([
		"action":		"$N��$w��׼$n��$l���˹�ȥ",
		"damage_type":	"����",
		"post_action":	(: call_other, __FILE__, "throw_weapon"	:),
		]),
]);

varargs	mapping	query_action()
{
	string verb, *verbs;

	verbs =	previous_object()->query("verbs");

	if( !pointerp(verbs) ) return weapon_actions["hit"];
	else {
		verb = verbs[random(sizeof(verbs))];
		if( !undefinedp(weapon_actions[verb]) )	return weapon_actions[verb];
		else return weapon_actions["hit"];
	}	
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
	if( objectp(weapon) ) {
		if( (int)weapon->query_amount()==1 ) {
			weapon->unequip();
			tell_object(me,	"\n���" + weapon->query("name") + "�����ˣ�\n");
		}
		weapon->add_amount(-1);
	}
}

function bash_weapon(object me,	object victim, object weapon, int damage)
{
	return (: call_other, __FILE__,	"weapon_cut", me, victim, weapon, damage :);

}


int weapon_cut(object me, object victim, object	weapon,	object vweapon,	int damage)
{	
	int wp,	wap, wdp, i, j, k=0,pnum,pnum2;
	string poison;
	
	if(!objectp(weapon) ) return 0;	

	// poisoned weapon hit.
	if (stringp(poison = weapon->query("poisoned"))	
	&& intp(wp = weapon->query("poison_number")) 
        && random(10) > 5  
        && me->query("combat_exp") > victim->query("combat_exp")
	&& wp >	1 
	&& victim->query_condition(poison) < 70) {     // upper	limit for poison hit.
		if (wp == 2)		       
			weapon->set_temp("apply/long", ({weapon->query("long")+"�����Ǳ�ι���綾������Ч���Ѿ��������ˡ�\n"}));
		weapon->add("poison_number", -1);
		if( mapp(weapon->query("weapon_mp")) )
			weapon->add("weapon_mp/poison_number", -1);
			
		pnum = 1 + random(10);
		pnum2 = CLOTH_D->armor_vs_poison(victim, pnum,poison);
		
		if( (pnum-pnum2) > 0 ) {
			victim->apply_condition(poison,	 victim->query_condition(poison) + pnum - pnum2);
			victim->set_temp("last_damage_from", me);
// ���ӡ�ͨ���� �����ô��˺� newbie  by Lane@SJ
			if( userp(me) && userp(victim) && me->query_condition("killer") < 15 )
				me->add_condition("killer", 15);
		}

                if(victim->query("race") == "����" && !victim->query("mute") && me->query("combat_exp") > victim->query("combat_exp"))
			message_vision(HIR"$Nֻ�����˿���һ�飬���һ�������ã�\n"NOR,victim);
		else if(victim->query("race") == "����")
			message_vision(HIR"$Nֻ�����˿���һ�飬üͷһ������Ȼ�Ƿ�ŭ�ˣ�\n"NOR,victim);
		else  message_vision(HIR"$N��Ȼһ�����˿ڴ�������Ѫ�������¶��\n"NOR,victim);

                if( pnum2 >= pnum )
			message_vision(HIC"����$N�ƺ���һ�����صĵֿ����Ե���������ȫ���ܶ��Ե��˺���\n"NOR,victim);
		else if( pnum2 > (pnum/2) )
			message_vision(HIC"����$N�ƺ���һ�����صĵֿ����Ե������������˴󲿷ֵĶ����˺���\n"NOR,victim);
		else if( pnum2 > 0 )
			message_vision(HIC"����$N�ƺ���һ�����صĵֿ����Ե������������˲��ֵĶ����˺���\n"NOR,victim);

		if (!victim->is_killing(me->query("id")) && !userp(victim))
			victim->kill_ob(me);
	}

	if( weapon->query("skill_type")	== "throwing" && damage	!= RESULT_PARRY) {
		weapon = new(base_name(weapon));
		weapon->set_amount(1);
		weapon->move(environment(victim));
		return 0;
	}
	
	if (damage == RESULT_PARRY) {
		if(vweapon) i=(vweapon->query("sharpness")+vweapon->query_temp("apply/sharpness")+1)/3; else i=1;
		if(weapon)  j=( weapon->query("sharpness")+ weapon->query_temp("apply/sharpness")+1)/3; else j=1;
		if (i<1) i=1;
		if (j<1) j=1;
	}
	else {
		i = 1;
		j = 0;
	}
        if( intp(weapon->query("dur")) && weapon->query("dur")>0 && !weapon->query("weapon_prop/vipzb")&& !me->query("vip_as")) {
		weapon->add("dur",-i);
		if( mapp(weapon->query("weapon_mp")) )
			weapon->add("weapon_mp/dur",-i);
		if( weapon->query("dur") <= 0 ) {
			message_vision(HIW"$N���е�"+weapon->name()+HIW"ʹ�ù��ã����ڶ�Ϊ���أ�\n"NOR,me);
			weapon->broken();
			k = 1;
		}
	}
        if( objectp(vweapon) && intp(vweapon->query("dur")) && vweapon->query("dur")>0 && !vweapon->query("weapon_prop/vipzb")&& !me->query("vip_as")) {
		vweapon->add("dur",-j);
		if( mapp(vweapon->query("weapon_mp")) )
			vweapon->add("weapon_mp/dur",-j);
		if( vweapon->query("dur") <= 0 ) {
			message_vision(HIW"$N���е�"+vweapon->name()+HIW"ʹ�ù��ã����ڶ�Ϊ���أ�\n"NOR,victim);
			vweapon->broken();
			k = 1;
		}
	}
	if(k) return 1;
	
	if( !objectp(vweapon)) return 0;
	
	if( vweapon->query("skill_type") == "throwing" ) return	0;
	// hoho..... by	snowman@SJ
	if( intp(wp = vweapon->query_temp("no_weapon_cut")) ){
		wp--;
		if( wp <= 0 )	wp = 0;
		vweapon->set_temp("no_weapon_cut", wp);
		return 0;
	}
	
	// slash_weapon	cut.
        if( weapon->query("flag") == 4 && !vweapon->query("weapon_prop/vipzb") && !victim->query("vip_as"))  {
		wp = weapon->query("sharpness")	+ weapon->query_temp("apply/sharpness");
		wap = vweapon->query("sharpness") + vweapon->query_temp("apply/sharpness");
		wdp = vweapon->query("rigidity") + vweapon->query_temp("apply/rigidity");
                if( wp > 50 ) wp = 50;
                if( wap > 50 ) wap = 50;
                if( wdp > 10 ) wdp = 50;
		if( wp > 0 && wp > wap && wp > wdp && 
		((random(me->query("str")) > victim->query("str")/2 && damage == RESULT_PARRY)
		|| (random(me->query("str")) > victim->query("str")/3 && damage	> 0))){
			message_vision(WHT "ֻ�������ѡ���һ�����죬$N���е�"+vweapon->name()+WHT"�Ѿ���"+weapon->name()+WHT"��Ϊ���أ�\n"NOR, victim );
			vweapon->broken("�ϵ���");
		} 
		return 1;
	}
	     
	// bash_weapon break.
	else if( random(100) > 60 
		&& damage == RESULT_PARRY 
		&& weapon->query("skill_type") != "whip"
		&& vweapon->query("special") !=	"nobreak"
		&& vweapon->query("material") != "softsteel" 
		&& vweapon->query("skill_type")	!= "whip" 
		&& vweapon->query("rigidity") <= weapon->query("rigidity")) {	
			wap = ((int)weapon->query("rigidity")+weapon->query_temp("apply/rigidity")) * 5;
			wdp = ((int)vweapon->query("rigidity")+vweapon->query_temp("apply/rigidity")) *	5;	       

			wap *= weapon->query_amount() >	1?weapon->query_amount():1;
			wap *= (int)weapon->query("base_weight") / 500 + (int)me->query("str");
		      
			wdp *= vweapon->query_amount() > 1?vweapon->query_amount():1;
			wdp *= (int)vweapon->query("base_weight") / 500	+ (int)victim->query("str");
		      
			wap = random(wap);	    
                        if( wap > 2 * wdp&& !vweapon->query("weapon_prop/vipzb")&& !me->query("vip_as")) {
				message_vision(HIW "$Nֻ��������" + vweapon->name() + "�ѳֲ��������ַɳ���\n" NOR,victim);
				vweapon->unequip();
				vweapon->move(environment(victim));
				victim->reset_action();
			} 
                        else if( wap > wdp && !vweapon->query("weapon_prop/vipzb") && !me->query("vip_as")) {
				message_vision(HIW "ֻ������ž����һ����$N���е�"+vweapon->name()+"�Ѿ���Ϊ���أ�\n" NOR, victim );
				vweapon->broken("�ϵ���");
			}   
			else if( wap > wdp / 2 && random(2)) 
				message_vision("$Nֻ��������" +	vweapon->name()	+ "һ����Щ���֣�\n",victim);
		      
			else if( random(3) == 1) message_vision("$N��" + weapon->name()	+ "��$n��" + vweapon->name()+"�����ð�����Ļ��ǡ�\n", me, victim);
			return 1;
	}
	
	return 0;
}
