//hanshasheying ��ɳ��Ӱ
// 1997-2-14

inherit SKILL;

string  *msg = ({
"$N��һ�ʹһʽ������׷�¡���ֻ��������������ö$wǰ��������$n��$l���",
"$N���κ��ظ߸�Ծ��ʹһʽ����Ůɢ������������ö$w��$n�������",
"$Nһʽ��ȥ������������һ������ö$w��$n�����ӹ�������$n����Ȼתͷ��$n���ķ�ȥ",
"$N����ͻ�ص������������һ����ʹһ�С��ճ������������а��۵���ö$w��Ѹ�ײ����ڶ�֮������$n����",
"$N����һ��������$n��󣬷���һʽ��������񡹣�������ö$w��$n�ĺ���Ҫ����ȥ",
"$Nһʽ��������꡹��ͻȻ˫���������£�ʮ��ö$w�������ط���$n��ǰ��",
});

int valid_enable(string usage)
{
	return usage == "throwing" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage": 40 + random(60),
		"damage_type":random(2)?"����":"����",
		"dodge":random(20)-10,
		"force":random(250)+100,
		"parry": random(10),
		"post_action": (: call_other, WEAPON_D, "throw_weapon" :)
	]);
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("���������������ɳ��Ӱ��\n");
	if ( me->query("neili") < 10)
		return notify_fail("���������������ɳ��Ӱ��\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 50)
		return notify_fail("��Ķ����󷨻��̫ǳ��\n");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"hansha-sheying/" + action;
}
