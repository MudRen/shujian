// liangyi-jian.c (kunlun) �����������ǽ���
//update by cool 981104

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action":"$Nһʽ��˳ˮ���ۡ���$N����$wָ���Լ����ؿڣ�����бб�����⣬��������$n��$l",
	"lvl" : 0,
	"skill_name" : "˳ˮ����",
	"damage_type":"����"
]),
([
	"action":"$N����΢�࣬���ֺ�ڣ�����$wһ�С���ɨǧ������ֱ��$n�������ȥ",
	"lvl" : 10,
	"skill_name" : "��ɨǧ��",
	"damage_type":"����"
]),
([
	"action":"$N�����ǰ��$w��Ȼ���䵯�������ⱬ����һ�С��ͱڶ��ơ����͵ش���$n���ؿ�",
	"lvl" : 20,
	"skill_name" : "�ͱڶ���",
	"damage_type":"����"
]),
([
	"action":"$N�������������ƽ�ƶ�������ָ���������ֽ����첻����һ�С�����ָ·��������$n",
	"lvl" : 40,
	"skill_name" : "����ָ·",
	"damage_type":"����"
]),
([
	"action":"$N���к��䣬ʹ��һ�С����ɻ�����ȫ��б�ƣ����߰���б����ż����Ю��һ�����ƣ����˼���׽��",
	"lvl" : 60,
	"skill_name" : "���ɻ�",
	"damage_type":"����"
]),
([
	"action":"$N����$w�������𣬷�����£�һ�С���Įƽɳ�������ߵ��ƣ�����$n��$l",
	"lvl" : 80,
	"skill_name" : "��Įƽɳ",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С�ľҶ��������$N����$w������бָ���죬���϶��£�����$n��$l",
	"lvl" : 100,
	"skill_name" : "ľҶ����",
	"damage_type":"����"
]),
([
	"action":"$N��ǰһ����$w΢΢�����������㣬һ�С����Ӳ��ߡ����ն���ʼ�����಻������$n",
	"lvl" : 120,
	"skill_name" : "���Ӳ���",
	"damage_type":"����"
]),
([
	"action":"$N���ֽ���һ�٣�������ʯ�⣬һ�С��������ơ����ý�����ס$n���б�����$wֱָ$n���ʺ�",
	"lvl" : 140,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([
	"action":"$N����ؽ�������б����һ�С����ɷ��١�������Ӱ����ֱк��������ס$n�Ϸ�",
	"lvl" : 160,
	"skill_name" : "���ɷ���",
	"damage_type":"����"
]),
([
	"action":"$Nһʽ��ѩӵ���š���$N���н������ţ�һ����������������$n",
	"lvl" : 180,
	"skill_name" : "ѩӵ����",
	"damage_type":"����"
]),
([
	"action":"$N�ڿն���ͻȻʹ��һ�С�������ɫ����������Ϣ�ؼ���$n�ı�����ȥ",
	"lvl" : 200,
	"skill_name" : "������ɫ",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ( me->query("max_neili") < 800)
		return notify_fail("�������������\n");

	if ( me->query_skill("xuantian-wuji", 1) < 100)
		return notify_fail("��������޼������̫ǳ��\n");

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

	level = (int) me->query_skill("liangyi-jian",1);

	for (i = sizeof(action); i > 0; i--) {
		if (level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("kl/xunlei")){
				return ([
					"action": action[j]["action"],
					"lvl": action[j]["lvl"],
					"damage_type": action[j]["damage_type"],
					"force": 250 +random(350),
					"dodge": random(30),
					"parry": random(30),
					"damage": 130 +random(140),
				]);
			}
			else if( me->query_temp("ly_hebi") ) {
				return ([
					"action": HIC+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC), NOR, HIC)+NOR,
					"lvl": action[j]["lvl"],
					"damage_type": action[j]["damage_type"],
					"force": 200 +random(350),
					"dodge": random(30)-10,
					"parry": random(20),
					"damage": 80 +random(140),
				]);
			}
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 200 +random(350),
				"dodge": random(30)-10,
				"parry": random(20),
				"damage": 80 +random(140),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("liangyi-jian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("neili") < 20)
		return notify_fail("����������������ǽ�����\n");
	if ( me->query("jingli") < 50)
		return notify_fail("����������������ǽ�����\n");
	me->receive_damage("jingli", 40);
	me->add("neili",  -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liangyi-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int i;

	i = me->query_skill("liangyi-jian",1)/4;

	if( me->query_temp("ly_hebi")
	 && !me->query_temp("hebi_hit") 
	 && random(10) > 5
	 && me->query_skill_mapped("parry") == "liangyi-jian") {
		me->set_temp("hebi_hit", 1);
		me->add_temp("apply/attack", i);
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);  
		me->add_temp("apply/attack", -i);
		me->delete_temp("hebi_hit");
	}
}
