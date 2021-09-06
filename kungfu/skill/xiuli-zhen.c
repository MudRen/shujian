// ������Ů��
// Created by snowman@SJ 28/02/2001

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ������$w����һʽ�����ɴ��̡���ȥ����ӹ��ƽָ����$n��ֻ��һ�б㽫�����书�еġ��ȡ����ӵ����쾡��",
        "force" : 160,
        "dodge" : 20,
        "parry" : 5,
        "damage" : 25,
        "lvl" : 0,
        "skill_name" : "���ɴ���",
        "damage_type" : "����"
]),
([      "action" : "$N������������$w���ֻγ�������һʽ����ɽ���衹����ͬ����ɽ�ϵ��������ɣ������ɨ��$n",
        "force" : 220,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 30,
        "lvl" : 20,
        "skill_name" : "��ɽ����",
        "damage_type" : "����"
]),
([      "action" : "$N������$wбָ���죬��Ц��һʽ��ǧ�徺�㡹��������������⣬���������������ֱ��$n��ȥ",
        "force" : 240,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 40,
        "lvl" : 40,
        "skill_name" : "ǧ�徺��",
        "damage_type" : "����"
]),
([      "action" : "$N�ƺ�һ����һ�С����Ʋ�ϼ������$w���»��裬��Ӱ������һƬƬ������ϼ�⣬��$n����",
        "force" : 260,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 50,
        "lvl" : 60,
        "skill_name" : "���Ʋ�ϼ",
        "damage_type" : "����"
]),
([      "action" : "$N����š����$w������ߣ���������һʽ��������Ȫ����ϼ��������������ˮֱ�䣬����$n��ҪѨ",
        "force" : 280,
        "parry" : 15,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 80,
        "skill_name" : "������Ȫ",
        "damage_type" : "����"
]),
([      "action" : "$N��$wһ˦������������$n��ǰ����һ��������Ľ���������ž�ʢ�������Ƕ�ü�������еġ�ɽ��ŭ�š�",
        "force" : 300,
        "dodge" : 10,
        "parry" : 20,
        "damage" : 75,
        "lvl" : 100,
        "skill_name" : "ɽ��ŭ��",
        "damage_type" : "����"
]),
([      "action" : "$Nʩչ�����š���ˮ���衹���������������֣�������������Ĳʵ��������������·�������$w������ʴ�",
        "force" : 320,
        "dodge" : 5,
        "parry" : 15,
    	"damage" : 90,
        "lvl" : 120,
        "skill_name" : "��ˮ����",
        "damage_type" : "����"
]),
([      "action" : "$N��Хһ����һʽ��������ü���ڿշ����ڰ�ջ�����һ���»���ѩ���Ĺ�â�ɳ�����ҫ��ʣ�",
        "force" : 340,
        "dodge" : 10,
        "parry" : 15,
    	"damage" : 120,
        "lvl" : 150,
        "skill_name" : "������ü",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
                
        if ((int)me->query_skill("qingdai-shengang", 1) < 20)
                return notify_fail("�����������̫ǳ��\n");
        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        return 1;
}


mapping query_action(object me,object target)
{
        int i, level;
        level   = (int) me->query_skill("xiuli-zhen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("��ʹ�õ��������ԡ�\n");

       	if ((int)me->query("jingli") < 40)
                return notify_fail("�������������������Ů�롣\n");
        me->receive_damage("jingli", 30);
        if ((int)me->query("neili") < 20)
                return notify_fail("�������������������Ů�롣\n");
        me->receive_damage("jingli", 5);
        
        return 1;
}
           

string perform_action_file(string action)
{        
	return __DIR__"xiuli-zhen/" + action;
}
