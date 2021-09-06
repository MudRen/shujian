//    /kungfu/skill/xingyi-zhang.c ������
// by leontt /1/5/2000

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$Nʹһ�С����α�Ӱ����˫�ֻ��˸���Ȧ������$n��$l",
	"lvl" : 0,
	"skill_name" : "���α�Ӱ",
	"damage_type" : "����"
]),
([
	"action" : "$N�����鰴������ʹһ�С����ǵ�㡹����$n��$l��ȥ",
	"lvl" : 20,
	"skill_name" : "���ǵ��",
	"damage_type" : "����"
]),
([
	"action" : "$N˫����ȭ����ǰ��󻮻���һ�С������Ƕ�������$n��$l",
	"lvl" : 40,
	"skill_name" : "�����Ƕ�",
	"damage_type" : "����"
]),
([
	"action" : "$N�����黮������һ�ǡ��嶷�ǳ�������$n������",
	"lvl" : 60,
	"skill_name" : "�嶷�ǳ�",
	"damage_type" : "����"
]),
([
	"action" : "$Nʩ�����������ǡ������ֻ���$n��$l�����ֹ���$n���ɲ�",
	"lvl" : 80,
	"skill_name" : "��������",
	"damage_type" : "����"
]),						   
([
	"action" : "$NԾ���ڰ�գ�˫�ƾ�������磬һʽ��׷�Ǹ��¡�Ѹ���ޱȵ�����$n",
	"lvl" : 100,
	"skill_name" : "׷�Ǹ���",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ת�����Ʊ�����֡�\n");
	if ( me->query_skill("shenyuan-gong", 1) < 15)
		return notify_fail("�����Ԫ����򲻹����޷�ѧ��ת�����ơ�\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����ת�����ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	string msg;
	level   = (int) me->query_skill("xingyi-zhang",1);

	if (me->query_temp("mr_riyue")){
		switch(me->query_temp("mr_riyue")){
			case 4: msg = HIR"$N˫��������ǰ�����λ�������㽫��"HIW"����"HIR"������$n��̴��Ѩ"NOR; break;
			case 3: msg = HIG"������$N������ƣ�����һ�������¶�����Ϯ��$n��С��"NOR; break;
			case 2: msg = HIR"ֻ��$N���������������һԾ�����������������$n��ͷ��"NOR; break;
			case 1: msg = HIY"$N�ڿ���һ����ת��Я��"HIR"����֮��"HIY"��, ˫�ư���$n�ĵ���"NOR; break;
		}    
		me->add_temp("mr_riyue", -1);
		return([
			"action": msg,
			"force" : 200 + random(300),
			"dodge" : random(30) + 10,
			"parry" : random(30) + 10,
			"damage": 30 + random(30),
			"damage_type" : me->query_temp("mr_riyue")?"����":"����",
		]);
	}

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("mr_daoying")) {
				return ([
					"action": CYN+action[j]["action"]+NOR,
					"lvl": action[j]["lvl"],
					"damage_type": action[j]["damage_type"],
					"force": 200 + random(300),
					"dodge": random(35),
					"parry": random(35),
					"damage": 40 +random(40),
				]);
			}
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 150 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("xingyi-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xingyi-zhang/" + action;
}
