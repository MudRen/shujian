    // by xjqx 2008/12/30

#include <ansi.h>
inherit F_SSERVER;
int perform(object me,object target)
{
        int j = me->query_skill("tianmo-dao", 1)/2 +me->query_skill("tianmo-zhang",1)/2;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("惊神诀只能对战斗中的对手使用。\n");                

        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 100)
                return notify_fail("以你现在的内功修为还使不出「惊神诀」。\n");  

        if( (int)me->query_skill("tianmo-dao", 1) < 100 )
                return notify_fail("你的刀法还未练成，不能使用惊神诀！\n");        

        if (!weapon
         || weapon->query("skill_type") != "blade"
         || me->query_skill_mapped("blade") != "tianmo-dao")
                return notify_fail("你手里没有刀，无法使用惊神诀！\n");

        if((int)me->query_skill("tianmo-zhang", 1) < 100 )
                return notify_fail("你的天魔掌法还未练成，不能使用惊神诀！\n");  

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing-dafa")
                return notify_fail("你所使用的特殊内功不对。\n");   

        if(me->query_skill_mapped("strike") != "tianmo-zhang" 
         || me->query_skill_prepared("strike") != "tianmo-zhang")
                return notify_fail("你没有用天魔掌，无法使用惊神诀！\n");

        if(me->query_skill_mapped("parry") != "tianmo-zhang")
         if(me->query_skill_mapped("parry") != "tianmo-dao")
                return notify_fail("你的招架功夫不对，无法使用惊神诀！\n");

        if((int)me->query("max_neili") < 2000 )
                return notify_fail("你现在内力修为不够，不能使用惊神诀！\n");      

        if((int)me->query("neili") < 1000 )
                return notify_fail("你现在内力不足，不能使用惊神诀！\n");      

        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("你的基本刀法不够娴熟，不能在刀招中夹杂使用惊神诀。\n");

        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("你的基本掌法不够娴熟，不能在刀招中夹杂使用惊神诀。\n");     

        message_vision(HIR"\n一声怒吼，$N使出日月神教绝技之「惊神诀」，只见漫天刀影掌影扑天盖地突袭$n而去！\n"NOR, me,target);
        me->set_temp("tmd/jingshen",1);
        me->add("neili", -200); 
        me->add("jingli", -50);
        me->add_temp("apply/attack", j*4/3);
        me->add_temp("apply/damage", j*5/7);
        me->add_temp("apply/dodge",j);
if(j>450 ) target->add_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        if(objectp(target) && me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                weapon->wield(); 
        }
        if(objectp(target) && me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        if(objectp(target) && me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                weapon->wield();
        }
        if(objectp(target) && me->is_fighting(target) && random((int)me->query_str()) > 30)
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("apply/dodge",-j);
        me->add_temp("apply/attack", -j*4/3);
        me->add_temp("apply/damage", -j*5/7);
        me->delete_temp("tmd/jingshen");
        me->start_perform(2+random(2),"惊神诀");
        return 1;
}
string perform_name(){ return HIR"惊神诀"NOR; }
