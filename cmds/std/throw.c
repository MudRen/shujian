// throwing.c

#include <ansi.h>;
#include <pktime.h>

inherit F_SSERVER;

string *emote = ({
	"sneer", "callname", "consider", "killair", "grin",
	"nonsense", "walkby", "cut", "chicken", "kick", "hehe",
	"brag"
});

int do_throw(object me, object ob, object victim);
int fushi_du(object me, object victim, object ob);
int can_kill_ob(object me, object ob);
private int throw_result(object me, object victim, object ob);

int main(object me, string arg)
{
	string what, who;
	object ob, victim;

	seteuid(geteuid(me));

	if( !arg ) return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");

        if( me->query("combat_exp") < 10000 )
		return notify_fail("�����΢�����������С�������Լ���\n");

	if(sscanf(arg, "%s at %s", what, who)!=2){
		if(!me->is_fighting())
			return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");
		else {
			who = offensive_target(me)->query("id");
			what = arg;
		}
	}

	ob = present(what, me);
	if (me->query_temp("quit"))
		return notify_fail("�����˳���Ϸ�У���������Ӷ�����\n");
	if (!ob) return notify_fail("��Ҫ��ʲô��\n");

	if (ob->query("no_drop"))
		return notify_fail("������������뿪�㡣\n");

	if (ob->query("unique") && !ob->query("embed"))
		return notify_fail(ob->name()+"�Ǳ�����ӻ���Ⱦ�����ġ�\n");

	if (ob->query("embedded"))
		return notify_fail("�����������ȡ��������\n");

	if (!(victim = present(who, environment(me))))
		return notify_fail("����û�����Ŀ�ꡣ\n");

	if (!victim || !victim->is_character())
		return notify_fail("���ﲢ�޴��ˣ�\n");

	if (me->query_temp("combat_yield"))
		return notify_fail("�����򲻻����أ���ô�ӣ�\n");

	if (!living(victim))
		return notify_fail("�ⲻ�ǻ��\n");
    
    if ( userp(victim) && me->query("combat_exp") < 1000000 && userp(me))
                return notify_fail("СС��;�Ҫ�������֣�����ѧ��ðɡ�\n");
	if (userp(victim) && userp(me)
	&& me->query("combat_exp") < me->query("mud_age")/6)
		return notify_fail("���㵱ǰ�Ľ������飬���������ð����ˡ�\n");

	if (victim->query("winner"))
		return notify_fail("���ɶ�"+victim->short()+"������\n");

	if (victim->query("no_ansuan") || victim->query("job_npc"))
		return notify_fail("Ҫɱ��ɱ����ʲô������\n");

	if (victim->query_temp("embed"))
		return notify_fail(victim->name()+"�Ѿ����а����ˣ�\n");

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (victim == me)
		return notify_fail("�αض��һ�٣�\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	if (!wizardp(me) && wizardp(victim))
		return notify_fail("����Ҫ����������ͻȻ����ֻ��������һ�Ž����ߵ�����׼����ʦ���˲�����\n");

	if (userp(me) && userp(victim) && victim->query("age") < 18)
		return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");

	if (userp(me) && userp(victim) &&
	!me->is_killing(victim->query("id")) &&
	victim->query("qi") < victim->query("max_qi")/2)
		return notify_fail("�Է��Ѿ��������ˣ��㻹��ֱ����ɱ�ְɡ�\n");

	if (me->is_exert() && ob == me->query_temp("weapon"))
		return notify_fail("������ʹ��"+me->query_exert()+"���޷��ӳ�"+ob->name()+"��\n");

	if (me->is_perform() && ob == me->query_temp("weapon"))
		return notify_fail("������ʹ��"+me->query_perform()+"���޷��ӳ�"+ob->name()+"��\n");

	if ( me->query("no_pk") && userp(victim))
		return notify_fail("���Ѿ�����ϴ�֣����ǲ�Ҫ���뽭����Թ�ɡ�\n");

	if ( userp(me) && victim->query("no_pk"))
		return notify_fail(victim->name()+ "�Ѿ�����ϴ�֣������˴������˰ɡ�\n");

	if (strsrch(file_name(environment(me)),"/d/wuguan/") >= 0)
		return notify_fail("����ڽ�ֹ͵Ϯ��\n");

// ��ֹ�� newbie ʹ�����ⰵ��
	if ( ob->query("embed") && userp(me) && userp(victim) && victim->query("combat_exp") < 1000000 )
		return notify_fail(victim->name()+ "�书��΢��û��Ҫ����ʹ�����ְ����ɣ�\n");


if (userp(me) && userp(victim) && victim->query("combat_exp")<200000) 
                return notify_fail("�Բ����밮��С���ѡ�\n");

if (userp(me) && userp(victim) && me->query("combat_exp")<  victim->query("combat_exp") * 2 /3 &&  !victim->query_condition("killer") ) 
                return notify_fail("�˼ұ���ǿ��ô�࣬��Ͳ����˼ұ�����\n");
		
if (userp(me) && userp(victim) && me->query("combat_exp") > victim->query("combat_exp") * 3 / 2 &&  !victim->query_condition("killer")) 
                return notify_fail("����˼�ǿ��ô�࣬����СϺ��Ҳֵ���㶯�֣�\n");
		









// ��ֹͬһ��ɱ��ͬһ��������
	if( !can_kill_ob(me, victim) )
		return notify_fail(victim->name()+ "�ղ�����ɱ��һ�Σ������˴������˰ɡ�\n");
		
// Add By River@SJ 2003.6.24
	if ( pktime_limit(me, victim))
		return 0;
	if(meisdummy(me,victim))
	{
		return notify_fail("�����ף�һ������ȥ��\n");
	}
	
	if (userp(me) && userp(victim))
	{
		victim->set_temp("other_kill/"+me->query("id"), 1);
		
		log_file("ANSUAN", 
                        sprintf("%-18s throw  %-18s",
                                me->name(1)+"("+capitalize(getuid(me))+")",
                                victim->name(1)+"("+capitalize(getuid(victim))+")"
                        ),
                        this_object(),
                );
	}

	if (ob->is_corpse() && me->query_skill("chousui-zhang", 1) >= 120
	&& me->query_skill("poison", 1) >= 120)
		return fushi_du(me, victim, ob);

	return do_throw(me, ob, victim);
}

int do_throw(object me, object ob, object victim)
{
	string msg;

	if (!stringp(msg = ob->query("throw/msg")))
		msg = "$N��һ���"+ob->name()+"��׼$n���˹�ȥ��\n";
	message_vision("\n"+msg, me, victim);

	me->start_busy(1);

	if (victim->query_skill_mapped("sword")=="dugu-jiujian"
	&& victim->query_temp("weapon")
	&& victim->query_temp("weapon")->query("skill_type")=="sword"
	&& random(victim->query("combat_exp")) > me->query("combat_exp")/4) {
		message_vision(CYN"$Nʹ�����¾Ž��ġ��Ƽ�ʽ�����ӽ�����"+ob->name()+CYN"����"+ob->name()+CYN"�����ȥ��\n"NOR, victim);
		throw_result(victim, me, ob);
		return 1;
	}
	if (victim->query_skill_mapped("parry")=="douzhuan-xingyi"
	&& victim->query_skill("douzhuan-xingyi", 1) > 100
	&& random(victim->query("combat_exp")) > me->query("combat_exp")/3) {
		message_vision(CYN"$Nʹ�����ƶ�ת����"+ob->name()+CYN"Ī�����������;ת�˷���ֱ��$n�Լ�Ϯ����\n"NOR, victim, me);
		throw_result(victim, me, ob);
		return 1;
	}
	throw_result(me, victim, ob);
	return 1;
}

void embedded(object victim, object me, object ob)
{
	if (ob->query("id")!="leihuo dan"){
		ob->set("embedded", 1);
		ob->set("victim", victim->query("id"));
		ob->move(victim);
		victim->set_temp("embed", ob->query("id"));
	}
	ob->do_embed(victim);
	if(stringp(ob->query("poison")))
		victim->apply_condition(ob->query("poison"), ob->query("damage")*2);
	victim->receive_wound("qi", me->query_str() * ob->query("damage"), me);
	if(!userp(victim) && random(10) < 5 && !victim->is_killing(me->query("id")))
		victim->kill_ob(me);
	if( me && userp(victim) && !victim->is_killing(me->query("id")))
		me->set_temp("kill_other/"+ victim->query("id"), 1);
	if (victim)
		victim->fight_ob(me);
}

object sel_ob(object ob)
{
	object obj;
	if (ob->query_amount() > 1){
		ob->add_amount(-1);
		obj = new(base_name(ob));
		obj->set_amount(1);
	}
	else obj = ob;
	return obj;
}

private int throw_result(object me, object victim, object ob)
{
	string *limbs, limb, str, dodge_skill;
	int ap, dp , damage, wound;

	ap = me->query_str() + me->query_int() + me->query_skill("throwing", 1)/10;
	dp = victim->query_dex() + victim->query_int();
	ap *= (me->query("combat_exp")/1000);
	dp *= (victim->query("combat_exp")/1000);
	ap -= ob->query_weight();

	if (ap < 1 ) ap = 1;
	if (dp < 1 ) dp = 1;

	victim->add_temp("offenders/"+me->query("id"), 1);

	if (random(ap+dp) > dp) {
		limbs = victim->query("limbs");
		limb = limbs[random(sizeof(limbs))];
		
		damage = (ob->query_weight()/5000+me->query_str()) * 15/10 * ob->query("throw/damage");
		wound = damage/3 + random(damage/2);
		victim->receive_damage("qi", damage, me);
		victim->receive_wound("qi", wound , me);
		if(wizardp(me) && me->query("env/test"))
			tell_object(me,sprintf("damage: %d , wound: %d\n",damage,wound));
		
		if(ob->query("embed")){
			if (!stringp(str = ob->query("throw/embed_msg")))
				str = CYN"���ֻ��$Nһ���ҽУ�"+ob->name()+CYN+"��Ȼ����$P��"+limb+"�ϡ�\n"NOR;
			message_vision(str, victim);
			embedded(victim, me, sel_ob(ob));
		} else {
			if (!stringp(str = ob->query("throw/hit_msg")))
				str = CYN"$N⧲�������"+ob->name()+CYN+"������$N��"+limb+"�ϡ�\n"NOR;
			message_vision(str, victim);
			sel_ob(ob)->move(environment(victim));

			if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 2
			&& !victim->is_killing(me->query("id"))){
				victim->kill_ob(me);
				me->kill_ob(victim);
			} else if (!victim->query_temp("no_respond")) {
				me->set_temp("kill_other/"+ victim->query("id"), 1);
				victim->fight_ob(me);
				call_out("do_respond", 1, victim, me);
			}
		}

		if (victim) {
			str = COMBAT_D->eff_status_msg(
				victim->query("eff_qi")*100/(victim->query("max_qi")+victim->query_temp("apply/qi"))
			);
			message_vision("($N"+str+")\n", victim);
		} else
			tell_object(me, BLINK "�������ڿ͵���������ʦ�������������Ϊ�����򽫵��������Ĵ�����\n" NOR);
	} else if (random(ap) < random(ap+dp) && ob->query_weight() < 7000 && victim->query("race") == "����"
	&& !ob->query("unique") && userp(me)) {
		if( !stringp(str = ob->query("throw/catch_msg")) )
			str = CYN"����$N�����ֿ죬����һ�࣬��"+ob->name()+CYN+"����ؽ������\n\n"NOR;
		message_vision(str, victim);
		sel_ob(ob)->move(victim);

		if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 2
		&& !victim->is_killing(me->query("id"))){
			victim->kill_ob(me);
			me->kill_ob(victim);
		} else if (!victim->query_temp("no_respond"))
			call_out("e_mote", 1, victim, me);
	} else {
		if (!stringp(str = ob->query("throw/dodge_msg")) ){
			dodge_skill = victim->query_skill_mapped("dodge");
			if (!dodge_skill) dodge_skill = "dodge";
			str = SKILL_D(dodge_skill)->query_dodge_msg(victim, 1);
			limbs = victim->query("limbs");
			limb = limbs[random(sizeof(limbs))];
			str = replace_string( str, "$l", limb);
		}
		message_vision(str, me, victim);
		sel_ob(ob)->move(environment(me));

		if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 2
		&& !victim->is_killing(me->query("id"))){
			me->kill_ob(victim);
			victim->kill_ob(me);
		}
		else if( !victim->query_temp("no_respond") )
			call_out("do_respond", 1, victim, me);
	}
	if (userp(me)) me->add_busy(random(2));
	return 1;
}

