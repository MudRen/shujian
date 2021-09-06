//lingshe_zhangfa.c �����ȷ�
//updated by redhat@sjmud 2009/5/9

#include "ansi.h"

inherit SKILL;
mapping *action = ({
([  "action": HIB"$Nʹ��һ�С����߳�����������$w"HIB"�󿪴���ɨ��$n��$l"NOR,
    "lvl" : 0,
    "skill_name" : RED "���߳���" NOR,
    "damage_type": "����"
]),
([  "action": HIY"$N����$w"HIY"������죬һ�С�ҡͷ��β����$n��$l��ȥ"NOR,
    "lvl" : 20,
    "skill_name" : MAG "ҡͷ��β" NOR,
    "damage_type": "����"
]),
([  "action": HIG"$N����$w"HIG"���Ӹ�����ʹһ�С������½�������$n��$l"NOR,
    "lvl" : 30,
    "skill_name" : HIW "�����½�" NOR,
    "damage_type": "����"
]),
([  "action": HIM"$Nһ�С�����ͦ��������$w"HIM"����ɨ��$n��$l"NOR,
    "lvl" : 40,
    "skill_name" : YEL "����ͦ��" NOR,
    "damage_type": "����"
]),
([  "action": HIR"$Nʹ��һ�С��������ߡ���$w"HIR"�����ػ���$n��$lɨȥ"NOR,
    "lvl" : 50,
    "skill_name" : YEL "��������" NOR,
    "damage_type": "����"
]),
([  "action": HIY"$N����$w"HIY"һ�ӣ�ʹ��һ�С��߲����ҡ����������ɨ��$n��$l"NOR,
    "lvl" : 60,
    "skill_name" : BLU "�߲�����" NOR,
    "damage_type": "����"
]),
([  "action": HIM"$Nʹ��һ�С�������ɽ�����߾�����$w"HIM"����ͷ����$n��$l"NOR,
    "lvl" : 80,
    "skill_name" : RED "������ɽ" NOR,
    "damage_type": "����"
]),
([  "action": HIB"$Nʹ��һ�С����߳�����������$w"HIB"��һ̽��ֱɨ$n��$l"NOR,
    "lvl" : 100,
    "skill_name" : RED "���߳���" NOR,
    "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="staff" || usage=="parry"; }

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, j, level;

	level = (int) me->query_skill("lingshe-zhangfa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 200 + random(150),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}

		   if( me->query_temp("lszf/saoluoye") > 1 )
			me->add_temp("lszf/luoye", -1);
		return ([
			"action" : action[j]["action"],
			"damage": 220 + random(100),
			"damage_type": "����",
			"dodge": random(30)-20,
			"parry": random(30),
			"force": 350 + random(250),
		]);
		if( me->query_temp("lszf/wanshe"))
		return ([
			"action" : action[j]["action"],
			"damage": 350 + random(250),
			"damage_type": "����",
			"dodge": random(30)-20,
			"parry": random(30),
			"force": 450 + random(250),
		]);
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("������������ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("������������ˡ�\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20);
	return 1;
}

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("����������㣬û�а취�������ȷ�, ����Щ���������ɡ�\n");

	if (!me->query_skill("hamagong", 1) || me->query_skill("hamagong", 1) < 50)
		return notify_fail("��ĸ�󡹦���̫ǳ��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "staff" )
		return notify_fail("�����ʹ���������ȷ���\n");
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon; 
        int i;
        weapon = me->query_temp("weapon");
        i = me->query_skill("lingshe-zhangfa", 1);

        if( !userp(me) && random(2) ) return 0;

        if( !weapon || weapon->query("skill_type") != "staff" ) return 0;
        if( i < 350 ) return 0;
        if( me->query_temp("lszf/wanshe")) return 0;
        if( !me->query_temp("hmg_nizhuan")) return 0;
        if( !living(victim) ) return 0;

        if( i >= 350 && random(3)
         && random(me->query_con()) > victim->query_con()/3
         && random(me->query_skill("staff")) > victim->query_skill("parry")/3 
         && !me->query_temp("lingshe")) {
                if( me->query_skill_prepared("cuff") == "lingshe-zhangfa"
                 && me->query_skill_mapped("cuff") == "lingshe-zhangfa"
                 && me->query_skill("lingshe-quanfa", 1) >= 200 && random(3) ) {
                 	message_vision(HIB"ֻ��$N����"+weapon->name()+HIB"����ͷ��ø��ǹ���ɲ���ֻ������������Ȼ�������죬ͻȻ�������ж�Һ����$n�����ȥ��\n"NOR, me);
                        
                        me->add_temp("apply/attack",  me->query_skill("lingshe-quanfa", 1)/2);
                        me->set_temp("lingshe");
                        COMBAT_D->do_attack(me, victim, 0, 3);
                        victim->add_condition("snake_poison", 10);
                        me->delete_temp("lingshe");
                        me->add_temp("apply/attack", -me->query_skill("lingshe-quanfa", 1)/2);
                } else {
                  message_vision(HIM"$Nȫ������ת��ƾ����ѧԨ��ڹ���񣬾�������С�ɣ�����"+weapon->name()+HIM"�Ӷ���������У���ʽ��Ϊ������"NOR, me);     
                        me->set_temp("lingshe", 1);
                        me->add_temp("apply/attack",  me->query_skill("lingshe-zhangfa", 1));
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),  3);
                        me->add_temp("apply/attack", -me->query_skill("lingshe-zhangfa", 1));
                        me->delete_temp("lingshe");
                }
        }
        else if( i >= 400 && random(2)
         && random(me->query("combat_exp")) > victim->query("combat_exp")/3
         && random(me->query_skill("staff")) > victim->query_skill("parry")/3
         && random(me->query_con()) > victim->query_str()/3
         && !victim->query_temp("lost_attack")
         && !me->query_temp("wugou") ) {
                message_vision(HIY"$N������"+weapon->name()+HIY"ֱͦ�����۹�����"+weapon->name()+HIY"�ϣ��������Ʈ�ڣ����ȼ�������籩��Ҳ���ƶ���\n"+
					                     HIY"����ֱָ$n�Ŀڣ����Ǵ򹷰�����ʮ��·������"HIG"�����޹�"NOR"��"HIY"�ĵ�����İ������ڣ�\n"NOR, me, victim);
					                     me->set_temp("wugou");
                victim->add_temp("lost_attack", 1+random(3));
                return random(me->query_skill("staff"))/3;
                me->delete_temp("wugou");
        }
        return 0;
}

string perform_action_file(string action)
{
	return __DIR__"lingshe-zhangfa/" + action;
}
