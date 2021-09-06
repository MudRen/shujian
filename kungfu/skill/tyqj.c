// tianyu-qijian.c �����潣
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([  "action":"$Nʹһʽ��"+BLK+"����һ��"+NOR+"��������$w����΢�񣬻ó�һ���������$n��$l",
    "lvl" : 0,
    "skill_name" : BLK "����һ��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����ǰ��ʹ����"+RED+"���羪��"+NOR+"��������$w����һ����������$n��$l",
    "lvl" : 10,
    "skill_name" : RED "���羪��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wһ����һ�С�"+GRN+"���ھ���"+NOR+"����ббһ�������ó�������$n��$l",
    "lvl" : 15,
    "skill_name" : GRN "���ھ���" NOR,
    "damage_type":  "����"
]),
([  "action":"$N���н����ॳ���һ����һʽ��"+BLU+"�������"+NOR+"����һ���������$n��$l",
    "lvl" : 20,
    "skill_name" : BLU "�������" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+MAG+"ŭ����"+NOR+"��������$w�������������ʹ$n�Ѷ���ʵ���޿ɶ��",
    "lvl" : 35,
    "skill_name" : MAG "ŭ����" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wбָ���죬��â���£�һʽ��"+BLU+"�Ż�����"+NOR+"������׼$n��$lбб����",
    "lvl" : 45,
    "skill_name" : BLU "�Ż�����" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+WHT+"�����ѩ"+NOR+"�������󼱶�������������⣬����$n��$l",
    "lvl" : 50,
    "skill_name" : WHT "�����ѩ" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+HIR+"��ӵ�к"+NOR+"����$w��ն�������缲�������$n���ؿ�",
    "lvl" : 60,
    "skill_name" : HIR "��ӵ�к" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+HIY+"�������"+NOR+"����$wͻȻ���������һƬ���Χ��$nȫ��",
    "lvl" : 65,
    "skill_name" : HIY "�������" NOR,
    "damage_type":  "����"
])
});
mapping *action_shandian = ({
([	"action":HIY"$Nǰ�н��䣬����������ǰ����������һʽ������˷������಻��"NOR,
	"lvl" : 15,
	"damage_type":	"����"
]),
([	"action":HIC"�Է�����㵼䣬ȴ��$N�Ľ�����������ǰ�����������������䣬���ͱ���"NOR,
	"lvl" : 30,
	"damage_type":	"����"
]),
([	"action":HIR"ֻ��$N��Ӱһ����������Ȼ�۽��Է������н�����˸����������"NOR,
	"lvl" : 45,
	"damage_type":	"����"
]),
([	"action":HIY"ȴ��$Nһ��δ����������������ǰ��֮��ȴͬʱ����ٶ�֮���������ͬʱ����"NOR,
	"lvl" : 60,
	"damage_type":	"����"
]),
([	"action":HIG"����$N�ֱ۶�����ֻ��һ������֮������ڶ������ƿն�����������ǰ"NOR,
	"lvl" : 75,
	"damage_type":	"����"
]),
([	"action":HIB"�����ţ�$N����һ���������������ǰ�󣬵����漸��ͬʱ����ٶ�֮�������Ա�"NOR,
	"lvl" : 90,
	"damage_type":	"����"
]),
([	"action":HIR"һգ�ۼ�$N��������������ǰ���������ޣ���ڶ������ڵ���ʯ�������ǰ"NOR,
	"lvl" : 105,
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ( ! me->query_skill("bahuang-gong", 1))
	if (me->query_skill("beiming-shengong", 1) < 20)
		return notify_fail("��İ˻�����Ψ�Ҷ�����̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,j;
	level   = (int) me->query_skill("tianyu-qijian",1);
	if( me->query_temp("tyqj/shandian")) {
		for(i = sizeof(action_shandian); i > 0; i--) { 
			if(level >= action_shandian[i-1]["lvl"]) {
				j = NewRandom(i, 20, level/5);
				return ([
					"action": action_shandian[j]["action"],
					"lvl": action_shandian[j]["lvl"],
					"damage_type": action_shandian[j]["damage_type"],
					"force": 150 + random(200),
					"dodge": random(30),
					"parry": random(30),
					"damage": 160+ random(200),
				]);
			}
		}
	}
		if( me->query_temp("tyqj/kuangwu")) {
	
				return ([
					"action": action_shandian[j]["action"],
					"lvl": action_shandian[j]["lvl"],
					"damage_type": action_shandian[j]["damage_type"],
					"force": 100 + random(200),
					"dodge": random(30),
					"parry": random(30),
					"damage": 100+ random(140),
				]);
			}
		if( me->query_temp("tyqj/piaomiao")) {
	
				return ([
					"action": action[j]["action"],
					"lvl": action[j]["lvl"],
					"damage_type": action[j]["damage_type"],
					"force": 100 + random(200),
					"dodge": random(30),
					"parry": random(30),
					"damage": 80+ random(100),
				]);
			}
return ([
				"action" : action[j]["action"],
				"force" : 100 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 100 + random(100),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
}

int practice_skill(object me)
{
	int lvl = me->query_skill("tianyu-qijian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("������������������潣��\n");
	if((int)me->query("neili") < 20)
		return notify_fail("������������������潣��\n");
		me->receive_damage("jingli", 40);
		me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}