int fushi_du(object me, object victim, object ob)
{
	int ap, dp, damage;
	string dodge_skill, str, *limbs, limb, result, type = "����";

	message_vision(HIB"$N���ð�ź���������ץ��"+ob->name()+"��$n��ȥ��\n"NOR, me, victim);

	ap = me->query_skill("strike");
	dp = victim->query_skill("dodge");
	ap *= me->query("combat_exp")/1000;
	dp *= victim->query("combat_exp")/1000;

	if (random(ap) > dp){
		limbs = victim->query("limbs");
		limb = limbs[random(sizeof(limbs))];
		damage = ob->query("victim_exp")/1500;
		if (damage > 2500 ) damage = 2500+random(damage-2500)/10;
		str = COMBAT_D->damage_msg(damage, type);
		str = replace_string( str, "$l", limb);

		victim->receive_damage("qi", damage, me);
		result = COMBAT_D->status_msg(
			victim->query("qi")*100/(victim->query("max_qi")+victim->query_temp("apply/qi"))
		);
		message_vision(str, me, victim);
		message_vision("($N"+result+")\n", victim);

		if ( ! victim->query("job_npc"))
			victim->add_condition("xx_poison", me->query_skill("poison", 1)/5);

		if (userp(me)
		&& userp(victim)
		&& !victim->query_temp("kill_other/"+me->query("id"))
		&& !me->query_temp("other_kill/"+victim->query("id"))
		&& ! me->query_temp("revenge/"+victim->query("id")))
			me->add_condition("killer", 15);

		victim->add_busy(1+random(3));
		victim->fight_ob(me);
	}
	else {
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		str = SKILL_D(dodge_skill)->query_dodge_msg(victim, 1);
		message_vision(str, me, victim);
		victim->fight_ob(me);
	}
	ob->move(environment(me));
	me->start_busy(1);
	return 1;
}

