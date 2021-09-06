// emei-ci.c ���Ҵ�
// created by Godhelpu 2001-02-07

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
        "action" : "$N���µ��������������鰴��һ�С��ļ��ӱʡ�������$wֱ��$n��$l",
        "force" : 80,
        "dodge" : 20,   
        "damage" : 70,
        "lvl" : 0,
        "skill_name" : "�ļ��ӱ�",
        "damage_type" : "����"
]),
([
        "action" : "$N��¶΢Ц����̬��ͣ�һ�С�����ϴ�桹��˫�ֻ�����Բ���������̲��ż�Ϊ������ɱ��",
        "force" : 100,
        "dodge" : 5,
        "parry" : 60,
        "damage" : 75,
        "lvl" : 20,
        "skill_name" : "����ϴ��",
        "damage_type" : "����"
]),
([
        "action" : "$N�����𴦣�$wһʽ���ֻ����������������Ӱ���������ƿ���һ�ƾ�â��ֱ��$n",
        "force" : 130,
        "dodge" : 25,   
        "damage" : 90,
        "lvl" : 40,
        "skill_name" : "�ֻ�����",
        "damage_type" : "����"
]),
([
        "action" : "ֻ�����͡���һ����$N�������$n�Ľ���������$w��Ϊ������ɽ١�����ȡ$n��$l",
        "force" : 200,
        "dodge" : -20,
        "damage" : 110,
        "lvl" : 60,
        "skill_name" : "����ɽ�",
        "damage_type" : "����"
]),
([
        "action" : "$N����һ�ϣ�����$n��࣬���ν����У�$wһ�С����Χ����������$nǰ�Һ�������λ",
        "force" : 145,
        "dodge" : 40,   
        "damage" : 120,
        "lvl" : 80,
        "skill_name" : "���Χ��",
        "damage_type" : "����"
]),
([
        "action" : "$N���ΰ�ת��ͻȻ�������񣬵���ʯ�������$n�������У�����һʽ����Ů������",
        "force" : 180,
        "dodge" : 50,   
        "damage" : 145,
        "lvl" : 100,
        "skill_name" : "��Ů����",
        "damage_type" : "����"
]),
([
        "action" : "$N΢һ����$wͻ�����֣�һ�С�ԽŮ׷�꡹�����ּ��̣�$n΢һ��㵼䣬����������ǰ",
        "force" : 240,
        "dodge" : 65,   
        "damage" : 170,
        "lvl": 120,
        "skill_name" : "ԽŮ׷��",
        "damage_type" : "����"
]),
([
        "action" : "$Nһ����Х��б�ж�ǰ��$w����ֱ����Ѹ���ޱȣ��׹���˸�У�����$n��������",
        "force" : 280,
        "dodge" : 70,   
        "damage" : 200,
        "lvl" : 150,
        "skill_name" : "���Ǿۻ�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) 
{
    return usage == "dagger" || usage == "parry" || usage == "dodge"; 
}

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 2000)
               return notify_fail("���������Ϊ������\n");
       if ((int)me->query_skill("linji-zhuang", 1) < 150)
               return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
       if ((int)me->query_skill("parry", 1) < 150)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
       if ((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("��Ļ����Ṧ���̫ǳ��\n");
       return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}

mapping query_action(object me,object target)
{
        int i, level;
        level = (int) me->query_skill("emei-ci",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 15, level/4)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
        object weapon = me->query_temp("weapon");

        if (!weapon) return;
        if ((string)weapon->query("id")!="emei ci" && (string)weapon->query("id")!="yunv zan") return;
        if (random(me->query_str())>victim->query_con()/2)
                victim->receive_wound("qi", victim->query("max_qi")/100+random(100));
}

int practice_skill(object me)
{
        object weapon;
        weapon = me->query_temp("weapon");
        
        if ( !objectp(weapon) || (string)weapon->query("skill_type") != "dagger" )
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50) return notify_fail("��ľ���������\n");
        if ((int)me->query("neili") < 20) return notify_fail("�������������\n");
        me->receive_damage("jingli", 30);
        me->receive_damage("neili", 10);
        return 1;
}

int double_attack(object me)
{       
        if ( me->query_skill("emei-ci", 1) >= 100
        && me->query_skill_mapped("dagger") == "emei-ci"
        && me->query("class") == "bonze" && me->query("gender") == "Ů��"
        && me->query("family/family_name") == "������" )
                return 1;
}

string perform_action_file(string action)
{
        return __DIR__"emei-ci/" + action;
}

int help(object me)
{
        write(WHT"\n���Ҵ̣�"NOR"\n\n");
        write(@HELP        
�书���ƣ�
        ���Ҵ�(emei-ci)
        
Ҫ��
        ������� 2000;
        �ټ�ʮ��ׯ 150��;
        �����Ṧ 150��;
        �����м� 150��;

���⹥����
        �к����(Perform canhong)��

HELP
        );
        return 1;
}
