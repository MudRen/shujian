// �����ȷ�
//written by cool

inherit SKILL;

mapping *action = ({
([
	"action" : "$N���Ӽ�ת���ҽ����������һʽ������Ϊ�Ρ�����ɨ$n������",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "����Ϊ��"
]),
([
	"action" : "$N�����߳��������������£��ҽŽ���������߳���һʽ��׷����硹��˫���Ⱥ�����$n��$l",
	"damage_type" : "����",
	"lvl" : 15,
	"skill_name" : "׷�����"
]),
([
	"action" : "$Nһʽ�����Ҵ���������ź��ߣ��漴����ǰ���䲽���ҽ�Ѹ�ٷ�������$n��$l",
        "damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "���Ҵ���"
]),
([
	"action" : "$NͻȻһ���󷭣�һʽ�����߱�������˫�Ȼζ�����$n��$l��ȥ",
        "damage_type" : "����",
	"lvl" : 45,
	"skill_name" : "���߱���"
]),
([
	"action" : "$Nʹһʽ�����Ʋ��¡����εض���˫�������߳�������$n���ؿ�",
        "damage_type" : "����",
	"lvl" : 60,
	"skill_name" : "���Ʋ���"
]),
([
	"action" : "$N������������һʽ����ɨ���ݡ������Ⱥ�ɨ$n��$l",
	"damage_type" : "����",
	"lvl" : 75,
	"skill_name" : "��ɨ����"
]),
([
	"action" : "$N����һ�ƣ������$n��ͷ����һʽ����Ӱ���١�������ͻȻ����$n��$l",
	"damage_type" : "����",
	"lvl" : 90,
	"skill_name" : "��Ӱ����"
]),
([
	"action" : "$Nʹһʽ���������¡���������ն���˫��������ֻ��������Ӱ������$n",
	"damage_type" : "����",
	"lvl" : 100,
	"skill_name" : "��������"
]),
});

int valid_enable(string usage) { return usage=="leg" ||  usage=="parry"; }
 int valid_combine(string combo) { return combo=="zhentian-quan"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ȱ�����֡�\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 20)
		return notify_fail("��������޼�����򲻹����޷�ѧ�����ȡ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷��������ȡ�\n");
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
	level = (int)me->query_skill("chuanyun-tui", 1);
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
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("chuanyun-tui", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 10)
		return notify_fail("������������������ȡ�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"chuanyun-tui/" + action;
}
