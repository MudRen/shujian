#include <ansi.h>
#include <combat.h>

#define ZHEN "「" HIW "反璞归真" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
string msg;
    int extra,i;
    extra = me->query_skill("huanmo-longtianwu",1);
    if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
        return notify_fail("「返璞归真」只能对战斗中的对手使用。\n");

    if( objectp(me->query_temp("weapon")) )
        return notify_fail("你必须空手使用「返璞归真」！\n");

    if( (int)me->query_skill("huanmo-longtianwu", 1) < 100 )
        return notify_fail("你的幻魔胧天舞不够娴熟，无法施展出「返璞归真」。\n");

    if( (int)me->query_skill("force", 1) < 100 )
        return notify_fail("你的基本内功不够娴熟，无法施展出「返璞归真」。\n");
   
    if ( (int)me->query("max_neili") < 3000)
        return notify_fail("你的内力修为不够，无法施展出「返璞归真」。\n");

    if ( (int)me->query("neili") < 1000)
        return notify_fail("你的真气不够，无法施展出「返璞归真」。\n");
   
    if (me->query_skill_prepared("strike") != "huanmo-longtianwu"
        || me->query_skill_mapped("strike") != "huanmo-longtianwu")
        return notify_fail("你现在无法使用「返璞归真」！\n");  
        
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/strike", extra/2);
    me->add_temp("apply/damage", extra);
    me->add("neili", -350);
    target->add_busy(1);

        message_vision(HIR "陡然间$N" HIR "施出「" HIY "反" HIR "」字诀，双掌向$n"
              HIR "平平推去，招数朴实无华，毫无半点花巧可言。\n" NOR, me,target);
i = 1;
if(userp(me)) i = 3;              
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
    
    message_vision(HIB "\n紧接着$N" HIB "变招「" HIC "璞" HIB "」字诀，霎"
               "时只见$N" HIR "双掌纷飞，化出漫天掌影笼罩$n" HIW "四面"
               "八方。\n" NOR, me,target); 
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),i,msg);
    
    message_vision(HIM "\n紧接着$N" HIM "变招「" HIY "归" HIM "」字诀，霎"
               "时只见$N" HIR "双掌纷飞，化出漫天掌影笼罩$n" HIW "四面"
               "八方。\n" NOR, me,target); 
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),i,msg);
    
    message_vision(HIC "\n最后着$N" HIC "变招「" HIG "真" HIC "」字诀，霎"
               "时只见$N" HIR "双掌纷飞，化出漫天掌影笼罩$n" HIW "四面"
               "八方。\n" NOR, me,target); 
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),i,msg);
    
    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/strike", -extra/2);
    me->add_temp("apply/damage", -extra);
    target->start_busy(random(2));
    me->start_perform(3+random(2),"「返璞归真」");
    return 1;
}

string perform_name(){ return HIR"返璞归真"NOR; }
