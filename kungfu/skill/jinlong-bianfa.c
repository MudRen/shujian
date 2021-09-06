// jinlong-bianfa �����޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
	"action":   "$N���β�����һ�С������ʯ��������$w��ֱ��ʸ����׼$n��ǰ�ش�ȥ",
	"lvl" : 0,
	"skill_name" : "�����ʯ",
	"damage_type":  "����"
]),
([
	"action":   "$N������ת������$w�糤����ˮ��һ�С�������ˮ����$n�������ر�Ӱ����",
	"lvl" : 20,
	"skill_name" : "������ˮ",
	"damage_type":  "����"
]),
([
	"action":  "$N���ΰ���������ң�һ�С����ഩ�ơ�������$w���һ������ֱȡ$n��$l",
	"lvl" : 40,
	"skill_name" : "���ഩ��",
	"damage_type":  "����"
]),
([
	"action": "$N���η��ͣ�һ�С���߸̽����������$w����������Ӱ����׼$n������ȥ",
	"lvl" : 60,
	"skill_name" : "��߸̽��",
	"damage_type":  "����"
]),
([
	"action": "$N����������紵�ͣ�ƮȻ������һ�С����Χ����������$w���һ����ԲȦ������$n������",
	"lvl" : 80,
	"skill_name" : "���Χ��",
	"damage_type":  "����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("����������㣬û�а취�������޷�, ����Щ���������ɡ�\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");
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
	level   = (int) me->query_skill("jinlong-bianfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":150+random(300),
				"dodge":random(30),
				"damage":60+random(100),
				"parry":random(30),
			]);
		}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("jinlong-bianfa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40 || me->query("neili") < 20)
		return notify_fail("������������������޷���\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinlong-bianfa/" + action;
}
