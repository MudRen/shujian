// pangen-fu.c �̸���ḫ

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([
	"action" : "$N�߾�����$w��һʽ��������ɽ����������ǰ�����ϵ��£�����$n��$l",
	"lvl" : 0,
	"skill_name" : "������ɽ",
	"damage_type" : "����"
]),
([
	"action" : "$N����һ��������һ�С���ɽ��ˮ�������䲻��ת��$n���$w���ϵ��¿�����ȥ",
	"lvl" : 30,
	"skill_name" : "��ɽ��ˮ",
	"damage_type" : "����"
]),
([
	"action" : "$N�Ӷ�$w���û���������$w��һ�С���Ӱ������������$n����Ѩ",
	"lvl" : 40,
	"skill_name" : "��Ӱ����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С���ɽʽ������ת$w, �󿪴��أ��߾�ͷ��,ֱ����$n",
	"lvl" : 60,
	"skill_name" : "��ɽʽ",
	"damage_type" : "����"
]),
([
	"action" : "$N����$wһ����һ�С������̸�����˫�ֺ���$wɨ��$n������",
	"lvl" : 90,
	"skill_name" : "�����̸�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "axe" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");
	if (me->query_str(1) < 25)
		return notify_fail("��ı���̫�͡�\n");
	if ((int)me->query_skill("qiantian-yiyang", 1) < 15)
		return notify_fail("��ġ�Ǭ��һ���������̫ǳ��\n");
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
	int i, j, level;
	level = (int) me->query_skill("pangen-fu",1);

	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/4);
			if( me->query_temp("jingtian")){
				return ([
					"action" : YEL+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"YEL)+NOR,
					"force" : 250 + random(150),
					"dodge": random(20),
					"damage": 160 + random(80),
					"lvl" :  action[j]["lvl"],
					"parry": random(20),
					"weapon" : "����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"damage":140+random(60),
				"parry":random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("pangen-fu", 1);
	int i = sizeof(action);
	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ������������̸���ḫ����\n");
	if((int)me->query("neili") < 10)
		return notify_fail("����������������̸���ḫ����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"pangen-fu/" + action;
}
