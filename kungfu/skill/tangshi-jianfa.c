
#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include <combat_msg.h>

mapping *action = ({
([	"action" : "$N��ǰ����һ����ͬʱ���д�һ����һʽ��"+HIG"���̺�����"NOR+"��ֱ��$n��$l",
	"force" :random(30)+ 60,
	"dodge" : 5,
	"damage" : 20,
        "lvl" : 0,
	"damage_type" : "����"
]),
([      "action" : "$N��ǰ������һ�С�"+HIB"������СС"NOR+"����������ãĪ�⣬$w��ǰ���$n��$l",
        "force" :random(30)+ 80,
        "dodge" : 15,
        "damage" : 25,
        "lvl" : 10,
        "damage_type" : "����",
]),
([      "action" : "$N���ֶ���һ�У��·�������ʲô��һ�С�"+HIW"�����羪��"NOR+"���������е�$w��ǰ����$n��$l",
        "force" :random(30)+ 100,
        "dodge" : 5,
        "damage" : 35,
        "lvl" : 20,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��һʽ��"+HIY"��ɽ������"NOR+"��������$w�Ľ�����һ�Ⲽһ������$n��$l",
        "force" :random(30)+ 120,
        "dodge" : 10,
        "damage" : 40,
        "lvl" : 30,
        "damage_type" : "����",
]),
([      "action" : "$N���к��䣬$w��ǰһ�ᣬ����бб��ʹ��һʽ��"+HIR"�Ǻ᲻�ҹ�"NOR+"����$w����$n",
        "force" :random(30)+ 140,
        "dodge" : -5,
        "damage" : 45,
        "lvl" : 40,
        "damage_type" : "����",
]),
([  	"action" : "$N����бָ��أ����һ����һ�С�"+HIC"�����д��"NOR+"����������$n������$w�漴�̳�",
    	"force" :random(30)+ 160,
    	"dodge" : 15,
    	"damage" : 50,
    	"lvl" : 50,
    	"damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tangshi-jianfa",1);
	if ( me->query_temp("tangshi/erguang")){
			return ([
				"action": random(2)?HIW"$N����������������ֳ�����Ȼ�ݳ����͵��｣�����֣����ַ������ĵ�һ������"NOR:HIY"$N����������������ֳ�����Ȼ�ݳ����͵��｣�����֣����ַ������ĵ�һ������"NOR,
                "damage": 150,
                "dodge" : 100,
                "damage_type": "����"
			]);
                
	}
	if ( me->query_temp("tangshi/qujian")){
			return ([
				"action": HIY"$N����$w"HIY"һ������$n������$n������������$N$w"HIY"ͣ�Ͳ�ǰ����������Ϊ����\n"HIC"ͻȻ$w"HIC"�綾�߱��𣬽�����������$w"HIC"��ǰһ̽������$p��"NOR,
                "damage": 80,
                "dodge" : 100,
                "damage_type": "����"
			]);                
	}
	if ( me->query_temp("tangshi/cijian")){
			return ([
				"action": HIY"$N��Хһ����������Ȼ�ӿ죬$n���ü��У�$NͻȻ�䳤��������߲��һ���������$n��"NOR,
                "damage": 80,
                "dodge" : 100,
                "damage_type": "����"
			]);                
	}
	for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ�����������ʬ������\n");
	me->receive_damage("jingli", 20);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"tangshi-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon, weapon1; 
	weapon = me->query_temp("weapon");
	weapon1= victim->query_temp("weapon");
	if( !objectp(weapon) ) return;
	if(!me->query_temp("tangshi")) return;
    
	if(me->query_temp("tangshi/erguang") && random(2))
	{
		tell_object(victim, HIR"�㲻���󺧣���һ��̫��ͻȻ����һ��֮�䣬"+me->query("name")+"������ǰ��\n"NOR);        
		victim->add_busy(1);
	}
   if(me->query_temp("tangshi/qujian") && weapon1)
   {
	   if(random(2))
		   message_vision(HIC"���ţ�$N����"+weapon->name()+HIC"��ƽ��"+weapon1->name()+HIC"��$N��"+weapon->name()+HIR"��ת����Ȧ�ӡ�\n"NOR, me,victim);
	   else 
		   message_vision(HIY"���ţ�$N"+weapon->name()+HIY"һ�죬��ס"+weapon1->name()+HIY"��"+weapon->name()+HIY"���н�ˮ����$n����ȫ�������෴�ķ���\n"NOR, me,victim);

	   if(random(me->query("str")) > victim->query("str")/3){           
           		me->add("neili", -50);
           		message_vision(HIR"$N��ʽ����ɬ�ͣ�"+weapon1->name()+HIR"����ס�����ַɳ���\n"NOR, victim);
           		weapon1->unequip();
           		weapon1->move(environment(victim));
           	}
      		else 
           		message_vision(HIR"$N��ʽ����ɬ�ͣ�"+weapon1->name()+HIR"�������ס��\n"NOR, victim);
   }
}

