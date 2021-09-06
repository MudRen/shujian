// chanshen.c 缠身

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      
      
      lvl = ((int)me->query_skill("hamagong", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;
          if( !target ) target = offensive_target(me);
           if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「金蛇缠身」之技只能在战斗中对敌人使用。\n");

        if( (int)target->query_temp("bt_chanshen") )
                return notify_fail("对方已经被你使金蛇缠身缠住了！\n");
      if( (int)me->query_skill("shexing-diaoshou",1) < 100 )
      return notify_fail("你的蛇行刁手不够娴熟，不能使出金蛇缠身！\n");
      if( (int)me->query_skill("hamagong", 1) < 150 && (int)me->query_skill("huntian-qigong", 1) < 150  )
      return notify_fail("你的特殊内功等级不够，不能使出金蛇缠身！\n");
      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("你的内力太弱，不能使出金蛇缠身！\n");
      if( (int)me->query("neili") < 200 )
      return notify_fail("你的内力太少了，不能使出金蛇缠身！\n");   
                if( (int)me->query("neili") < 300 )
      return notify_fail("你的精力太少了，不能使出金蛇缠身！\n");   


    message_vision(HIR"\n$N招法一变，运用起刁手七绝：粘缠吸引即束展，招招不离$n的要害！\n"NOR,me);
      me->add("neili", -300+random(50)); 
      me->add("jingli", -150+random(50));      
                target->add_temp("apply/parry",  -lvl/5);
                target->add_temp("apply/dodge",  -lvl/5);
                target->add_temp("apply/aromr",  -lvl/5);
                if(target->query("combat_exp")<random(me->query("combat_exp"))*2
                        )
                {
                        message_vision(HIW"\n但见$N的招式犹如毒蛇缠身一般，紧紧攻向$n的要害，"
                        "\n$n的动作顿时慢了下来，身形渐渐凝滞起来。\n"NOR, me,target);
                        
                        target->start_busy(1+random(lvl/100));
                }

                target->set_temp("bt_chanshen",1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", target, lvl/5 :), lvl/100);
                
                me->start_busy(1+random(2));
      return 1;
}

void remove_effect(object target,int lvl)
{
                        if( !target ) return;
                        target->add_temp("apply/parry",  lvl);
                        target->add_temp("apply/dodge",  lvl);
                        target->add_temp("apply/aromr",  lvl);
                        target->delete_temp("bt_chanshen");
                if(target->is_fighting() )
                        {
                        target->start_busy(1 + random(1));
                        message_vision(HIG"$N使出浑身解数，算是挣脱了蛇形刁手的诡异怪招。\n"NOR, target);
                        }
}

string perform_name() {return HIW"金蛇缠身"NOR;}
