// mingwang-jian.c ����������
// by dubei 
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ��һʽ���󱯡���$N���е�$w�Ѿ�Ѹ���ޱȵĴ���$n��$l��  ",
        "skill_name" : "��",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һʽ�����������򵥶���Ч����$n��$l��ȥ��",
        "skill_name" : "����",
        "force" : 120,
        "dodge" : 5,
        "lvl" : 20,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�������������һת������һ�ӣ�����$w����$n��$l��",
        "skill_name" : "����",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 40,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ�������ѡ���˫�ŵ�أ�ȫ��ת��һ�Ž������$n��",
        "skill_name" : "����",
        "force" : 170,
        "dodge" : 10,
        "lvl" : 60,
        "damage" : 48,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ġ���ȫ��������$w�У�һƬ����Ϯ��$n��$l��",
        "skill_name" : "����",
        "force" : 250,
        "dodge" : 10,
        "lvl" : 70,
        "damage" : 54,
        "damage_type" : "����",
]),
([      "action" : "$N�����ת��һʽ������������������$n��$l��",
        "skill_name" : "����",
        "force" : 180,
        "dodge" : -15,
        "lvl" : 80,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ڡ�������$w�����������$n��$l����������",
        "skill_name" : "����",
        "force" : 200,
        "dodge" : 20,
        "lvl" : 90,
        "damage" : 66,
        "damage_type" : "����",
]),
([      "action" : "$N�趯$w�������˽�����ȥ��һ�С����ס���Ю�������������$n��$l��",
        "skill_name" : "����",
        "force" : 220,
        "dodge" : 25,
        "lvl" : 100,
        "damage" : 80,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
 

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang-gong", 1) <= 20 ) 
                   return notify_fail("���������������̫ǳ��\n");
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
	level   = (int) me->query_skill("mingwang-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("������������������˲�����������\n");
	me->receive_damage("jing", 25);
	return 1;
}