void e_mote(object victim, object me)
{
	if (!me || !victim || environment(me) != environment(victim))
		return;
	EMOTE_D->do_emote(victim, emote[random(sizeof(emote))], me->query("id"));
}

void do_respond(object victim, object me)
{
	string att;

	if (!me || !victim || environment(me) != environment(victim))
		return;

	att = victim->query("attitude");

	me->set_temp("kill_other/"+ victim->query("id"), 1);

	if (victim->query("shen") < 0)
		return victim->fight_ob(me);

	if (att == "friendly" && victim->query("race") == "����")
		return e_mote(victim, me);

	if (att == "heroism" || att == "aggressive")
		return victim->fight_ob(me);

	if (att == "peaceful" && random(5)== 1)
		return victim->fight_ob(me);

	else if(victim->query("race") == "����")
	EMOTE_D->do_emote(victim, "brag", me->query("id"));

	return victim->fight_ob(me);
}

int can_kill_ob(object me, object ob)
{
	int i;
	if( !userp(me) ) return 1;
	if (ob->query_condition("killer") > 10) return 1;
	i = ob->query("last_death_time/"+ me->query("id"));
	if( i + 86400 > time() ) return 0;
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : throw <��Ʒ> at <����>

���ָ�������ĳ��ʹ�ð�����

�������ָ��: fight, kill, ansuan, hit


HELP
	);
    return 1;
}
