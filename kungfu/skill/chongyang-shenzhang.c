// chongyang-zhang.c -��������
// Modified by action@SJ 2008/09/15

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "skill_name": "��������",
        "action": "$N˫��һ��һ�С������������ó������Ӱ����$n��$l",   
        "lvl"   : 0,
        "damage_type":  "����"
]),
([      "skill_name": "�ؾ��쳤",
        "action": "$N����һ����������Ȼ�Ƴ���һ�С��ؾ��쳤��ǿ�����Ʒ�ֱ��$n��$l",
        "lvl"   : 15,
        "damage_type":  "����"
]),
([      "skill_name": "����Ϸˮ",
        "action": "$N˫�Ʒ׷ɣ�һ�С�����Ϸˮ��ֱȡ$n��$l",
        "lvl"   : 30,
        "damage_type": "����"
]),
([      "skill_name": "���︴��",
        "action": "$N��������λ���ߣ�һ�С����︴�ա��������Ʒ��޿ײ����ػ���$n��$l",
        "lvl"   : 50,
        "damage_type": "����"
]),
([      "skill_name": "�عⷴ��",
        "action": "$N�������˫��ƽ�ƣ����������һ�С��عⷴ�ա�����$n��$l",
        "lvl"   : 70,
        "damage_type": "����"
]),
([      "skill_name": "���է��",
        "action": "$N����������ǰ�������Ƴ���һ�С����է�֡�ѸȻ����$n$l",
        "lvl"   : 90,
        "damage_type": "����"
]),
([      "skill_name": "����ǧ��",
        "action": "$Nʹ��������ǧ���������μ�����������$n���ƹ���",
        "lvl"   : 110,
        "damage_type": "����"
]),
([      "skill_name": "���ξ���",
        "action": "$Nһ�С����ξ��졹��˫������ʵʵ�Ļ���$n��$l",
        "lvl"   : 130,
        "damage_type": "����"
]),
([      "skill_name": "������λ",
        "action": "$N���ƻ��˸�ȦȦ�������Ƴ���һ�С�������λ������$n$l",
        "lvl"   : 150,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 

	if ( me->query_int(1) > 50)
		return combo=="zhongnan-zhi"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 60)
		return notify_fail("������칦��򲻹����޷�ѧ�������ơ�\n");
	if ((int)me->query_int(1) > 30) {
		return 1;
	}
	else {
		if ( me->query_skill("zhongnan-zhi", 1))
			return notify_fail("��Ĺ����������޷�ͬʱѧϰ�������ϵ��ϳ˹���\n");
	}
	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷����������ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, j, level;
	string msg;
	
	level = (int) me->query_skill("chongyang-shenzhang",1);	
	for(i = sizeof(action); i > 0; i--) 	{
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if(me->query_temp("qixing")) {
				switch(me->query_temp("qixing")) {
					case 2: msg = HIY"$N����������ɽ������һ������ָ��ʹ�������������һ��ָ��������������磬�Ʋ��ɵ���"NOR; break;
					case 1: msg = HIB"$N�ۼ��Է���������Χ����Ҳ����ȫ����ˣ�������ָ����ػ���"NOR; break;
					default: msg = HIW"$N��ָ������Ʒ磬ָ�缴������$n��$n������ʾ��������"NOR;break;
				}
				me->add_temp("qixing", -1);      
				return ([
					"action": msg, 
					"force" : 200 + random(300),
					"dodge": random(35),
					"parry": random(35),
					"damage": 40 + random(50),
					"damage_type" : "ץ��",
				]);
			}
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("chongyang-shenzhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������������ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"chongyang-shenzhang/" + action;
}
