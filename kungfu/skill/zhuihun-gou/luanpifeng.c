// luanpifeng.c 乱披风 
// by snowman@SJ 30/09/1999

#include <ansi.h>

inherit F_SSERVER;
int remove_effect(object me,object target,object weapon,int conut);

int perform(object me, object target)
{
       object weapon = me->query_temp("weapon");  
       int skill;
    
       if( !target ) target = offensive_target(me);
     
       if( !target || !me->is_fighting(target))
           return notify_fail("「乱披风」只能在战斗中对对手使用。\n");
 
       if ( (int)me->query_skill("huagong-dafa", 1) < 150 )
           return notify_fail("你的内功等级不够，不能使用「乱披风」。\n");
    
       if ( (int)me->query_skill("zhuihun-gou", 1) < 150 )
           return notify_fail("你的天山追魂钩不够娴熟，不能真正发挥「乱披风」。\n");
    
       if (!weapon 
        || weapon->query("skill_type") != "hook"
        || me->query_skill_mapped("hook") != "zhuihun-gou")
           return notify_fail("你现在无法使用「乱披风」来提高攻击力。\n");
    
       if ( (int)me->query("max_neili") < 2500 )
           return notify_fail("你的内力修为不够，不能使用「乱披风」。\n");

       if ( (int)me->query("max_jingli") < 1000 )
           return notify_fail("你的精力修为不够，不能使用「乱披风」。\n");

       if ( (int)me->query("neili") < 700 )
           return notify_fail("你现在内力太弱，不能使用「乱披风」。\n");
    
       if ( (int)me->query_temp("zhuihun/lpf") ) 
           return notify_fail("你正在使用天山追魂钩之「乱披风」。\n");
    
       if (me->query_skill_mapped("force") != "huagong-dafa")
           return notify_fail("你的内功有误，无法使用「乱披风」。\n");

       message_vision(HBBLU "\n$N将发结解开，披头散发，脸色惨白，突然狂嚎一声，手中的"+weapon->name()+HBBLU"胡乱挥舞着，全然不按章法，间杂着抽髓掌狂乱使出！\n"NOR, me);                 
  
       me->set_temp("zhuihun/lpf",1);
         
       skill = me->query_skill("zhuihun-gou", 1);
    
       me->add_temp("apply/parry",  -skill/6);
       me->add_temp("apply/dodge",  -skill/6);
       me->add_temp("apply/attack",  skill/3);
       me->add_temp("apply/damage",  skill/3);

 if(!userp(target)) target->start_busy(2);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
       me->add("neili", -(me->query_skill("force")));
       me->add("jingli", - 100);
       me->start_perform(3, "乱披风");
       call_out("remove_effect", 1, me, target, weapon, skill/10);
       return 1;
}

int remove_effect(object me,object target,object weapon,int count)
{
        if(!me) return 0;
        if(!me->query_temp("zhuihun/lpf")) return 0;
        if( !target 
         || ! me->is_fighting(target)
         || weapon != me->query_temp("weapon")
         || me->query_skill_mapped("hook") != "zhuihun-gou"
         || count < 0){
           me->add_temp("apply/attack", -me->query_skill("zhuihun-gou", 1)/3);
           me->add_temp("apply/damage", -me->query_skill("zhuihun-gou", 1)/3);
           me->add_temp("apply/parry", me->query_skill("zhuihun-gou", 1)/6);        
           me->add_temp("apply/dodge", me->query_skill("zhuihun-gou", 1)/6);
           me->delete_temp("zhuihun/lpf");
           if(living(me))
             message_vision(HIG "\n$N大口大口地喘气，招数也渐渐恢复正常，看来是消耗了不少的气力！\n\n" NOR, me);
           return 0;
         }
         call_out("remove_effect", 1 ,me ,target, weapon, count -1);
}
