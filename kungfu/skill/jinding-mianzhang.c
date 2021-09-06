// jinding-mianzhang.c -������

inherit SKILL;

mapping *action = ({
([	"action" : "$N��$nңңһ�ϣ�һʽ��������̩����˫�ƴ󿪴��أ�����$n�Ľ���",
	"force" : 180,
        "dodge" : 5,
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "������̩"
]),
([	"action" : "������$N�溬΢Ц��һʽ���������项��˫���Ʋ����ƣ�ͬʱ����$nȫ�����",
	"force" : 220,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 10,
	"skill_name" : "��������"
]),
([	"action" : "$N�������һʽ��������ɳ����˫����£���У�����$n��$l",
	"force" : 270,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 20,
	"skill_name" : "������ɳ"
]),
([	"action" : "������$Nʹһʽ������ơ���˫�ֻ��ƣ�һǰһ����ǰ���ƣ�����$n��$l",
	"force" : 300,
        "dodge" : -5,
        "damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "�����"
]),
([	"action" : "$Nʹһʽ������ء���ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
	"force" : 320,
        "dodge" : 10,
        "damage_type" : "����",
	"lvl" : 40,
	"skill_name" : "�����"
]),
([	"action" : "$Nһʽ���׶���������˫����Ѹ�ײ����ڶ�֮�ƣ������������̫��Ѩ",
	"force" : 340,
        "dodge" : -5,
        "damage_type" : "����",
	"lvl" : 60,
	"skill_name" : "�׶�����"
]),
([	"action" : "$N���ϸ߸�Ծ��һʽ����ɽ��ˮ�����Ӹ����£���������$n��ȫ��",
	"force" : 380,
        "dodge" : 0,
        "damage_type" : "����",
	"lvl" : 90,
	"skill_name" : "��ɽ��ˮ"
]),
([	"action" : "$Nʹһʽ��ժ�ǻ�����������������˫�����֣�һ������$n��$l�ȥ",
	"force" : 400,
        "dodge" : 10,
        "damage_type" : "����",
	"lvl" : 120,
	"skill_name" : "ժ�ǻ���"
]),
([	"action" : "$Nһʽ�����Ľ�ħ����˫�����÷��ã��ƶ��Ƕ��������缱����ʹ����������",
	"force" : 460,
        "dodge" : -10,
        "damage_type" : "����",
	"lvl" : 150,
	"skill_name" : "���Ľ�ħ"
]),
([	"action" : "$Nŭ߳һ����һʽ���𶥷�⡹���������������Ƽ�����Ķ�����Ѩ",
	"force" : 520,
        "dodge" : 10,
        "damage_type" : "����",
	"lvl" : 180,
	"skill_name" : "�𶥷��"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧϰ�����ơ�\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("�������̫�����޷��������ơ�\n");
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
	int i, level;
	level = (int)me->query_skill("jinding-mianzhang", 1);
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
