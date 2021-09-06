// lingshe-bianfa ���߱޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([     "action":   "$N���β�����һ�С��������项������$wֱ��$n��˫Ŀ��ȥ",
       "dodge":        10,
       "parry":        20,
       "damage":       20,
       "force":        80,
       "lvl" : 0,
       "skill_name" : "��������",
       "damage_type":  "����"
]),
([     "action":   "$Nһ�С��������������$w��Ӱ���Σ���$n�ľ�����ȥ",
       "dodge":     15,
       "parry":     20,
       "damage":    30,
       "force":     100,
       "lvl" : 20,
       "skill_name" : "��������",
       "damage_type":  "����"
]),
([     "action":   "$NͻȻ������ˣ���$n�Ƚ�ʱ������һ�С�������β��������$w������֮����ֱ��$n��ǰ�ض�ȥ",
       "dodge":     10,
       "parry":     12,
       "damage":    50,
       "force":     120,
       "lvl" : 40,
       "skill_name" : "������β",
       "damage_type":  "����"
]),
([     "action":   "$N�͵�һ��������$w��������Բ����һ�С�������������Ȧ��$n������",
       "dodge":     12,
       "parry":     20,
       "damage":    60,
       "force":     140,
       "lvl" : 60,
       "skill_name" : "��������",
       "damage_type":  "����"
]),
([     "action":  "$N���ΰ���������ң�һ�С������·���������$w�γ�������Ӱ����$nӭͷ����",
       "dodge":    15,
       "parry":    20,
       "damage":   80,
       "force":    160,
       "lvl" : 80,
       "skill_name" : "�����·�",
       "damage_type":  "����"
]),
([     "action":  "$N���ؾ͵�һ����һ�С����������������$w��Ѹ�ײ����ڶ�֮��ɨ��$n��˫��",
       "dodge":    20,
       "parry":    20,
       "damage":   80,
       "force":    180,
       "lvl" : 100,
       "skill_name" : "�������",
       "damage_type":  "����"
]),
([     "action": "$N���η��ͣ�һ�С������鳲��������$w����������Ӱ����׼$n������ȥ",
       "dodge":   20,
       "parry":   30,
       "damage":   90,
       "force":   200,
       "lvl" : 120,
       "skill_name" : "�����鳲",
       "damage_type":  "����"
]),
([     "action": "$N�͵ض�ֱ���е�$w��һ�С�����������������$n�ĽŸ�ֱ�ö��ϣ�ֱ��$n��ͷ����ȥ",
       "dodge":   25,
       "parry":   30,
       "damage":  90,
       "force":   210,
       "lvl" : 120,
       "skill_name" : "��������",
       "damage_type":  "����"
])
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int valid_learn(object me)
{
       object weapon;

       if( (int)me->query("max_neili") < 100 )
               return notify_fail("����������㣬û�а취�����߱޷�, ����Щ���������ɡ�\n");
       if ((int)me->query_skill("dulong-dafa", 1) < 30)
               return notify_fail("��Ķ����󷨻��̫ǳ��\n");
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
       level   = (int) me->query_skill("lingshe-bianfa",1);
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
       if ((int)me->query_skill("dulong-dafa", 1) < 30)
               return notify_fail("��Ķ����󷨻��̫ǳ��\n");
       if ((int)me->query("jingli") < 50)
               return notify_fail("����������������߱޷���\n");
       me->receive_damage("jingli", 15);
       return 1;
}

string perform_action_file(string action)
{
       return __DIR__"lingshe-bianfa/" + action;
}
