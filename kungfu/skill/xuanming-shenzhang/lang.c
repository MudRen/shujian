// jijin激劲
// by reikou
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)

{
    string msg;
    int extra;
    extra = me->query_skill("xuanming-shenzhang",1);
    if( !target ) target = offensive_target(me);
    if( !target
      ||        !target->is_character()
      ||        !me->is_fighting(target) )
        return notify_fail("「惊涛骇浪」只能对战斗中的对手使用。\n");

    if( objectp(me->query_temp("weapon")) )
        return notify_fail("你必须空手使用「惊涛骇浪」！\n");

    if( (int)me->query_skill("xuanming-shenzhang", 1) < 350 )
        return notify_fail("你的玄冥神掌不够娴熟，无法施展出「惊涛骇浪」。\n");

    if( (int)me->query_skill("force", 1) < 350 )
        return notify_fail("你的基本内功不够娴熟，无法施展出「惊涛骇浪」。\n");
   
    if ( (int)me->query("max_neili") < 3000)
        return notify_fail("你的内力修为不够，无法施展出「弹指激劲」。\n");

    if ( (int)me->query("neili") < 1000)
        return notify_fail("你的真气不够，无法施展出「惊涛骇浪」。\n");
   
    if (me->query_skill_prepared("strike") != "xuanming-shenzhang"
        || me->query_skill_mapped("strike") != "xuanming-shenzhang")
        return notify_fail("你现在无法使用「惊涛骇浪」！\n");  
    
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/strike", extra);
    me->add_temp("apply/damage", extra);
    me->add("neili", -350);
    target->start_busy(1);
        message_vision(BLU"$N当下身形纵上前来，双掌推出，使出玄冥神掌最为精髓的绝招，掌力未至，阴寒之风已如惊涛骇浪般向$n迎而扑来！"NOR"\n" NOR, me,target);
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    
    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/strike", -extra);
    me->add_temp("apply/damage", -extra);
    me->start_busy(1);
    target->start_busy(random(2));
    me->start_perform(4,"「惊涛骇浪」");
    return 1;
}


