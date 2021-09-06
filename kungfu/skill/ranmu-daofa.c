// ranmu-daofa.c ȼľ����

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
	"action" : "$N���΢Ц��һ�С��һ���������$w����$n�������˰˰���ʮ�ĵ��������ݺᣬ�����һ������$p��Ѹ�ײ��ɵ�",
	"lvl" : 0,
	"skill_name" : "�һ�����",
	"damage_type" : "����"
]),
([
	"action" : "$N�����ڹ�һ�С���ľ���𡹣���$w�ϴ��������ޱȾ�����Ѹ�ٻ���һ���󻡣����϶�������$n��$l",
	"lvl" : 30,
	"skill_name" : "��ľ����",
	"damage_type" : "����"
]),
([
	"action" : "$N�ֱ�һ��һ����ʹ�����Ź����¡���˫�ֳ���$w����һ��ѩ�����⣬����$n���֮ʱ�͵��������У�����$n��$l",
	"lvl" : 60,
	"skill_name" : "�Ź�����",
	"damage_type" : "����"
]),
([
	"action" : "$N����$w�������ã����ҿ���ʹ��һ�С��һ����ơ����������󵶷磬ÿһȦ����������ͬ����������������$n",
	"lvl" : 90,
	"skill_name" : "�һ�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�����ȡ������������Ȧ�����Ծ����أ�����$w��ǰֱ�죬���߽��ƣ�Ю�����ȵķ�������$n��$l",
	"lvl" : 120,
	"skill_name" : "����ȡ��",
	"damage_type" : "����"
]),
([
	"action" : "$N�ڿն��𣬰����һ�С���ʯ��١��������£�����$wѸ�����������������ĵ�Ӱ��ɽ���������$n��ȫ���ȥ",
	"lvl" : 150,
	"skill_name" : "��ʯ���",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query_skill("riyue-bian",1)
	 || (int)me->query_skill("weituo-chu",1)
	 || me->query("passdu"))
		return notify_fail("������д�Ħ�������Ϊ������ͬʱѧϰ������������\n"); 

	if(!me->query("family") || me->query("family/family_name")!="������" )
		return notify_fail("�㲻�����ֵ��ӣ����������ȼľ������\n");

	if ( me->query("max_neili") < 1500)
		return notify_fail("�������������\n");

	if ( me->query_skill("yijin-jing", 1) < 160)
		return notify_fail("����׽�ڹ����̫ǳ��\n");

	if ( me->query_skill("ranmu-daofa",1) <= 200
	 &&  me->query_skill("xiuluo-dao",1) <= 120)
		return notify_fail("������޵���򲻹���������ȼľ����\n");
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
	level = (int) me->query_skill("ranmu-daofa",1);

	if ( me->query_temp("fenwo_hit")){
		return ([
			"action": HIR"$N˫�Ƽе���ʮ�����е�"+weapon->name()+HIR"��ʱ����һ�Ż��潫�Լ���Χ��$P����һ����ţ�һ��ֱ����$n" NOR,
			"damage": 200+ random(140),
			"dodge" : -60+random(40),
			"parry": -110+random(60),
			"force": 300 + random(350),
			"damage_type": "����"
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 200 + random(350),
				"dodge": random(30)-10,
				"damage": 80 + random(140),
				"parry": -20-random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 50 )
		return notify_fail("��ľ���������ȼľ������\n");

	if ((int)me->query("neili") < 20 )
		return notify_fail("�������������ȼľ������\n");

	me->receive_damage("jingli", 40);
	me->add("neili",-15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"ranmu-daofa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( userp(me)
	 && me->query_temp("fenwo_hit")
	 && victim->query("combat_exp") >= me->query("combat_exp")/2
	 && me->query("fenwo") < me->query_skill("blade"))
		me->add("fenwo", 1); // for rmd's fenwo pfm
}
