#include <ansi.h>
inherit SKILL;
string  *msg = ({
"ͻȻ$Nһ�����ȣ���â������$w���ǰ�ɳ������Ŵ̶���Х֮����ֱ��$n��$l",
"$N˫�����ӣ�$N���е����������������Ϸ�����������ö$w����������缲�磬�����꣬��������",
"$N����$wͻȻ�����������⼱�ɶ�����$nֻ����ǰһ������ö$wȴ������Ϣ�Ӻ�Ϯ��",
"$N������ö$w���������η�������ջ�������ɢ��������$n�޴Ӷ��",
"�����$N˫��һ��һ�������ż�������������������������������$n����",
});

int valid_enable(string usage)
{
        return usage == "throwing";
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(3)+1)*60,
                "damage_type":random(2)?"����":"����",
                "dodge":random(10)+10,
                "force":random(200)+100,
                "post_action":
                  (: call_other, WEAPON_D, "throw_weapon" :)
                ]);
}
int practice_skill(object me)
{
       object weapon;
       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("id") != "jinshe zhui")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query_skill("jinshe-zhuifa", 1) < 100)
           return notify_fail("������ֻ��ͨ����ϰ�������ؼ�������ߡ�\n");
       
       
       if ((int)me->query("jingli") < 50)
               return notify_fail("�����������������׶����\n");
       me->receive_damage("jingli", 30);
       return 1;
}

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 500)
                return notify_fail("�������������\n");
       if ((int)me->query_skill("throwing", 1) < 100)
                return notify_fail("��Ļ�����̫ǳ��\n");
       return 1;

}
string perform_action_file(string action)
{
       return __DIR__"jinshe-zhuifa/" + action;
}

