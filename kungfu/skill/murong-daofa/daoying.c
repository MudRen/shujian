//    /kungfu/skill/xingyi-zhang/daoying.c pfm daoying
// by leontt /22/6/2000

#include <ansi.h>
inherit F_SSERVER;
int perform(object me,object target)
{
        int j;
        object weapon = me->query_temp("weapon");
       j = me->query_skill("murong-daofa",1)/2 + me->query_skill("xingyi-zhang",1)/2;
       j =j /3;
       if(!userp(me)) j = j*2/ 3;
     
        if( !target ) target = offensive_target(me);

  if( !target  
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("刀影掌只能对战斗中的对手使用。\n");                

        if( (int)me->query_skill("shenyuan-gong", 1) < 100 )
                return notify_fail("你的内功还未练成，不能使用刀影掌！\n");    

        if( (int)me->query_skill("murong-daofa", 1) < 100 )
                return notify_fail("你的刀法还未练成，不能使用刀影掌！\n");        

        if (!weapon
         || weapon->query("skill_type") != "blade"
         || me->query_skill_mapped("blade") != "murong-daofa")
                return notify_fail("你手里没有刀，无法使用刀影掌！\n");

        if((int)me->query_skill("xingyi-zhang", 1) < 100 )
                return notify_fail("你的掌法还未练成，不能使用刀影掌！\n");  
/*
        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("你的内功不是神元功，无法使用刀影掌！\n");      
*/
        if(me->query_skill_mapped("strike") != "xingyi-zhang" 
         || me->query_skill_prepared("strike") != "xingyi-zhang")
                return notify_fail("你没有用掌，无法使用刀影掌！\n");

        if(me->query_skill_mapped("parry") != "xingyi-zhang")
        if(me->query_skill_mapped("parry") != "douzhuan-xingyi")
         if(me->query_skill_mapped("parry") != "murong-daofa")
                return notify_fail("你的招架功夫不对，无法使用刀影掌！\n");

        if((int)me->query("max_neili") < 1200 )
                return notify_fail("你现在内力修为不够，不能使用刀影掌！\n");      

        if((int)me->query("neili") < 600 )
                return notify_fail("你现在内力不足，不能使用刀影掌！\n");      

        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("你的基本刀法不够娴熟，不能在刀招中夹杂使用刀影掌。\n");

        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("你的基本掌法不够娴熟，不能在刀招中夹杂使用刀影掌。\n");     

        message_vision(HIR"\n$N大吼一声使出慕容绝技「刀影掌」，只见$P掌随刀走，片片刀光中夹杂着阵阵掌风一起奔向$n！\n"NOR, me,target);
if(j<= 300 && !userp(target))
 { j = j * 2;
  target->add_busy(2);
}


        me->set_temp("mr_daoying",1);
        me->add("neili", -200); 
        me->add("jingli", -50);
        me->start_perform(4,"刀影掌");  
        me->add_temp("apply/attack", j); 
        me->add_temp("apply/strength",j /10);
        me->add_temp("apply/blade",j);
        me->add_temp("apply/strike",j);
        me->add_temp("apply/damage",j);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
        if( me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                weapon->wield(); 
        }
        
        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
        if(me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                weapon->wield();
        }
        
        if( me->is_fighting(target) && random((int)me->query_str()) > 30)
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
        
        me->add_temp("apply/damage",-j);
        me->add_temp("apply/strike",-j);
        me->add_temp("apply/strength",-j /10);
        me->add_temp("apply/blade",-j);
        me->add_temp("apply/attack", -j);

if(me->query_skill("shenyuan-gong",1)<=450 )
        me->start_busy(1+random(2));
        me->delete_temp("mr_daoying");
        return 1;
}
string perform_name(){ return HIR"刀影掌"NOR; }
