// liushen-dao.c �������̵�
// By snowman@SJ 25/01/2000

inherit SKILL;

string *action = ({
"$Nʹһʽ�����硹��������$w��Ϊ����һ�㣬������ƮƮ�ظ���$n��$l",
"$Nʹһʽ���ķ硹������$w��Ϊ��籩��һ�㣬��Ȼ����$n��$l",
"$Nʹһʽ����硹����$w�˾�һ��������ƬƬ���⣬����Ҷ��Ʈ��$n��$l",
"$Nʹһʽ�����硹����$wһת���͵�һ��ֱ��$n��$l������ޱȣ����޿ɱ�",
"$Nʹһʽ�����硹�����������$w���е���$n����ͬ��ԭ�书һ�㣬�����ȣ��ᣬ�飬��",
"$Nʹһʽ��Ϧ�硹����$w�ݳ����꽫��ʱ��ָһ�����У�����һ��ת��$n��$l",
"$Nʹһʽ�����硹������$w�й���$n��$lһ�㣬ʵ�ڿ������磬��$n�޴Ӷ��",
"$Nʹһʽ����硹�������趯����$w��Ϊ���Σ����һ������Kamikaze��������$n",
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 100)
               return notify_fail("�������������\n");
       if (! me->query("wizard_agree") )
               return notify_fail("�㲻��ѧϰ��������\n");
       if ((int)me->query_skill("force", 1) < 20)
               return notify_fail("����������̫ǳ��\n");
       return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":action[random(sizeof(action))],
                "damage": me->query_skill("blade")/4+random(100),
                "damage_type": "����",
                "dodge": random(25),
                "parry": 10,
                "force": me->query_skill("force")/2+random(me->query_skill("force")/2),
        ]);
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "blade")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query("jingli") < 30)
               return notify_fail("��ľ����������������̵���\n");
       me->receive_damage("jingli", 20);
       return 1;
}
string perform_action_file(string action)
{
        return __DIR__"renshu/" + action;
}
