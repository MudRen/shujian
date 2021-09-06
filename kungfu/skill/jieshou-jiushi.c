// jieshou-jiushi���־�ʽ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N���ƽ�������ǰ̽��һ�С���ʽ�ֽ𡹣��Ʒ�ֱ����$n��$l",
	"lvl" : 0,
	"skill_name" : "��ʽ�ֽ�",
	"damage_type" : "����"
]),
([
	"action" : "$N���ж�ת��һ�С�������ɽ�������ֻ��⣬����ֱ��$nǰ��",
	"lvl" : 20,
	"skill_name" : "������ɽ",
	"damage_type" : "ץ��"
]),
([
	"action" : "$N���һ����һ�С�˳ˮ���ۡ������в��䣬������Ѹ�仯�ƣ�б��$n�ĺ���",
	"lvl" : 40,
	"skill_name" : "˳ˮ����",
	"damage_type" : "����",
]),
([
	"action" : "$N˫�������������룬һ�С������Ὥ����ȥ����죬��$n��$l��ȥ",
	"lvl" : 60,
	"skill_name" : "�����Ὥ",
	"damage_type" : "����"
]),
([
	"action" : "$N�������,�����Ϸ⣬������ѹ������������$n��$l",
	"lvl" : 80,
	"skill_name" : "����С��",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�����������������ǰһ��͵�������ֻ�����ǰ����,����˳�Ʒ���$n������",
	"lvl" : 100,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([
	"action" : "$N�Ų����ţ���ȻԾ��$n������,һ�С�����ãã�������ִ���$n��$l",
	"lvl" : 120,
	"skill_name" : "����ãã",
	"damage_type" : "����"
]),
([
	"action" : "$N��ָ΢΢���죬һ�С���ɽ��ˮ������Ӱ������ٰ㽫$n����������",
	"lvl" : 140,
	"skill_name" : "��ɽ��ˮ",
	"damage_type" : "����"
]),
([
	"action" : "$NͻȻ��ü��������̬��ɢ�����ַ��飬$n��һ���ȣ���Ȼ�е�һ����ɽ�������Ʒ�Ϯ��",
	"lvl" : 160,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���־�ʽ������֡�\n");
	if (me->query_skill_mapped("force") != "linji-zhuang")
		return notify_fail("���־�ʽ�������ټ�ׯΪ������\n");
	if ( me->query_skill("linji-zhuang", 1) < 120)
		return notify_fail("����ټ�ׯ����û��ã�������ѧ���־�ʽ��\n");
       	if ( me->query_skill("sixiang-zhang", 1) < 100)
		return notify_fail("��������Ƹ���û��ã�������ѧ���־�ʽ��\n");
	if ( me->query("max_neili") < 1200)
		return notify_fail("�������̫�����޷������־�ʽ��\n");
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
	level   = (int) me->query_skill("jieshou-jiushi",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if( me->query_temp("liaoyuan") && me->query("jiali")) {
				return ([
					"action" : HIW+action[j]["action"]+NOR,
					"force" :  250 +random(350),
					"dodge":  random(30),
					"damage" : 50 + random(50),
					"parry" : random(30),
					"damage_type" : "����",
				]);
			}
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":200+random(350),
				"dodge":random(30)-10,
				"parry":random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("jieshou-jiushi", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������־�ʽ��\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jieshou-jiushi/" + action;
}
                   