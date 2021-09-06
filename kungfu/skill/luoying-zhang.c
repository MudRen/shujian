// ��Ӣ����
// Modified by Darken@SJ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N������ǰ������һ�����գ�˫�����Σ�������$n����ǰ��ʹ������Ӣ�ͷס�������ʵʵ���������޵�Ϯ��$n",
        "force" : 100,
        "dodge" : 30,
        "parry" : -2,
        "lvl" : 0,
        "skill_name" : "��Ӣ�ͷ�",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�㣬Ծ�����࣬�ڰ����ת����Ȧ�ӣ���ջ��ƣ��������Σ�һ�С����Ƿɻ�������$n��ͷ����",
        "force" : 150,
        "dodge" : -1,
        "parry" : 5,
        "lvl" : 7,
        "skill_name" : "���Ƿɻ�",
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ�������ں󣬵��ۻ��˸����ߣ����ǡ�����һ�������ͷ��������$n��ȥ",
        "force" : 200,
        "dodge" : 5,
        "parry" : 2,
        "lvl" : 15,
        "skill_name" : "����һ�",
        "damage_type" : "����"
]),
([      "action" : "$N����һת���Ѿ��۵�$n��ǰ�������罣�����ֺ������쬷��죬һ�С��꼱��񡹻���$n��$l",
        "force" : 250,
        "dodge" : -5,
        "parry" : 6,
        "lvl" : 28,
        "skill_name" : "�꼱���",
        "damage_type" : "����"
]),
([      "action" : "$N�������Σ�ٿ������Χ��$nת�˼���Ȧ�ӣ���ӰƮƮ������һ�С��ޱ���ľ����������˷���$nϮȥ",
        "force" : 300,
        "dodge" : 8,
        "parry" : 5,
        "lvl" : 45,
        "skill_name" : "�ޱ���ľ",
        "damage_type" : "����"
]),
([      "action" : "$N��Цһ����̤��һ����˫�����������ж��ʵ���٣���ʱ���������컨�꡹����$n��ȫ����������Ӱ֮��",
        "force" : 350,
        "dodge" : -2,
        "parry" : 10,
        "damage" : 35,
        "lvl" : 60,
        "skill_name" : "���컨��",
        "damage_type" : "����"
]),
([      "action" : "$N�����˾�������˫�ۣ������罣������$n������һǰһ��ʹ��һ�С����޲к졹���ݺݵذ���$n��ǰ��",
        "force" : 400,
        "dodge" : -8,
        "parry" : 8,
        "lvl" : 80,
        "skill_name" : "���޲к�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

 int valid_combine(string combo) { return combo=="xuanfeng-tui"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ѧ��Ӣ���Ʊ�����֡�\n");
        if (me->query("max_neili") >= 1000) return 1;
        if ((int)me->query_skill("bihai-chaosheng", 1) < 20)
                return notify_fail("��ı̺���������򲻹����޷�ѧ��Ӣ���ơ�\n");
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
                return notify_fail("��ϰ��Ӣ���Ʊ����б̺���������ϡ�\n");
        if ((int)me->query("max_neili") < 80)
                return notify_fail("�������̫�����޷�����Ӣ���ơ�\n");
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
        level = (int) me->query_skill("luoying-zhang",1) + (int) me->query_skill("xuanfeng-tui",1);
        adjust = level/5;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level > action[i-1]["lvl"]) {
                    j = NewRandom(i, 20, level/5);
                    if (me->query_perform() == "������")
                        return ([  
                        "action" : HIM+action[j]["action"]+NOR,
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
        int lvl = me->query_skill("luoying-zhang", 1);
        int i = sizeof(action);
        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["luoying-zhang"])
                while (i--) 
                        if (lvl == action[i]["lvl"])
                                return notify_fail("�㽫�Ѿ�ѧ���������ʽ��ϰ��һ�飬���������ȥ��ʦ��ѧ�µ���ʽ���޷���ý����ˡ�\n");;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ӣ���Ʊ�����֡�\n");
        if ((int)me->query("jingli") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("���������������Ӣ���ơ�\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
      return __DIR__"luoying-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl = me->query_skill("strike");
        if ((random(lvl) > 100 && random(me->query_dex()) > victim->query_dex()/2 ||
             random(me->query_temp("thd/is_fast")) > 200) && !victim->query_temp("must_be_hit")) {
                victim->set_temp("must_be_hit", 1);
                call_out("remove_effect", 2+random(3), victim);
                message_vision(HIR"$n��$N��������Ū����ͷת�򣬸����ֲ�������Ϊʵ������Ϊ�飡\n"NOR, me, victim);
        }
}

void remove_effect(object victim)
{
        if (!victim) return;
        victim->delete_temp("must_be_hit", 1);
}

