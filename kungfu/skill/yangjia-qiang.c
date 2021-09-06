
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N����һ��$w��һ�С�"+HIY"ʨ��ҡͷ"NOR+"����ǹ�Ϻ�ӧ�������������һ��ǹ������$n$lֱ����ȥ",
	"lvl" : 0,
	"skill_name" : "ʨ��ҡͷ",
	"damage_type":  "����"
]),
([      "action":"$N��ת$w��һ�С�"+HIY"�׺羭��"NOR+"����б���Ʋǹ�ǹ���𴦣�ԲԲһ�ź�Ӱ��ǹ����һ�㺮�⼲��$n����",
	"lvl" : 30,
	"skill_name" : "�׺羭��",
	"damage_type":  "����"
]),
([      "action":"$N�߶���������ɣ�����$wһ����ʹ��һ�С�"+HIY"����һ����"NOR+"����$wͦ�ñ�ֱ��Ѹ�����׵ش���$n��$l",
	"lvl" : 60,
	"skill_name" : "����һ����",
	"damage_type":  "����"
]),
([      "action":"$Nͦ��$w��һ�С�"+HIY"���ͷ"NOR+"������ӧ������$w�ó����ǹӰ��ǹ����˸��������$n$l�㵽",
	"lvl" : 90,
	"skill_name" : "���ͷ",
	"damage_type":  "����"
]),
([      "action":"$Nһ�С�"+HIY"������ŭ"NOR+"����ˢˢˢ������ǹ�����̶�������ӧ�Ұڣ�$w�������죬����һ�����Ȧ�ӣ���ס��$n���¸�·",
	"lvl" : 120,
	"skill_name" : "������ŭ",
	"damage_type":  "����"
]),
([      "action":"$NͻȻ���һ����˫��ץסǹ������������$w��ɹ��Σ�ͻȻһ���֣����һ�����մ���$n����һ�С�"+HIY"���ߵ���"NOR+"��",
	"lvl" : 150,
	"skill_name" : "���ߵ���",
	"damage_type":  "����"
]),
([      "action":"$NͻȻ̤��һ�ǹ�$wͦ�ñ�ֱ��ʹ��һ�С�"+HIY"�����Ⱥ"NOR+"����$w������磬������ƥ����$n��$l��ȥ",
	"lvl" : 180,
	"skill_name" : "�����Ⱥ",
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { if (this_player()->query("quest/���Ӣ�۴�/yangjiaqiang/pass"))  return usage == "spear" || usage == "parry"; }

int valid_learn(object me)
{
	if( me->query_skill("yangjia-qiang", 1) < 1 )
		return notify_fail("���ǹֻ�ܴ������Ĵ�ϰ����\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{ 
	int i, j, level,lv2;
	level = me->query_skill("yangjia-qiang",1);
	lv2 = me->query_skill("spear", 1)/2;

	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/5);

			if( me->query_temp("yjq/huima")){
				return ([  
					"action":HIC+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC), NOR, HIC)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + lv2/10,
					"dodge": random(20)- 5 +lv2/15,
					"damage": 160 + random(80) + random((level+lv2)/4),
					"parry": random(15)+lv2/10,
					"weapon" : random(2)?"ǹ��":"ǹ��",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			if( me->query_temp("yjq/jifeng")){
				return ([  
					"action":MAG+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"MAG), NOR, MAG)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + lv2/10,
					"dodge": random(20)- 5 +lv2/15,
					"damage": 170 + random(100) + random((level+lv2)/4),
					"parry": random(15)+lv2/10,
					"weapon" : random(2)?"ǹ��":"ǹ��",
					"damage_type" : random(2)?"����":"����",
				]);
			}
						if( me->query_temp("yjq/qinghe")){
				return ([  
					"action":HIG+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIG), NOR, HIG)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + lv2/10,
					"dodge": random(20)- 5 +lv2/15,
					"damage": 180 + random(100) + random((level+lv2)/5),
					"parry": random(15)+lv2/10,
					"weapon" : random(2)?"ǹ��":"ǹ��",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			if( me->query_temp("yjq/shenwei")){
				return ([  
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + lv2/10,
					"dodge": random(20)- 5 +lv2/15,
					"damage": 180 + random(100) + random((level+lv2)/5),
					"parry": random(15)+lv2/10,
					"weapon" : random(2)?"ǹ��":"ǹ��",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			return ([
				"action": action[j]["action"],
				"force" : 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 80 +random(80),
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
			]);
		}
	}
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("����������������ǹ��\n");
        me->receive_damage("jingli", 20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yangjia-qiang/" + action;
}


mixed hit_ob(object me, object target)
{
   int lv = me->query_skill("yangjia-qiang");

   if( random(5) > 2 && lv > 250 && !me->query_temp("yjq/hmq") )
          {
                message_vision(YEL"$N���һ����˫��ץסǹ������Ȼ��š���ݱۣ������ǹ��ֱ��$n���ţ���һǹ�������ǹ���ġ�����ǹ��" NOR,me,target);
                         me->add_temp("apply/attack",  me->query_skill("yangjia-qiang", 1)/3);
me->set_temp("yjq/hmq",1);
                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                         me->add_temp("apply/attack", -me->query_skill("yangjia-qiang", 1)/3);
me->delte_temp("yjq/hmq");
         }
     
}

