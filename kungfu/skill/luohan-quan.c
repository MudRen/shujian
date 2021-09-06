// luohan-quan.c �޺�ȭ

inherit SKILL;

mapping *action = ({
([
	"action" : "$N�����ϲ���һʽ����ݺ��ܡ��������ַֿ�����ȭΪ�ƣ�����$n��$l",
	"lvl" : 0,
	"skill_name" : "��ݺ���",
	"damage_type" : "����"
]),
([
	"action" : "$N�����̤��ȫ����ת��һ�С����ﳯ�����������͵ز���$n��$l",
	"lvl" : 10,
	"skill_name" : "���ﳯ��",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С����Ӷ�Ӧ����˫ȭ��$n��$l��ȥ",
	"lvl" : 20,
	"skill_name" : "���Ӷ�Ӧ",
	"damage_type" : "����"
]),
([
	"action" : "$N����Ȧ���������⵱�أ����ڳ��ϣ�һ�С�ƫ�����ǡ�����$n��$l",
	"lvl" : 30,
	"skill_name" : "ƫ������",
	"damage_type" : "����"
]),
([
	"action" : "$Nʹһ�С��ຣ��ͷ��������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
	"lvl" : 40,
	"skill_name" : "�ຣ��ͷ",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ƻ�����һ�ǡ�Юɽ���������Ƴ���磬һ�����е�$n��$l",
	"lvl" : 50,
	"skill_name" : "Юɽ����",
	"damage_type" : "����"
]),
([
	"action" : "$Nʩ��������������˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
	"lvl" : 60,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$N����ڿۣ�����������һʽ�������������˫�����밴��$n��$l",
	"lvl" : 70,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) {
	if(this_player()->query_skill("wuxiang-zhi", 1) >= 200
	&& this_player()->query_skill("luohan-quan",1) >= 200
	&& this_player()->query_con(1) > 45
	&& this_player()->query_int(1) > 45)
		return combo=="wuxiang-zhi";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���޺�ȭ������֡�\n");
	if ( me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ�޺�ȭ��\n");
	if ( me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷����޺�ȭ��\n");
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
	level = (int) me->query_skill("luohan-quan",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if( me->query_skill("wuxiang-zhi", 1))
				return ([
					"action": action[j]["action"],
					"damage_type": action[j]["damage_type"],
					"lvl": action[j]["lvl"],
					"force": 200 + random(350),
					"dodge": random(30)-10,
					"parry": random(20),
				]);
				else return ([
					"action": action[j]["action"],
					"damage_type": action[j]["damage_type"],
					"lvl": action[j]["lvl"],
					"force": 100 + random(250),
					"dodge": random(20)-10,
					"parry": random(10),
				]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("luohan-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("��������������޺�ȭ��\n");
	if ( me->query_skill("wuxiang-zhi", 1)) {
		me->receive_damage("jingli", 40);
		me->add("neili", -15);
	}
	else {
		me->receive_damage("jingli", 20);
		me->add("neili", -5);
	}
	return 1;
}
