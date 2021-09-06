// youming-zhao.c ��ڤ��צ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([     "action" : "$N��צǰ�죬����˿˿����������һʽ"RED"��Ԫ����ϡ�"NOR"���͵���$n�Ķ��Ų���",
       "force" : 150,
       "damage" : 30,
       "dodge" : 5,
       "lvl" : 0,
       "weapon" : "��ָ",
       "damage_type" : "ץ��"
]),
([     "action" : "$N˫�����ģ�����һ����ǽ����$n����Ȼһצ"RED"�����ȴ��ġ�"NOR"������ǽֱ��$n��$l",
       "force" : 160,
       "dodge" : 10,
       "damage": 30,
       "lvl" : 0,
       "weapon" : "ָ��",
       "damage_type" : "����"
]),
([     "action" : "$Nʹ��"RED"��Ѫ������"NOR"˫צ����$n��ס$l��������������������һ������Ҫ��$n�����Ƭ",
       "force" : 170,
       "dodge" : 0,
       "damage": 40,
       "lvl" : 20,
       "weapon" : "ָ��",
       "damage_type" : "����"
]),
([     "action" : "$N˫צ£ס$n��ʹһʽ"BLU"����������"NOR"�������ڹ���צ��͸��$n���ڣ�ֱϮ����ؽ�",
       "force" : 180,
       "dodge" : 5,
       "damage": 60,
       "lvl" : 30,
       "damage_type" : "����"
]),
([     "action" : "$N��͸ָ�⣬��$n����ʵʵ��ץʮ��צ��"BLU"������Ϯ�塹"NOR"��������������ס$n",
       "force" : 200,
       "dodge" : 15,
       "damage": 60,
       "weapon" : "����",
       "lvl" : 40,
       "damage_type" : "����"
]),
([     "action" : "$Nһʽ"RED"���������֡�"NOR"����צ���·����γ�����צӰ���ұ�һ�죬���Ȱ�ץ��$n��$l",
       "force" : 260,
       "dodge" : 5,
       "damage": 70,
       "weapon" : "��ץ",
       "lvl" : 50,
       "damage_type" : "ץ��"
]),
([     "action" : "$N̽����ǰ��˳��$n���ֱ���Եֱ�ϣ�����Ϊצ��һ��"RED"���»�Ԧħ��"NOR"ץ��$n��$l",
       "force" : 300,
       "dodge" : 5,
       "damage": 70,
       "lvl" : 70,
       "weapon" : "��צ",
       "damage_type" : "ץ��"
]),
([     "action" : "$N��շ��䣬һצͻǰ��"BLU"��ħצ���¡�"NOR"����ȫ������ָ�⣬����ޱȵز���$n",
       "force" : 350,
       "dodge" : 10,
       "damage": 80,
       "lvl" : 90,
       "weapon" : "��צ",
       "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("��צ��������֡�\n");
       if ((int)me->query_skill("claw", 1) < 50)
               return notify_fail("��Ļ���צ����򲻹����޷�ѧϰ��\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("�������̫�����޷�����צ����\n");
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
       level   = (int) me->query_skill("youming-zhao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("���������������ڤ��צ��\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"youming-zhao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   if(me->query_temp("��ڤ") && !me->query_temp("youming_hit")) {
        me->set_temp("youming_hit", 1);
        me->set_temp("apply/name", ({ me->query("name")+"��"HIB"���"NOR }));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);       
        me->delete_temp("apply/name");
        me->delete_temp("youming_hit");
        }
}

