// wudang-quan.c �䵱��ȭ

inherit SKILL;

mapping *action = ({
([
	"action" : "$N�����ұۣ�һ�С������֡���һȭֱ������$n��$l",
	"lvl" : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$N����ǰ̽������籼$n��࣬һ�С����֡�����$n��$l��ȥ",
	"lvl" : 10,
	"skill_name" : "����",
	"damage_type" : "����"
]),
([
	"action" : "$N˫��΢�������лζ���һ�С�һ���ޡ����д�������$n��$l",
	"lvl" : 20,
	"skill_name" : "һ����",
	"damage_type" : "����"
]),
([
	"action" : "$N�����ȣ�������Σ�������ȭһʽ��ֱ����Ѹ�ʹ���$n���ؿ�",
	"lvl" : 40,
	"skill_name" : "ֱ��",
	"damage_type" : "����"
]),
([
	"action" : "$Nʩ�������ͷ��������Ծ����У�˫��ͬʱ����$n��$l",
	"lvl" : 50,
	"skill_name" : "���ͷ",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ۻػ�������΢΢������һ�С�������������$n��˫��",
	"lvl" : 60,
	"skill_name" : "����",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���䵱��ȭ������֡�\n");
	if ((int)me->query_skill("yinyun-ziqi", 1) < 10)
		return notify_fail("�����������򲻹����޷�ѧ�䵱��ȭ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷����䵱��ȭ��\n");
	return 1;
}

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("wudang-quan",1);
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"parry":random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("wudang-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("��������������䵱��ȭ��\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
