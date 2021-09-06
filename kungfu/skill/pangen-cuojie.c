// pangen-cuojie.c 

inherit SKILL;

mapping *action = ({
([      "action" : "$N�߾�����$w��һʽ������֦����������ǰ����$n��$l��ȥ",
        "force" : 160,
        "dodge" : 5,
        "damage" : 10,
        "lvl" : 0,
        "skill_name" : "����֦",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�������������������ף��綨������$w������$n��$l��ȥ",
        "force" : 200,
        "dodge" : 10,
        "damage" : 20,
        "lvl" : 30,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$N�Ӷ�$w�����������츫Ӱ��һʽ�����ҽڡ��������ʱ����$n��ȫ��",
        "force" : 240,
        "dodge" : -15,
        "damage" : 40,
        "lvl" : 60,
        "skill_name" : "���ҽ�",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��ʮ�˿���������$w������������ֱ����$n��С��",
        "force" : 280,
        "dodge" : -10,
        "damage" : 60,
        "lvl" : 90,
        "skill_name" : "ʮ�˿�",
        "damage_type" : "����"
]),
([      "action" : "$N��������һת��һʽ���̸���ڡ���˫�ֻ���$w����$n��$l",
        "force" : 300,
        "dodge" : -10,
        "damage" : 80,
        "lvl" : 120,
        "skill_name" : "�̸����",
        "damage_type" : "����"
]),
});


int valid_enable(string usage)
{
    return usage == "axe" || usage == "parry"; 
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 150)
                return notify_fail("�������������\n");
       if (me->query_str() < 25)
                return notify_fail("��ı���̫�͡�\n");
        if ((int)me->query_skill("qiantian-yiyang", 1) < 30)
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
        level   = (int) me->query_skill("pangen-cuojie",1);
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
        if ((int)me->query("jingli") < 50)
                return notify_fail("�������������ϰ���̸���ڸ�����\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("�������������ϰ���̸���ڸ�����\n");
        me->receive_damage("jingli", 30);        
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pangen-cuojie/" + action;
}
