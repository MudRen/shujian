// riyue-bian.c ���±޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([     "action":               "$N����������һ�С�������ּ��������$w���ñ�ֱ����׼$n���ظ�Ҫ����������",
       "dodge":                -10,
       "parry":                5,
       "damage":               100,
       "force":                100,
       "lvl" : 0,
       "skill_name" : "������ּ",
       "damage_type":  "����"
]),
([     "action":               "$N����һת��һ�С���ǰ���¡�������$w��������ڿ�һ���͵���$n��ͷ����",
       "dodge":                -10,
       "parry":                0,
       "damage":               120,
       "force":                150,
       "lvl" : 60,
       "skill_name" : "��ǰ����",
       "damage_type":  "����"
]),
([     "action":               "$N������ң�һ�С���̨��ȥ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
       "dodge":                -20,
       "parry":                -5,
       "damage":               150,
       "force":                200,
       "lvl" : 90,
       "skill_name" : "��̨��ȥ",
       "damage_type":  "����"
]),
([     "action":               "$N�ֱ����Σ�һ�С�ѩ�������������$w�û�������ԲȦ�����ص����ؾ���$n",
       "dodge":                -30,
       "parry":                -10,
       "damage":               180,
       "force":                300,
       "lvl" : 90,
       "skill_name" : "�ƺ�ʽ",
       "damage_type":  "����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
       object weapon;

       if( (int)me->query("max_neili") < 500 )
               return notify_fail("����������㣬û�а취��Ʈ��޷�, ����Щ���������ɡ�\n");

       if ((int)me->query_skill("yijin-jing", 1) < 100)
               return notify_fail("����׽�ڹ����̫ǳ��\n");

       if ( !objectp(weapon = me->query_temp("weapon"))
       || ( string)weapon->query("skill_type") != "whip" )
               return notify_fail("���������һ�����Ӳ������޷���\n");

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
       level   = (int) me->query_skill("piaomiao-bianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "whip")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query_skill("yijin-jing", 1) < 100)
               return notify_fail("����׽�ڹ����̫ǳ��\n");
       if ((int)me->query("jingli") < 50)
               return notify_fail("�������������Ʈ��޷���\n");
       me->receive_damage("jingli", 15);
       return 1;
}
/*
string perform_action_file(string action)
{
               return __DIR__"riyue-bian/" + action;
} 
*/