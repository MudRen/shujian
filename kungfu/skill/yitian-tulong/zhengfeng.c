#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string perform_name(){ return HIC"谁与争锋"NOR; }

int perform(object me, object target)
{
      string msg; 
      int i;                                  
      object weapon = me->query_temp("weapon");

      if (!weapon || weapon->query("skill_type") != "sword")
         return notify_fail("你手中无剑，如何使得出谁与争锋！\n");

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
         return notify_fail("谁与争锋只能在战斗中对对手使用。\n");
             
      if((int)me->query_skill("yitian-tulong",1) < 180 )
         return notify_fail("你的倚天屠龙功还不够娴熟，尚使不出谁与争锋！\n");
      
      if((int)me->query_skill("literate",1) < 180 )
         return notify_fail("你的读书写字等级不够，不能写出谁与争锋！\n");

      if((int)me->query_skill("sword",1) < 180)
         return notify_fail("你的基本剑法等级不够，不能写出谁与争锋！\n");  
      
      if((int)me->query("max_neili") < 1500 )
         return notify_fail("你的内力修为似乎不够! \n");
      
      if((int)me->query("neili") < 500 )
         return notify_fail("你的当前内力似乎不够！\n"); 

      if( target->is_busy() )
         return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

      if (me->query_skill_mapped("sword") != "yitian-tulong"
       || me->query_skill_mapped("parry") != "yitian-tulong")
         return notify_fail("你现在无法写出「谁与争锋」！\n");

      i = random((int)(me->query_skill("yitian-tulong",1)/100));
      if(i < 2) i=2;
      if(i > 4) i=4;                                                                                 
      msg = HIC"$N长啸一声，手中"+weapon->query("name")+HIC"直划下来，当真是星剑光芒，如矢应机，\n"+
               "霆不暇发，电不及飞，这一直乃是“锋”字的最后一笔！\n" NOR;
      me->add("neili", - 200);
      if((random(me->query_skill("literate", 1)) > target->query_skill("literate", 1)/5)
        &&  random(me->query("combat_exp")) > target->query("combat_exp")/2) {
            target->start_busy(i+1);
            msg += HIR"$n猝不及防，但见"+weapon->query("name")+HIC"剑光雪亮，只得连连招架，毫无还手之力。\n"NOR;
      }
      else {
            me->start_busy(2);
           target->start_busy(1);
            msg += HIY"$n见$N招式犀利，心下已是暗暗警惕，当下抽身急退，躲过了这一招。\n"NOR;
      }
      message_vision(msg, me, target);
      me->start_perform(3,"「谁与争锋」");
      return 1;
}




int help(object me)
{
   write(HIG"\n「"HIW"谁与争锋"HIG"」："NOR"\n");
	write(@HELP
      待到月涌中天，他(张三丰)长啸一声，右掌直划下来，当真是星剑光芒; 
      如矢应机，霆不暇发，电不及飞，这一直乃是“锋”字的最后一笔。

  
    指令：perform sword(parry).zhengfeng

    要求：基本剑法180级
          读书写字180级
          倚天屠龙功180级
          最大内力1500以上，当前内力500以上。
          激发剑法，招架为倚天屠龙功，且手中持有武器          

    说明：这峰字最后一笔犀利无匹，敌人猝不及防之下，往往只能疲于招架
          毫无还手之力。
HELP
	);
	return 1;
}
