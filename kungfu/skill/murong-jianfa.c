#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N�����ָ��һʽ��ϴ����������˫�ź�����������������$wһ�Σ�ֱ��$n$l",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : "$N̤ǰ������������$w������Σ������ʵ������ʹһʽ�������������ֱ��$n��$l",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С����������$w��������׵Ľ������м��л����ֱ����$n��ȫ���Ѩ",
	"lvl" : 60,
	"damage_type" : "����"
]),
([
	"action" : "$N�����ڣ�����ָ��$n��������һ�С�����Ī��������������ǧ��һ�㣬��ɨ$n��$l",
	"lvl" : 90,
	"damage_type" : "����"
]),
([
	"action" : "$N˫����أ�ʹ�����Ϸɣ�����ֱ��$n��һ�С��ﻢ���¡��������й���ƽ��$n��$l",
	"lvl" : 120,
	"damage_type" : "����"
]),
([
	"action" : "$N��Цһ������$w�������У�һ�С���ש���񡹣�����һ��ѩ���Ľ��⣬����һ�����磬ֱ��$n��ȥ",
	"lvl" : 150,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 20)
		return notify_fail("�����Ԫ�����̫ǳ��\n");
	if ((int)me->query_skill("parry", 1) < 10)
		return notify_fail("��Ļ����мܻ��̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, j, level;
	level   = (int) me->query_skill("murong-jianfa",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/4);
			if (me->query_temp("lianhuan") > 0) {
				return ([
					"action" : HIC+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC)+NOR,
					"force" : 200 +random(300),
					"dodge": random(35),
					"parry": random(35),
					"damage" : 180 + random(100),
					"damage_type" : "����",
				]);
			}
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force": 150 +random(300),
				"dodge": random(30),
				"parry": random(30),
				"damage": 60 +random(100),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("murong-jianfa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;
	if ((int)me->query("jingli") < 40)
		return notify_fail("�������������Ľ�ݽ�����\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������Ľ�ݽ�����\n");
	me->receive_damage("jingli", 30);
	me->receive_damage("neili", 10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"murong-jianfa/" + action;
}

void lianhuan(object me, object victim)
{
	object weapon;

	if (!me || !victim || !me->is_fighting(victim))
		return;
	weapon = me->query_temp("weapon");
	if(me->query_temp("lianhuan")
	&& !me->query_temp("lianhuan_hit")
	&& me->query_skill_prepared("finger") == "canhe-zhi"
	&& me->query_skill_mapped("finger") == "canhe-zhi"
	&& objectp(weapon)) {
		me->set_temp("lianhuan_hit", 1);
                weapon->unequip();
if( random(me->query_skill("canhe-zhi",1)>= 180 )) victim->set_temp("must_be_hit",1);
                COMBAT_D->do_attack(me, victim, 0, 3);
victim->delete_temp("must_be_hit",1);
		weapon->wield();
		me->add("neili", -30);
		me->delete_temp("lianhuan_hit");
	}
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	call_out((: lianhuan :), 1, me, victim);
}
