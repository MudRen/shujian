// /kungfu/skill/xiangmo-chu ��ս�ħ��
// by dubei
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([
	"action": "$N�߾�$w��һ�С�ħ����Ӱ�����ݺݵ���$n��$l��ȥ��",
	"lvl" : 0,
	"skill_name" : "ħ����Ӱ",
	"damage_type": "����"
]),
([
	"action": "$Nȫ��εض��𣬰����һ�����һʽ����ħ��, ����$wɨ��$n��$l��",
	"lvl" : 20,
	"skill_name" : "��ħ",
	"damage_type": "����"
]),
([
	"action": "$N����$w�趯��һ�У����������Ю�������ײ��֮��������$n��$l��",
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([
	"action": "$Nһ�С�������С�������$w��������������$n��",
	"lvl" : 60,
	"skill_name" : "�������",
	"damage_type": "����"
]),
([
	"action": "$N�������$w��ʹ�������Ӻ�ա�������$w���ն��£�����$n$l��",
	"lvl" : 90,
	"skill_name" : "���Ӻ��",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if((int)me->query_skill("mingwang-jian",1) <100)
		return notify_fail("��Ĳ�������������򲻹���\n");
	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("����������㣬û�а취����ս�ħ�ơ�\n");
	if ((int)me->query_skill("longxiang-gong", 1) < 100)
		return notify_fail("��ս�ħ����Ҫ��������ϵ����������������ϰ��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "staff" )
		return notify_fail("����������ԡ�\n");
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
	int i, level, j;
	level   = (int) me->query_skill("xiangmo-chu",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150 + random(300),
				"damage":	60 + random(100),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("xiangmo-chu", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40 || me->query("neili") < 20)
		return notify_fail("����Ъ���������ɡ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
