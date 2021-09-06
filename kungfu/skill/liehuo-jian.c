// liehuo-jian.c �һ�

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһ�С��ĺ���Ʈ����$w�ƻó�ƬƬ���ƣ�����˷�������$n",
	"lvl" : 0,
	"skill_name" : "�ĺ���Ʈ",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С���ͨ�˴��������ָ������$n��$n�������ֱܷ�$w����·",
	"lvl" : 10,
	"skill_name" : "��ͨ�˴�",
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ��������һ������$w��һ������������һ�ɺ�������$n��$l",
	"lvl" : 20,
	"skill_name" : "����һ��",
	"damage_type" : "����"
]),
([
	"action" : "$N�������ϵ���������ָ��һ�С���������������$w����һ�Ž���������$n��$l",
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С����ٵ����������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
	"lvl" : 40,
	"skill_name" : "���ٵ���",
	"damage_type" : "����"
]),
([
	"action" : "$N���Ȱ�����ף�$wƽָ��һ�С�������ɫ��������������ɫ�������Ĵ���$n��$l",
	"lvl" : 50,
	"skill_name" : "������ɫ",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С��򴨹麣����$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
	"lvl" : 60,
	"skill_name" : "�򴨹麣",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if (! me->query_skill("jiuyang-shengong", 1))
	if ( me->query_skill("shenghuo-shengong", 1) < 20)
		return notify_fail("���ʥ���񹦻��̫ǳ��\n");
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
        level   = (int) me->query_skill("liehuo-jian",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 40 + random(60),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("liehuo-jian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30 || me->query("neili") < 10 )
		return notify_fail("��������������һ𽣷���\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
