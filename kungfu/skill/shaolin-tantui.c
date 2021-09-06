// /kungfu/skill/shaolin-tantui.c ���ֵ���

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ������ʽ��������֧�أ����Ȼ�����ֱ��$n��ͷ��",
	"lvl" : 0,
	"skill_name" : "����ʽ",
	"damage_type" : "����"
]),
([
	"action" : "$N����һ�����Ѵ�$n����ӹ������㷴�ߣ�����һ�С���ƽʽ��������$n�ı���",
	"lvl" : 10,
	"skill_name" : "��ƽʽ",
	"damage_type" : "����"
]),
([
	"action" : "$N�����ף����㻭������Բ��ʹ����׷��ʽ����ɨ��$n��ϥ��",
	"lvl" : 20,
	"skill_name" : "׷��ʽ",
	"damage_type" : "����"
]),
([
	"action" : "$N����΢�࣬����ٿ�ص���������$n��ͷ�����ɲ�������һʽ������ʽ��",
	"lvl" : 30,
	"skill_name" : "����ʽ",
	"damage_type" : "����"
]),
([
	"action" : "$N������������������η�ת��ɨ�������������������ɨ��ǰ��һ�С�ɨҶʽ��������$n��$l",
	"lvl" : 40,
	"skill_name" : "ɨҶʽ",
	"damage_type" : "����"
]),
([
	"action" : "$NԾ���ڰ�գ�˫�����裬�����������磬������ʽ����Ѹ�����׵ؾ���$n",
	"lvl" : 50,
	"skill_name" : "����ʽ",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }

int valid_combine(string combo) { return combo=="fengyun-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧ���ֵ���ʱ���ﲻ����������\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ���ֵ��ȡ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷������ֵ��ȡ�\n");
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
	level   = (int) me->query_skill("shaolin-tantui",1);
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
	int lvl = me->query_skill("shaolin-tantui", 1);
	int i = sizeof(action);

	while (i--) 
		if (lvl == action[i]["lvl"])
			return notify_fail("�����ڵ���ʽ�Ѿ��������ˣ���Ҫ��ʦ������µ���ʽ�ˡ�\n");;
	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("����������������ֵ��ȡ�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
