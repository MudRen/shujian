// pudu-zhang.c �ն��ȷ�

inherit SKILL;

mapping *action = ({
([
	"action":"$Nʹһ�С���ţת�ǡ�������$w���¶��ϣ������ޱȵ���$n��С����ȥ��",
	"lvl" : 0,
	"skill_name" : "��ţת��",
	"damage_type":"����"
]),
([
	"action":"$N�첽�����һ�С�Ұ��׷�硹������ƽ��$w�����������ȶˣ�����$n���ؿڡ�",
	"lvl" : 9,
	"skill_name" : "Ұ��׷��",
	"damage_type":"����"
]),
([
	"action":"$N�߾�$w��һ�С��ͻ���������ȫ��Ծ������$w§ͷ�Ƕ�����$n��ȥ��",
	"lvl" : 18,
	"skill_name" : "�ͻ�����",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С�ʨ��ҡͷ����˫�ֳ������֣���׼$n�͵�һ������ͬƽ�ع���һ�����硣",
	"lvl" : 27,
	"skill_name" : "ʨ��ҡͷ",
	"damage_type":"����"
]),
([
	"action":"$N���$w��һ�С�������β�����ȶ˻���������ԲȦ�����ͳ��أ���$n�������С�",
	"lvl" : 36,
	"skill_name" : "������β",
	"damage_type":"����"
]),
([
	"action":"$Nȫ�������$w�̵غ�ɣ�ͻ��һ�С�������������Ӱ��$n��������",
	"lvl" : 45,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([
	"action":"$N˫�ֺ�ʮ������һ�С���ɮ�в�����$w������ɳ���������$nײȥ��",
	"lvl" : 53,
	"skill_name" : "��ɮ�в�",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С��Ⱥ��նɡ���$w�������������Ծ����ֱ��$n���ؿڴ��롣",
	"lvl" : 60,
	"skill_name" : "�Ⱥ��ն�",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yijin-jing", 1) < 20)
		return notify_fail("����׽�ڹ����̫ǳ��\n");
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
	level   = (int) me->query_skill("pudu-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 100 + random(250),
				"dodge": random(20)-10,
				"damage": 40 + random(60),
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("pudu-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("��������������ն��ȷ���\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
