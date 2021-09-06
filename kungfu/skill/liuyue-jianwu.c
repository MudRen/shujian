//liuyue-jianwu.c
// Write By Zhuifeng's System on 2010-7-20 17:22:49

#include <ansi.h>
inherit SKILL;

mapping *action = ({

([
     "action" : "$N��ǰб��һ����һ�С��������������$wֱ��$n�ĺ�",
     "force"  : 100,
     "dodge"  : 10,
     "parry"  : 5,
     "lvl"    : 10,
     "damage"    : 20,
     "skill_name"  : "�������",
     "damage_type" : "����"
]),
([
     "action" : "$N����ǰ��һ�С�����ǧ��������������ޣ�$w��������$n��$l��ȥ",
     "force"  : 125,
     "dodge"  : 20,
     "parry"  : 10,
     "lvl"    : 20,
     "damage"    : 50,
     "skill_name"  : "����ǧ��",
     "damage_type" : "����"
]),
([
     "action" : "$Nһʽ�����б��¡�������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
     "force"  : 150,
     "dodge"  : 15,
     "parry"  : 10,
     "lvl"    : 30,
     "damage"    : 60,
     "skill_name"  : "���б���",
     "damage_type" : "����"
]),
([
     "action" : "$N��������Ծ��һʽ��������⡹��������ˮ��һкǧ�����$nȫ��",
     "force"  : 180,
     "dodge"  : 30,
     "parry"  : 25,
     "lvl"    : 40,
     "damage"    : 90,
     "skill_name"  : "�������",
     "damage_type" : "����"
]),
([
     "action" : "$N����$w�й�ֱ����һʽ������һ�롹��������Ϣ�ض�׼$n��$l�̳�һ��",
     "force"  : 180,
     "dodge"  : 30,
     "parry"  : 25,
     "lvl"    : 40,
     "damage"    : 120,
     "skill_name"  : "����һ��",
     "damage_type" : "����"
]),
([
     "action" : "$N����$wһ����һʽ���ǹ����򡹣�������Ϣ�ػ���$n��$l",
     "force"  : 200,
     "dodge"  : 25,
     "parry"  : 25,
     "lvl"    : 50,
     "damage"    : 125,
     "skill_name"  : "�ǹ�����",
     "damage_type" : "����"
]),
([
     "action" : "$N����$wбָ���죬��â���£�һʽ��ӳ������������׼$n��$lбб����",
     "force"  : 245,
     "dodge"  : 10,
     "parry"  : 15,
     "lvl"    : 70,
     "damage"    : 130,
     "skill_name"  : "ӳ������",
     "damage_type" : "����"
]),
([
     "action" : "$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ���������ȡ�����$n���ʺ�",
     "force"  : 290,
     "dodge"  : 10,
     "parry"  : 15,
     "lvl"    : 80,
     "damage"    : 140,
     "skill_name"  : "��������",
     "damage_type" : "����"
]),
([
     "action" : "$N���Ƶ�����һʽ��Ӱ����ԡ���$w�Ի���Ծ�����缲�������$n���ؿ�",
     "force"  : 331,
     "dodge"  : 20,
     "parry"  : 15,
     "lvl"    : 90,
     "damage"    : 145,
     "skill_name"  : "Ӱ�����",
     "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "parry" || usage == "sword"; }

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 50)
           return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 50)
           return notify_fail("�������������ϰ�ü��ܡ�\n");
       me->receive_damage("jingli", 10);
       me->add("neili", -0);
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
   level   = (int) me->query_skill("liuyue-jianwu",1);
   for(i = sizeof(action); i > 0; i--) {
       if(level > action[i-1]["lvl"]) {
           j = NewRandom(i, 20, level/4);
       if((int)me->query_skill("liuyue-jianwu",1) > 450 ){
       return ([
               "action" : HIW+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIW)+NOR,
               "force" : 120,
               "dodge": 20,
               "parry" : 15,
               "damage" : 30,
               "damage_type" : "����",
                ]);
       }
       else return action[j];
       }
   }
}

string perform_action_file(string action)
{
   return __DIR__"liuyue-jianwu/" + action;
}

