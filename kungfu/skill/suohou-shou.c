// suohou-shou ����������
// Lklv@SJ 2001.10.05

#include <ansi.h>
#include <combat.h>

inherit SKILL;

string *action_msg = ({
"$N�������������������ָ���ţ�����$n�ľ�����ץ��",
"ֻ��һ�󾢷�ֱ����ǰ$N�����������ֱָȡ$n����ɤ�ʺ�",
"$N����һ�ӣ���$n�����������������ţ����ּ�̽������$n�ĺ�ͷץ��",
"$N���μ��������䵽$n�����һ˫����Ĵ���ץ��$n�ĺ�",
"$N˫������������޹ǣ����������һ�㣬������ס$n�Ĳ��Ӳ���",
});

int valid_enable(string usage)
{
	return usage == "hand" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	int lvl;
	lvl = (int)me->query_skill("suohou-shou", 1);

	if ( random(lvl) > 100 && me->query("neili") > 800 && random(3)){
		if ( lvl <= 150) {
			me->add("neili", -50);
			return ([
				"action": "$N����һ̧���������ᣬ������ϢϮ��$n��������צͻȻ������������֮�������Һϻ�ֱȡ$n�ĺ�����",
				"damage_type": "����",
				"dodge": 10,
				"parry": 5,
				"force" : 300,
			]);
		}
		else {
			me->add("neili", -80);
			return ([
				"action": "$N���������������׺ݣ���¶�׹⣬���в���$n��Ҫ����λ,�ƺ�Ҫ��$n���̻����\n"
				"$N˫������������У���������������$n��������������òҿ��ޱȡ�",
				"damage_type": "ץ��",
				"dodge": 15,
				"parry": 10,
				"force" : 350,
			]);
		}
	}
	return ([
		"action": action_msg[random(sizeof(action_msg))],
		"damage_type": random(2)?"ץ��":"����",
		"dodge": random(20)-10,
		"parry": random(10),
		"force": 100+random(250),
	]);
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 30)
		return notify_fail("����������������������֡�\n");
	if ( me->query("neili") < 15)
		return notify_fail("����������������������֡�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����������ֱ�����֡�\n");

	if ( me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ( me->query_skill("huntian-qigong", 1) < 30)
		return notify_fail("��Ļ���������򲻵���\n");
	return 1;
}
