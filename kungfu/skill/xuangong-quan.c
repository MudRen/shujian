// xuangong-quan.c �޼�����ȭ

inherit SKILL;

mapping *action = ({
([      "action" : "$N���һ������ȭ����һ�С��ͼ���������ͷ�������$n��$l��", 
        "force" : 200,
        "dodge" : 10,
        "lvl" : 0,
        "skill_name" : "�ͼ�����",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ�С����ɳ²֡���˫�Ų���������һ�ã��������磬���ּ�̽������$n�ġ�����Ѩ��",
        "force" : 280,
        "dodge" : 15,
        "lvl" : 20,
        "skill_name" : "���ɳ²�",
        "damage_type" : "����"
]),
([      "action" : "$N������������ȭ���ƣ��ϱ�һ����ͻȻ���С��ջ���ӥ�������¶��ϵĴ���$n��$l",
        "force" : 330,
        "dodge" : 20,
        "lvl" : 40,
        "skill_name" : "�ջ���ӥ",
        "damage_type" : "����"
]),
([      "action" : "$Nٿ���ڿ�Ծ�𣬽�������֮�ƣ�����һȭ���漴��ȭΪ�֣�ץ��$n��$l,��һ�С������ܺ",
        "force" : 380,
        "dodge" : 15,
        "lvl" : 60,
        "skill_name" : "�����ܺ�",
        "damage_type" : "ץ��"
]),
([      "action" : "$Nʩ�����ɽ�ն���������ַ�����$n�ֱ��ϰ��䣬��ȭ�þ���ƽ֮�����϶����ͻ�$n�ұ�����",
        "force" : 420,
        "dodge" : 10,
        "lvl" : 50,
        "skill_name" : "�ɽ�ն��",
        "damage_type" : "����"
]),
([      "action" : "$N���¡����Ը�󸡹��һ�����䣬Ծ��$n��ǰ��һ����֦���沽��˫ȭ���ֱޡ�����$n��$l",
        "force" : 480,
        "dodge" : 20,
        "lvl" : 60,
        "skill_name" : "���Ը��",
        "damage_type" : "����"
])

});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="zhenshan-mianzhang"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���޼�����ȭ������֡�\n");
        if ((int)me->query_skill("yinyun-ziqi", 1) < 80)
                return notify_fail("�����������򲻹����޷�ѧϰ�޼�����ȭ��\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������̫�����޷����޼�����ȭ��\n");
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
        int i, level;
        level = (int)me->query_skill("xuangong-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������޼�����ȭ��\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuangong-quan/" + action;
}