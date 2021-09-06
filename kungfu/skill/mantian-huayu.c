//mantian-huayu.c���컨��
// 19981010
inherit SKILL;

string	*msg = ({
"$N������࣬һʽ������̤����������$w�������·�ͻȻ˦����ֱ����$n��$l",
"$w�ƿշɳ���һʽ�����羭�졹������һ�����ߣ��������ң�����$n��$l��",
"$N˫�����һʽ�����Ƽ��ա�������$w��$n����������$n��ȫ������",
"$N�����һ����ȴ��$nһ�С�������Ҷ����ʮ��ö$w�ɿ��л�������",
"$N���μ�����ǰ������һʽ��ѩ��׷�١�����ö$w��$n��в����ȥ",
"$Nһʽ�����ײ�ɣ��������һת������������ö$w������$n�ı���",
"$N���һ�ݣ�һ�С����Ƽ�����Ӹ����£�����$w���䣬ֱ��$n��$l",
"$Nһ�С����ǵ���������ָ������ö$w��һ��ڹ�����$n��ͷ��",
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
		"damage_type":"����",
		"dodge": random(20)-10,
		"parry": random(10),
		"force": 100 + random(250),
		"post_action": (: call_other, WEAPON_D, "throw_weapon" :)
	]);
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("����������������컨�ꡣ\n");
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
	if ( me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ( me->query_skill("xuantian-wuji", 1) < 30)
		return notify_fail("��������޼������̫ǳ��\n");
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"mantian-huayu/" + action;
}
