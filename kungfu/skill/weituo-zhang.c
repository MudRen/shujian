// weituo-zhang.c Τ����

inherit SKILL;

mapping *action = ({
([
	"action" : "$N˫��΢��������΢΢������˫�����ƣ�һ�С�����ٵء���һ����ɽ֮��ѹ��$n",
	"lvl" : 0,
	"skill_name" : "����ٵ�",
	"damage_type" : "����"
]),
([
	"action" : "$N���а����ӷ�һ�С��������ա������ƻ���$n���ţ���һ��ȴ����$n��С��",
	"lvl" : 15,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ƻ������Ī�⣬һ�С�������ɫ����˲Ϣ֮����$n����������һʮ����",
	"lvl" : 30,
	"skill_name" : "������ɫ",
	"damage_type" : "����",
]),
([
	"action" : "$N����һ�ƣ�û�а�����ף�һ�С����ޱߡ����͵���$n��$l�����ȥ",
	"lvl" : 40,
	"skill_name" : "���ޱ�",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ƽ����������ޣ�һ�С�˭������������ž�������$n�ļ�ͷ��ǰ��",
	"lvl" : 50,
	"skill_name" : "˭�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�����������������һ�ƻ�����������������һ�����$n��$l",
	"lvl" : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$N˫���ڿ����뻮������˫�����ƣ�һ�С��ҷ�ȱ�����һ����ɽ������������ֱ��$n����",
	"lvl" : 70,
	"skill_name" : "�ҷ�ȱ�",
	"damage_type" : "����"
]),
([
	"action" : "$NͻȻ���м�ת��һ�С��ຣ��ͷ������Ӱ���裬��ʱ֮�佫$n����˷�����ס��",
	"lvl" : 80,
	"skill_name" : "�ຣ��ͷ",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="yingzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��Τ���Ʊ�����֡�\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("����׽�ڹ���򲻹����޷���Τ���ơ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���Τ���ơ�\n");
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
	level   = (int) me->query_skill("weituo-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
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
	int lvl = me->query_skill("weituo-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("�������������Τ���ơ�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
