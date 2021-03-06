// kuangfeng.c  狂风绝技
// Modified by Darken@SJ

#include <ansi.h>
inherit F_SSERVER;

string perform_name() { return HIG"狂风绝技"NOR; }

int perform(object me, object target)
{
        int lvl;

        if( !target ) target = offensive_target(me);
        if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("狂风绝技只能对战斗中的对手使用。\n");
        if (!(me->query("thd/perform") & 4))
                return notify_fail("你虽然听说过“狂风绝技”是桃花岛看门神技，可是却未获黄岛主传授。\n");
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("你必须空手使用「狂风绝技」！\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 100 )
                return notify_fail("你的落英神剑掌不够娴熟，无法施展出狂风绝技。\n");
        if( (int)me->query_skill("xuanfeng-tui", 1) < 100 )
                return notify_fail("你的旋风扫叶腿不够娴熟，无法施展出狂风绝技。\n");
        if ((int)me->query_skill("bihai-chaosheng", 1) < 100)
                return notify_fail("你的碧海潮生功火候不够，无法施展出狂风绝技。\n");
        if ( (int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够，无法施展出狂风绝技。\n");
        if ( (int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法施展出狂风绝技。\n");
        if (me->query_skill_prepared("leg") != "xuanfeng-tui"
            || me->query_skill_mapped("leg") != "xuanfeng-tui"
            || me->query_skill_mapped("strike") != "luoying-zhang" )
                return notify_fail("你现在无法使用狂风绝技进行攻击！\n");
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
                return notify_fail("你的碧海潮生功修为不够，无法使用狂风绝技进行攻击！\n");

        if (me->query_temp("thd/is_fast")) lvl += 100;
            me->start_perform(6, "狂风绝技");
        lvl = (me->query_skill("xuanfeng-tui",1) + me->query_skill("luoying-zhang",1) )/2;
        message_vision(HBGRN "$N一声清啸，拳脚齐施，使出桃花「狂风绝技」迅捷无伦地攻向$n！\n"NOR,me, target);
        call_out("kuangfeng_attack", 1, me, target, "leg", lvl);
        return 1;
}

void kuangfeng_attack(object me, object target, string skill, int lvl)
{
        int i;
        if (!me)
return;
    if(me)
        me->receive_damage("neili", 100+random(100));
        if (!me || !target || !me->is_fighting(target) || lvl <= 0 || me->query("neili") <= 0) {
                message_vision(HIG"$N身形渐缓，停止了狂风绝技。\n"NOR, me);
                me->prepare_skill("strike","luoying-zhang");
                me->prepare_skill("leg", "xuanfeng-tui");
                return;
        } else {
                if (skill == "strike") {
                        me->prepare_skill("leg");
                        me->prepare_skill("strike", "luoying-zhang");
                        message_vision(HIG"$N变腿为掌，迅捷无比地向$n攻去。\n"NOR, me, target);
                        call_out("kuangfeng_attack", 2, me, target, "leg", lvl-50);
                } else {
                        me->prepare_skill("strike");
                        me->prepare_skill("leg", "xuanfeng-tui");
                        message_vision(HIG"$N变掌为腿，迅捷无比地向$n攻去。\n"NOR, me, target);
                        call_out("kuangfeng_attack", 2, me, target, "strike", lvl-50);
                }
                me->add_temp("apply/attack",lvl/2);
                me->add_temp("apply/damage",lvl/2);
                for (i = 0; i < 5; i++) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                me->add_temp("apply/attack",- lvl/2);
                me->add_temp("apply/damage",- lvl/2);
       }
}

int help(object me)
{
        write(HIG"\n「狂风绝技」："NOR"\n");
        write(@HELP

        以落英神剑掌配合旋风扫业腿向对手快速攻击，为黄药师极得意的独门绝技
        。六招落英神剑掌，六招旋风扫叶腿，循环不止。

        要求：  碧海潮声功等级 100 以上；
                落英神剑掌等级 100 以上；
                旋风扫叶腿等级 100 以上；
                最大内力 1000 以上；
                每回合消耗内力、精力；
                攻击力，命中率每回合逐渐下降；
                配合奇门五转可提升持续时限。
HELP
        );
        return 1;
}


