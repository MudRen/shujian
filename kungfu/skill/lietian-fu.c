// lietian-fu.c ���츫��

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([     "action" : "$Nƽ������$w��һ�С������𡹣�������ǰ����$n��$l��ȥ",
       "force" : 150,
       "dodge" : 20,
       "damage" : 50,
       "lvl" : 0,
       "skill_name" : "������",
       "damage_type" : "����"
]),
([     "action" : "$Nһ�С�����ɽ������һվ,����$w����$wƽƽ��$n�ľ���Ĩȥ",
       "force" : 200,
       "dodge" : 20,
       "damage" : 30,
       "lvl" : 30,
       "skill_name" : "����ɽ",
       "damage_type" : "����"
]),
([     "action" : "$N��������$wӰ������Ҵ�,һ�С�����ơ��������$n��ȫ��",
       "force" : 250,
       "dodge" : -20,
       "damage" : 50,
       "lvl" : 40,
       "skill_name" : "�����",
       "damage_type" : "����"
]),
([     "action" : "$Nһ�С�����ɽ������ʽ��׾,�󿪴��أ��߾�ͷ��,ֱ����$n",
       "force" : 300,
       "dodge" : 30,
       "damage" : 70,
       "lvl" : 60,
       "skill_name" : "���»���",
       "damage_type" : "����"
]),
([     "action" : "$N����$wһ������������,һ�С�����ء���˫�ֻ���$w����$n���ؿ�",
       "force" : 310,
       "dodge" : -10,
       "damage" : 90,
       "lvl" : 90,
       "skill_name" : "�����",
       "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "axe" || usage == "parry"; }

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 300)
               return notify_fail("�������������\n");
       if (me->query_str() < 30)
               return notify_fail("��ı���̫�͡�\n");
       if ((int)me->query_skill("guiyuan-tunafa", 1) < 20)
               return notify_fail("��ġ���Ԫ���ɷ������̫ǳ��\n");
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
        int i, j, level;
        object target;             
        level   = (int) me->query_skill("lietian-fu",1);
        for(i = sizeof(action); i > 0; i--){
                if(level > action[i-1]["lvl"]){
                  j = NewRandom(i, 20, level/5);
                  target = offensive_target(me);
                  if( me->query_temp("lihun")){ 
                  return ([  
                           "action" : YEL+action[j]["action"]+NOR,
                           "force" : action[j]["force"]+60,
                           "dodge": action[j]["dodge"]+15,
                           "damage": action[j]["damge"]+40,
                           "lvl" : action[j]["lvl"],
                           "parry":action[j]["parry"]+ 20,
                           "weapon" : "����",
                           "damage_type" : random(2)?"����":"����",
                         ]);
                   } 
                return action[j];
                }
        }
}

int practice_skill(object me)
{
       object weapon;
       int lvl = me->query_skill("lietian-fu", 1);
       int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "axe")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query("jingli") < 100)
               return notify_fail("������������������츫������\n");
       me->receive_damage("jingli", 60);
       return 1;
}

string perform_action_file(string action)
{
       return __DIR__"lietian-fu/" + action;
}
