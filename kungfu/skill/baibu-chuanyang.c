//baibu-chuanyang.c
// Write By Zhuifeng's System on 2010-8-8 13:45:51

#include <ansi.h>
inherit SKILL;

mapping *action = ({

([
     "action" : "$N�������У���������������ֻ������$w�ϣ�ʹ�������������ȫ�������",
     "force"  : 5,
     "dodge"  : 5,
     "parry"  : 20,
     "lvl"    : 10,
     "damage"    : 120,
     "skill_name"  : "�����",
     "damage_type" : "����"
]),
([
     "action" : "$N��ס��Ϣ�������乭�����ʹ�������Ǽ���������������$n����ʱ$n�������",
     "force"  : 50,
     "dodge"  : 15,
     "parry"  : 5,
     "lvl"    : 20,
     "damage"    : 100,
     "skill_name"  : "���Ǽ�",
     "damage_type" : "����"
]),
([
     "action" : "$N��ȫ��֮����ע�ڹ���֮�ϣ�����ʹ���������䡹��һ֧�������ӥ���ٷ���$n",
     "force"  : 20,
     "dodge"  : 5,
     "parry"  : 10,
     "lvl"    : 30,
     "damage"    : 130,
     "skill_name"  : "������",
     "damage_type" : "����"
]),
([
     "action" : "$N�乭�����ʹ��������������ԯ����ꪡ�ԯ���䡹�����������ֵ�Ұ�������$n����",
     "force"  : 20,
     "dodge"  : 20,
     "parry"  : 20,
     "lvl"    : 40,
     "damage"    : 90,
     "skill_name"  : "ԯ����",
     "damage_type" : "����"
]),
([
     "action" : "$N�乭�������������ע��$w֮�У�ʹ���������������ʸͻȻ�������;����һ����������������$n",
     "force"  : 20,
     "dodge"  : 20,
     "parry"  : 20,
     "lvl"    : 50,
     "damage"    : 90,
     "skill_name"  : "�����",
     "damage_type" : "����"
]),
([
     "action" : "$N�乭�����ʹ���ƺ�����ɳս�Ƴ���������ӧ�䡹����ʸ��Ծ���գ����ٷ���$n������",
     "force"  : 50,
     "dodge"  : 20,
     "parry"  : 20,
     "lvl"    : 60,
     "damage"    : 120,
     "skill_name"  : "��ӧ��",
     "damage_type" : "����"
]),
([
     "action" : "$N�乭�����ʹ�����岽�䡹���������߱��䣬�岽֮�ھ���$n������������������$nҪ��֮��",
     "force"  : 50,
     "dodge"  : 20,
     "parry"  : 20,
     "lvl"    : 70,
     "damage"    : 110,
     "skill_name"  : "�岽��",
     "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "arrow" ||  usage=="parry"; ; }

int practice_skill(object me)
{

       if ((int)me->query_skill("arrow") < 30)
           return notify_fail("��ļ�������̫���ˣ��޷���ϰ�ٲ����\n");

       if ((int)me->query("jingli") < 50)
           return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 50)
           return notify_fail("��������������޷���ϰ�ٲ����\��\n");
       me->receive_damage("jingli", 10);
       me->add("neili", -10);
       return 1;
}
string query_skill_name(int level)
{
   int i;
   for(i = sizeof(action); i > 0; i--)
       if(level >= action[i-1]["lvl"])
           return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
   int i, j, level;
   level   = (int) me->query_skill("baibu-chuanyang",1);
   for(i = sizeof(action); i > 0; i--) {
       if(level > action[i-1]["lvl"]) {
           j = NewRandom(i, 20, level/4);
       if((int)me->query_skill("baibu-chuanyang",1) > 350 ){
       return ([
               "action" : HIC+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC)+NOR,
               "force" : 500,
               "dodge": 30,
               "parry" : 50,
               "damage" : 140,
               "damage_type" : "����",
                ]);
       }
       else return action[j];
       }
   }
}

string perform_action_file(string action)
{
   return __DIR__"baibu-chuanyang/" + action;
}

