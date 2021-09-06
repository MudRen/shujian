// zhongjia-zhang.c �Ӽ��Ʒ�
// NPC ר��

inherit SKILL;

mapping *action = ({
([     "action" : "$N������ǰ������һ�����գ�˫�����Σ�����ֱ��������$n����������·",
       "force" : 150,
        "dodge" : 5,
       "damage_type" : "����",
       "lvl" : 0,
]),
([     "action" : "$NԾ�����࣬�ڰ����ת����Ȧ�ӣ���ջ��ƣ�����$n����ǰ��Ѩ",
       "force" : 160,
        "dodge" : 5,
        "damage_type" : "����",
       "lvl" : 12,
]),
([     "action" : "$N���ۻ��˸����ߣ���ͷ������ն��$n��$l",
       "force" : 170,
        "dodge" : 5,
        "damage_type" : "����",
       "lvl" : 18,
]),
([     "action" : "$N���ƻ��أ������罣�����ֺ������쬷��죬�͵�����$n��$l",
       "force" : 185,
        "dodge" : -5,
        "damage_type" : "����",
       "lvl" : 24,
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("���Ӽ��Ʒ�������֡�\n");
       if ((int)me->query_skill("jinglei-gong", 1) < 20)
               return notify_fail("��ľ��׹���򲻹����޷�ѧ�Ӽ��Ʒ���\n");
       if ((int)me->query("max_neili") < 100)
               return notify_fail("�������̫�����޷����Ӽ��Ʒ���\n");
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
       level = (int)me->query_skill("zhongjia-zhang", 1);
       for(i = sizeof(action); i > 0; i--)
               if(level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("��ľ���̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("��������������Ӽ��Ʒ���\n");
       me->receive_damage("jingli", 25);
       me->add("neili", -5);
       return 1;
}
