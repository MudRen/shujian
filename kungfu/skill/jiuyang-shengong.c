// jiuyang-shengong.c ������

#include <ansi.h>


inherit FORCE;
#include <combat_msg.h>


int valid_enable(string usage)
{
	if (this_player()->query("jiuyang/read"))
		return usage == "force";
}

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
	if( !me->query("jiuyang/read"))
		return notify_fail("������ֻ��ͨ����ȫ���Ĳ�ġ������澭������ߡ�\n");

	if( me->query_skill("jiuyang-shengong", 1) < 220)
		return notify_fail("������ֻ��ͨ����ȫ���Ĳ�ġ������澭������߾����񹦡�\n");

	if ((int)me->query_skill("jiuyang-shengong", 1) > me->query_skill("force", 1) + 10
	 && me->query_skill("jiuyang-shengong", 1) >= 220 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	return 1;
}

int practice_skill(object me)
{
	if((int)me->query_skill("jiuyang-shengong", 1) >= 220 ){
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
			me->improve_skill("jiuyang-shengong", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("�����ڵ���Ϊ��������߾����񹦡�\n");       
	}
	return notify_fail("������ֻ��ͨ����ȫ���Ĳ�ġ������澭������ߡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}

void skill_improved(object me)
{
	int i =2 +random(4);
	if( me->query_skill("jiuyang-shengong", 1) > 200
	 && me->query("jiuyang/gift") + 201 < me->query_skill("jiuyang-shengong", 1)){
		if( !me->query("jiuyang/gift"))
			me->set("jiuyang/gift", me->query_skill("jiuyang-shengong", 1) -200);
		else 
			me->add("jiuyang/gift", 1);
		me->add("max_neili", i); 
		tell_object(me,HIW"\n���ž����񹦵���ߣ���о��Լ�����������"+chinese_number(i)+"�㡣\n"NOR);
	}
}

mapping exercise_msg(object me)
{
	return ([
 		"status_msg" : HIR + me->name()+"���������������������֮����" NOR,
 		"start_my_msg" : "����ϥ��������ʹ�����������³������������뼹�ǣ�ע�����䣬������������֮���硣\n",
 		"start_other_msg" : me->name()+"��ϥ��������ʹ�����������³������������뼹�ǣ�ע�����䣬������������֮���硣\n",
 		"halt_msg" : "$N����΢΢����������������վ��������\n",
 		"end_my_msg" : "������������һ��Ԫ����������˫�ۣ�ֻ����ȫ����������������������Ȼ����֮����\n",
 		"end_other_msg" : "ֻ��"+me->name()+"�����������һ��Ԫ����������˫�ۣ�ֻ����ȫ����������������������Ȼ����֮����\n",
		"heal_msg" : HIR"$N��ϥ���£����վ�����ʾ�ķ��ŵ�Ϣ��ֻ��������ů���ء������õأ�����������\n"NOR,
		"heal_finish_msg" : HIR"�����񹦵���������ʱ�������ֳ�������$N������������ת���ظ�֮��������ů�泩��\n"NOR,
		"heal_unfinish_msg" : HIR"$N��̬ׯ�ϣ�����վ��������������Ѫ�죬�������ƻ�û����ȫ�ָ���\n"NOR,
		"heal_halt_msg" : HIR"$N�����ͺ죬ͷ�����������������͵���һ����������������������\n"NOR,
	]);
}


string *fanzhen_msg = ({
"ֻ���$n���ڸ��У���������һ�뷭ת��\n",
"���ȷ��𣬽�$n��������ֽ��ȫ��Ѫɫ��\n",
"���$n�ķ����ѣ�����������������\n",
"�����Ѳ���ȫ����$n�����������ȥ��\n",
"���$n������ת�������������߰˲���\n",
"��$nһײ��ֻ���$p�ؿ���Ѫ��ӿ��\n",
"$n����ײ��һ���޻����棬����Ϊ��ĺ�ǽ��һ�㣬����������\n",
"$n������$P��ͻȻ����һ�𣬵�ʱ���˳�ȥ��\n",
});

int ob_hit(object ob, object me, int damage)
{
	string msg;
	int p, skill, neili, neili1, i = 1, ap, dp;
	object weapon;
	skill = me->query_skill("jiuyang-shengong", 1);
	neili = me->query("neili") + 1 ;
	neili1 = ob->query("neili") + 1;

	if( skill > 300 ) 
             {
		i += me->query_temp("combat_yield");
	      }

	

     if( living(me)
	&& random(skill) * i + 100 > ob->query_skill("parry", 1)/2
//	&& me->query("combat_exp") > ob->query("combat_exp")/2
	&& skill > 199
	&& neili > 500
	&& !me->query("menggu")
	&& living(ob)
	&& !ob->is_visible(me)
        && random(10) > 6 
         ) 
	{
	
		if(!objectp(weapon = ob->query_temp("weapon"))){
			me->add("neili", -(10+random(70)));
			msg = random(2)?HIC"$NĬ���ǿ����ǿ�������󽭡������������Ķ���":HIC"$NĬ����������ᣬ������ɽ�ڡ������������Ķ���";
			if(neili1 > neili*4*i || random(damage) > (5000 + me->query_con(1) * 40 * i)){
				msg += "��ȴ��$n�ľ���һ�����飡\n"NOR;
				me->delete_temp("fanzhen");
				damage = random(damage/2);
			}
			else if(neili1 > neili*3*i) {
				msg += "��ȴ�����޷��赲$n�ľ�����\n"NOR;
				damage = 0;
			}

			else if(neili1 > neili*3/2*i){
				msg += "��������˲���$n�ľ�����\n"NOR;
				damage = -damage/2;
			}
			else{
				msg += fanzhen_msg[random(sizeof(fanzhen_msg))]+NOR;
				p = (neili / neili1) * i;
				if( p < 1) p = 1;
				p *= damage/3;
				if(ob->query_skill("force") > me->query_skill("force")*3/2) p = p*2/3;

				if ( me->is_busy())
					p /= 2;

				if(p < 10) p = 10;

				ob->receive_damage("qi", p, me);
				ob->receive_wound("qi", p/5*i, me);

				if(wizardp(me)) tell_object(me, "Fanzhen damage: "+p+"��\n");

				p = (int)ob->query("qi") * 100 / (int)ob->query("max_qi");
				msg += "( $n"+eff_status_msg(p)+" )\n";
				damage = -8000+(-damage);
			}
			message_vision(msg, me, ob);
		}
		else{
			msg = HIR"����������������һ�����ε�ǽ��$N��ǰ�赲�ţ�";
			switch(weapon->query("skill_type")) {
				case "whip"   : p = 10; break;
				case "sword"  : p = 8; break;
				case "hook"   : p = 6; break;
				case "blade"  : p = 5; break;
				case "club"   :
				case "stick"  : p = 2; break;
				case "staff"  :
				case "axe"    :
				case "hammer" : p = 1; break;
				default       : p = 3; break;
			}
			p *= weapon->query("rigidity");

			ap = me->query("combat_exp", 1) / 100 * (me->query("str") + p);
			dp = ob->query("combat_exp", 1) / 100 * (ob->query("str") + p);

			if( random(ap + dp ) > dp && neili*i > neili1*2/3) {
				message_vision(HIR"���$N���Ͼ������漴����$nֻ������һ�ȣ�" + weapon->name() + HIR"������ַɳ���\n\n"NOR, me, ob);
				ob->add_busy(1+random(2));
				return -8000+(-damage);
			}
			else if(neili*i > neili1*2){
				msg += "���$n"HIR"�����������������"+ob->name()+HIR"�ֱ۷��飡\n"NOR;
				ob->start_busy(1+random(3));
				damage = -8000+(-damage);
			}
			else if(neili*i > neili1*3/2){
				msg += "���$n"HIR"����ǰ��һ˿һ����\n"NOR;
				damage = -8000+(-damage);
			}
			else if(neili*i > neili1){
				msg += "���������$n"HIR"ǰ�����ٶȣ�\n"NOR;
				damage = -damage*3/2;
			}
			else if(neili*2*i > neili1){
				msg += "����û����ʲô���ã�\n"NOR;
				damage = -damage/4;
			}
			else{
				msg += "��ȴ��$n"HIR"һ�´��ƣ�\n"NOR;
				me->delete_temp("fanzhen");
				damage = random(damage/2);
			}
			message_vision(msg, me, weapon);
		}
		return damage;
	}
}
/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl,i;

        lvl = me->query_skill("jiuyang-shengong", 1);

        if (damage_bonus < 150
           || lvl < 150
           || me->query("neili") < 10000
           || me->query_skill_mapped("force") != "jiuyang-shengong")
           
		return 0;

           i = damage_bonus-80;

if(me->query_skill_mapped("parry") =="qiankun-danuoyi")  i= i * 2;

        if (damage_bonus / 5 > victim->query_con() && random(5) > 2)
        {
	        me->add("neili", -50);
                victim->receive_wound("qi", i / 40, me);
                return random(2) ? HIR "ֻ��$N" HIR "�������������ڱŷ���$n֮������Ƥë�����������������漴"
                                   "�ĵ�������$n" HIR "�۵�һ���������һ����Ѫ��\n" NOR:

                                   HIR "$N" HIR "�����񹦵�Ǳ�������˳�������$n��������Ϥ�����˻�����ֻ����$n"
                                   HIR "����һ�����һ����Ѫ��\n" NOR;
        }
}

*/













