// canhe-zhi.c �κ�ָ
// by leontt 1/5/2000

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N���缤����˫ָ������ã�һ�С�Ŀ��ʶ�����׺ݵ���$n��$l��ȥ",
	"lvl" : 0,
	"skill_name" : "Ŀ��ʶ��",
	"damage_type" : "����"
]),
([
	"action" : "$N���һ����ʮָ���·ַɣ�һ�С������㾦����˫ֱָȡ$n��$l",
	"lvl" : 20,
	"skill_name" : "�����㾦",
	"damage_type" : "����"
]),
([
	"action" : "$Nʮָ���������ʵ��һ�С���˷���롹��ǰ�����ң�˲Ϣ����$n����������",
	"lvl" : 40,
	"skill_name" : "��˷����",
	"damage_type" : "����",
]),
([
	"action" : "$N�����ڿն���һ�С��ܳ���������������죬��$n��$l�Ͳ���ȥ",
	"lvl" : 60,
	"skill_name" : "�ܳ�����",
	"damage_type" : "����"
]),
([
	"action" : "$N����һ�������������ߵ�$n��ǰ��һ�С����ϲ�����������$n��$l",
	"lvl" : 70,
	"skill_name" : "���ϲ���",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С��˱����᡹������һȭ���������ƻ�ָ��һ��һָ��ջ���$n��$l",
	"lvl" : 80,
	"skill_name" : "�˱�����",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ƻ�ָ��ָ�д��ƣ�˫�����ƣ�һ�С���н��������һ����ɽ������������ֱ��$n$l",
	"lvl" : 90,
	"skill_name" : "��н����",
	"damage_type" : "����"
]),
([
	"action" : "$NͻȻ���м�ת��һ�С����μ�����ʮָ���裬��ʱ֮�佫$n����˷�����ס��",
	"lvl" : 100,
	"skill_name" : "���μ�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���κ�ָ������֡�\n");
	if ( me->query_skill("shenyuan-gong", 1) < 15)
		return notify_fail("�����Ԫ����򲻹����޷�ѧ�κ�ָ��\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����κ�ָ��\n");
	return 1;
}

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("canhe-zhi",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
                   if (me->query_temp("lianhuan") && (int)me->query_skill("canhe-zhi",1) > 349) 
                   return ([
                           "action": HIG+action[j]["action"]+NOR,
                           "lvl": action[j]["lvl"],
                           "damage_type": action[j]["damage_type"],
                           "force": 350 + random(350),
                           "dodge": 20+random(35),
                           "parry": 10+random(20),
                   ]);
                   else
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 200 + random(350),
				"dodge": random(30)-10,
				"parry": random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("canhe-zhi", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 50)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("��������������κ�ָ��\n");
        me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{        
	return __DIR__"canhe-zhi/" + action;
}
