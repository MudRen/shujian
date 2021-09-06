// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define YAN "「" HIR "天寰神炎" NOR "」"

inherit F_SSERVER; 
string perform_name(){ return HIR"天寰神炎"NOR; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int lvl,damage;
        
        if (! target) target = offensive_target(me); 
        
        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
		return notify_fail("天寰神焰只能对战斗中的对手使用。\n");
         
        if (me->query_temp("weapon") )
                return notify_fail("你必须空手才能施展" YAN "。\n");
         
        if (me->query_skill("force") < 200) 
                return notify_fail("你的内功的修为不够，无法施展" YAN "。\n");
        
        if (me->query_skill("huoyan-dao", 1) < 150) 
                return notify_fail("你的火焰刀修为不够，无法施展" YAN "。\n");
         
        if (me->query("neili") < 600 || me->query("max_neili") < 2000) 
                return notify_fail("你的真气不够，无法施展" YAN "。\n");

        if (me->query_skill_mapped("strike") != "huoyan-dao") 
                return notify_fail("你没有激发火焰刀，无法施展" YAN "。\n");

        if (me->query_skill_prepared("strike") != "huoyan-dao")
                return notify_fail("你没有准备火焰刀，无法施展" YAN "。\n");

       
        if (me->query_skill("xuedao-jing", 1) > 1) 
               return notify_fail("你修炼血刀经与" YAN "义理相悖，不能施展。\n");
     
        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "\n\n$N" HIR "忽做明王忿怒状， 目瞪如铃，怒发上冲，狂催真气注入单掌，掌缘顿时腾起一道熊熊烈炎！\n" NOR;
       

        me->add("neili", -500);

       lvl = me->query_skill("huoyan-dao",1);
       
      damage = lvl*3;
      damage = damage+random(damage);
       
        
  if( damage > target->query("qi") ) {
  	      damage= target->query("qi")-1;
          target->start_busy(5);
                                     }

          	target->receive_damage("qi", damage, me);
          	target->receive_wound("qi", random(damage), me);     
               
        message_vision(msg, me, target);

COMBAT_D->report_status(target, 2);

me->set_temp("yan",1);
         
        
        
if(random(10)>6 || (!userp(target)&& lvl > 350)) {
    //         target->set_temp("must_be_hit",1);
             target->start_busy(1+ random(4));
                              }

me->add_temp("apply/parry", lvl/3);
me->add_temp("apply/dodge", lvl/3);
me->add_temp("apply/attack", lvl/5);
me->add_temp("apply/damage", lvl/5);
 
        COMBAT_D->do_attack(me, target, weapon, 3);

       if( me->is_fighting(target) )  
        COMBAT_D->do_attack(me, target, weapon, 3);

       if( me->is_fighting(target) ) 
        COMBAT_D->do_attack(me, target, weapon, 3);

  //      target->delete_temp("must_be_hit");
  
        me->start_busy(1 + random(2));
        me->start_perform(3,"「天寰神炎」");
       
me->add_temp("apply/parry", -lvl/3);
me->add_temp("apply/dodge", -lvl/3);
me->add_temp("apply/attack", -lvl/5);
me->add_temp("apply/damage", -lvl/5);
me->delete_temp("yan");
        return 1;

}


