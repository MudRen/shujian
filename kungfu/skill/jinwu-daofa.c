// jinwu-dao.c ���ڵ�

inherit SKILL;

mapping *action = ({
([      "action" : "$N�ص����գ�һ�С�����鮵������������¶��ϻ��˸��뻡����$n��$l��ȥ",
        "force" : 220,
        "dodge" : -10,
        "parry" : 5,
        "damage": 85,
        "lvl" : 0,
        "skill_name" : "����鮵�",
        "damage_type" : "����"
]),
([      "action" : "$N�����������⣬һ�С�÷ѩ���ġ�������$w��ֱ����$n��$l",
        "force" : 250,
        "dodge" : -10,
        "parry" : 10,
        "damage": 120,
        "lvl" : 20,
        "skill_name" : "÷ѩ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ǧ��ѹ�ա���$w�ƾ�������ˢ��һ�����϶�����$n����",
        "force" : 280,
        "dodge" : -5,
        "parry" : 5,
        "damage": 125,
        "lvl" : 40,
        "skill_name" : "ǧ��ѹ��",
        "damage_type" : "����"
]),
([      "action" : "$N���ַ�ִ������һ�С����ս�ġ�����һ����$wֱ��$n�ľ���նȥ",
        "force" : 300,
        "dodge" : 5,
        "parry" : 5,
        "damage": 130,
        "lvl" : 60,
        "skill_name" : "���ս��",
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С��������ء����������⻯����㷱�ǣ���$n��$l��ȥ",
        "force" : 320,
        "dodge" : 10,
        "parry" : 5,
        "damage": 135,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֺ�ִ$w��һ�С�����֮������š��ת������ֱ����$n��˫��",
        "force" : 340,
        "dodge" : 15,
        "parry" : 15,
        "damage": 140,
        "lvl" : 100,
        "skill_name" : "����֮��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ò����������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
        "force" : 360,
        "dodge" : 15,
        "parry" : 15,
        "damage": 150,
        "lvl" : 120,
        "skill_name" : "���ò��",
        "damage_type" : "����"
]),
([      "action" : "$N��ת�����׼�Լ���һ�С�������֦����ȫ��һ��������$w��$n����նȥ",
        "force" : 380,
        "dodge" : 20,
        "parry" : 10,
        "damage": 160,
        "lvl" : 140,
        "skill_name" : "������֦",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������ס���$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
        "force" : 400,
        "dodge" : 10,
        "parry" : 20,
        "damage": 175,
        "lvl" : 160,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����ƽָ��һ�С��󺣳�ɳ����һƬƬ�йǵ�����쫷�����$n��ȫ��",
        "force" : 420,
        "dodge" : 5,
        "parry" : 25,
        "damage": 190,
        "lvl" : 180,
        "skill_name" : "�󺣳�ɳ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{ 
	return (usage == "blade") || (usage == "parry"); 
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("jinwu-daofa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
		return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("����������������ڵ�����\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������ڵ�����\n");
	me->add("neili", -10);
	me->receive_damage("jingli", 30);
	return 1;
}
