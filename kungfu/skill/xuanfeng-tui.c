// ����ɨҶ��
// Modified by Darken@SJ
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N������ǰ����Ȼ������ȣ�һʽ�������߶�����ֱ��$n��ͷ��",
        "force" : 150,
        "dodge" : -2,
        "parry" : -2,
        "lvl" : 0,
        "skill_name" : "�����߶�",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�����Ѵ�$n����ӹ������㷴�ߣ�����һ�С������Ͻ�ڡ�������$n�ı���",
        "force" : 200,
        "dodge" : -1,
        "parry" : 2,
        "lvl" : 8,
        "skill_name" : "�����Ͻ��",
        "damage_type" : "����"
]),
([      "action" : "$N�����ף����㻭������Բ��ʹ�������ò������ɨ��$n��ϥ��",
        "force" : 250,
        "dodge" : 5,
        "parry" : 2,
        "lvl" : 18,
        "skill_name" : "���ò��",
        "damage_type" : "����"
]),
([      "action" : "$N����΢�࣬����ٿ�ص������������ȣ�����$n��ͷ�����ز����ɲ������ǡ��������ߡ�",
        "force" : 300,
        "dodge" : -4,
        "parry" : 6,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N������������������η�ת��ɨ�������������������ɨ��ǰ��һ�С����ɨ��Ҷ��������$n��$l",
        "force" : 350,
        "dodge" : 5,
        "parry" : 4,
        "lvl" : 50,
        "skill_name" : "���ɨ��Ҷ",
        "damage_type" : "����"
]),
([      "action" : "$NԾ���ڰ�գ�˫�����裬�����������磬��������졹��Ѹ�����׵ؾ���$n",
        "force" : 400,
        "dodge" : -5,
        "parry" : 10,
        "lvl" : 80,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }
 int valid_combine(string combo) { return combo=="luoying-zhang"; } 
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ѧ����ɨҶ��ʱ���ﲻ����������\n");
        if (me->query("max_neili") >= 1000) return 1;
        if ((int)me->query_skill("bihai-chaosheng", 1) < 30)
                return notify_fail("��ı̺���������򲻹����޷�ѧ����ɨҶ�ȡ�\n");
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
                return notify_fail("��ϰ����ɨҶ�ȱ����б̺���������ϡ�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�������ɨҶ�ȡ�\n");
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
        int i, j, level, adjust;
        level = (int)me->query_skill("xuanfeng-tui",1) + (int)me->query_skill("luoying-zhang",1);
        adjust = level/5;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level > action[i-1]["lvl"]) {
                    j = NewRandom(i, 20, level/5);
                    if (me->query_perform() == "������")
                        return ([  
                        "action" : HIG+action[j]["action"]+NOR,
                        "force" : action[j]["force"] + adjust,
                        "dodge" : action[j]["dodge"] + adjust,
                        "damage" : action[j]["damage"] + adjust,
                        "damage_type" : action[j]["damage_type"],
                        ]);
                    else
                        return ([  
                        "action" : action[j]["action"],
                        "force" : action[j]["force"],
                        "dodge" : action[j]["dodge"] + adjust/2,
                        "damage" : action[j]["damage"],
                        "damage_type" : action[j]["damage_type"],
                        ]);
                }
}

int practice_skill(object me)
{
        int lvl = me->query_skill("xuanfeng-tui", 1);
        int i = sizeof(action);
        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["xuanfeng-tui"])
                while (i--) 
                        if (lvl == action[i]["lvl"])
                                return notify_fail("�㽫�Ѿ�ѧ���������ʽ��ϰ��һ�飬���������ȥ��ʦ��ѧ�µ���ʽ���޷���ý����ˡ�\n");;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ɨҶ��ʱ���ﲻ����������\n");
        if ((int)me->query("jingli") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�����������������ɨҶ�ȡ�\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
      return __DIR__"xuanfeng-tui/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl = me->query_skill("leg");
        if ((random(lvl) > 100 && random(me->query_dex()) > victim->query_dex()/2 ||
             random(me->query_temp("thd/is_fast")) > 200) && victim->query("jiali")) {
                victim->set("jiali",0);
                victim->add("neili", -lvl);
                message_vision(HIR"$n��$N��һ�ȵ����е��������ɢ��\n"NOR,me, victim);
        }
}
