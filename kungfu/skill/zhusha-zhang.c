//shusha-zhang.c ��ɰ��
//written by cool

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ���鲽���֡������Ʒ��ƣ�˫��һ�ӣ�ֱ��$n��$l��ȥ",
	"force" : 180,
       "dodge" : 5,
       "parry" : -5,
	"lvl" : 0,
	"skill_name" : "�鲽����",
        "damage_type" : "����"
]),
([	"action" : "$N����һת��һʽ��˫���ơ�������б����࣬�������£�����$n��$l",
	"force" : 220,
        "dodge" : -10,
        "parry" : 15,
	"lvl" : 20,
	"skill_name" : "˫����",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ���Ʒ紩�ơ�������ǰ�壬˫����ǰ�����ֱȡ$n��$l",
	"force" : 260,
        "dodge" : 15,
        "parry" : -10,
	"lvl" : 40,
	"skill_name" : "�Ʒ紩��",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�֣�һʽ��������ն�������Ʒ���$n���ֲ���������$n����в����",
	"force" : 300,
        "dodge" : -5,
        "parry" : -10,
	"lvl" : 60,
	"skill_name" : "������ն",
        "damage_type" : "����"
]),
([	"action" : "$N�������£�һʽ����ˤ�ơ����������Ʊ���ˤ$n��ͷ��",
	"force" : 340,
        "dodge" : 0,
        "parry" : 10,
	"lvl" : 80,
	"skill_name" : "��ˤ��",
        "damage_type" : "����"
]),
([	"action" : "$NͻȻ����һ����ʹ��һʽ��͵©�ơ����ҽ�ǰ�ۣ���������Ȧ�֣�������������$n��$l",
	"force" : 380,
        "dodge" : -5,
        "parry" : 5,
	"lvl" : 100,
	"skill_name" : "͵©��",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ��������ɽ��������������������ķ�ת���͵���������$n��$l",
	"force" : 400,
        "dodge" : -30,
        "parry" : 30,
	"lvl" : 120,
	"skill_name" : "������ɽ",
        "damage_type" : "����"
]),
([	"action" : "$Nһ����ȣ�һ�С����ż�ɽ������ʽ���ȣ�˫�ư��죬ӭ������$n��ͷ��",
	"force" : 450,
        "dodge" : 0,
        "parry" : -5,
	"damage": 35,
	"lvl" : 150,
	"skill_name" : "���ż�ɽ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɰ�Ʊ�����֡�\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 20)
		return notify_fail("��Ĺ�Ԫ���ɷ���򲻹����޷�ѧ��ɰ�ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����ɰ�ơ�\n");
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
	level   = (int) me->query_skill("zhusha-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("���������������ɰ�ơ�\n");
	me->receive_damage("qi", 10);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("zhusha-zhang")) > 60 && (me->query_condition("warm_poison")<50))
	victim->apply_condition("warm_poison", random(me->query_skill("zhusha-zhang")/20) + 1 + victim->query_condition("warm_poison"));
}

