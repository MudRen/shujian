//  jingtian.c 惊天断云斧 
//  by Leontt 2000.6.11

#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
      int lvl;
      object weapon;
      weapon = me->query_temp("weapon");
      lvl = (int)me->query_skill("pangen-fu", 1)/2;
      if( !target ) target = offensive_target(me);
     
     if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("盘根错节斧只能对战斗中的对手使用。\n");
    
      if (!weapon || weapon->query("skill_type") != "axe"
       || me->query_skill_mapped("axe") != "pangen-fu")
        return notify_fail("你使用的兵刃不对，无法使用「惊天断云斧」！\n");             

      if( (int)me->query_skill("pangen-fu",1) < 120 )
        return notify_fail("你的盘根斧法不够娴熟，不能使用「惊天断云斧」！\n"); 
      
      if( (int)me->query_skill("axe",1) < 100 )
        return notify_fail("你的基本斧法等级不够，不能使用「惊天断云斧」！\n");  
     
      if( (int)me->query_skill("qiantian-yiyang", 1) < 100 )
        return notify_fail("你的乾天一阳功等级不够，不能使用「惊天断云斧」！\n");

      if( (int)me->query("max_neili") < 1000 )
        return notify_fail("你的内力太弱，不能使用「惊天断云斧」！\n");
      
      if( (int)me->query("neili") < ( me->query_skill("force")+ lvl ))
        return notify_fail("你的内力太少了，无法使用出「惊天断云斧」！\n");   
      
      message_vision(HIY"\n$N突然大喝一声,运足内力，手中"+weapon->query("name") +HIY"轮圆了劈将下来，巨斧本已甚为"+
                          "深重，加上$N全力施展，力道何止千斤，直有惊天断云之威！\n"NOR, me,target);
      me->add("neili", - (300+random(200)));
      me->add("jingli", -80);      
      lvl= lvl/5 + me->query("con") + me->query("str");
      me->add_temp("apply/axe", lvl);
      me->add_temp("apply/strength", lvl /5 );
      me->add_temp("apply/attack", lvl);
      me->add_temp("apply/damage", lvl);
      me->set_temp("jingtian", 1);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
      if (present(target,environment(me)) && me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
      if (present(target,environment(me))
       && me->is_fighting(target)
       && me->query_skill("pangen-fu", 1) > 150){
       if(random(me->query("combat_exp")) > target->query("combat_exp")/3)     
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       else 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
      }
      me->add_temp("apply/axe",- lvl);
      me->add_temp("apply/strength", -lvl /5 );
      me->add_temp("apply/attack",- lvl);
      me->add_temp("apply/damage",- lvl);
      me->delete_temp("jingtian");
      me->start_busy(random(2));
      me->start_perform(5,"「惊天断云斧」");
      return 1;
}
