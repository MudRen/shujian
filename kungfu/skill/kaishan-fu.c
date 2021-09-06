// kaishan-fu.c 

inherit SKILL;

mapping *action = ({
([	"action" : "$Nƽ������$w��һ�С������𡹣�������ǰ����$n��$l��ȥ",
	"force" : 100,
	"dodge" : 20,
       "damage" : 10,
	"lvl" : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����ɽ������һվ,���Ƹ�����$wƽƽ��$n�ľ���Ĩȥ",
	"force" : 150,
	"dodge" : 20,
	"damage" : 20,
	"lvl" : 30,
	"skill_name" : "����ɽ",
	"damage_type" : "����"
]),
([	"action" : "$N�������츫Ӱ������Ҵ�,һ�С�����ơ��������$n��ȫ��",
	"force" : 200,
	"dodge" : -20,
	"damage" : 40,
	"lvl" : 40,
	"skill_name" : "�����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����ɽ������ʽ��׾,�󿪴��أ��߾�ͷ��,ֱ����$n",
	"force" : 250,
	"dodge" : 30,
	"damage" : 60,
	"lvl" : 90,
	"skill_name" : "���»���",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ������������,һ�С�����ء���˫�ֻ���$w����$n���ؿ�",
	"force" : 300,
	"dodge" : -10,
	"damage" : 80,
	"lvl" : 120,
	"skill_name" : "�����",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������������\n");
       if (me->query("str") < 25)
		return notify_fail("��ı���̫�͡�\n");
	if ((int)me->query_skill("qiantian-yiyang", 1) < 60)
		return notify_fail("��ġ�Ǭ��һ���������̫ǳ��\n");
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
	level   = (int) me->query_skill("kaishan-fu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�����������������ɽ��������\n");
	me->receive_damage("qi", 25);
	return 1;
}

