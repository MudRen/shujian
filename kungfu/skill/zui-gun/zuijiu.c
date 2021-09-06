// zuijiu.c 醉酒

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{                                  
      int i, lvl, addlvl;
      object weapon;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target))
                return notify_fail("「八仙醉打」只能在战斗中对对手使用。\n");

      if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "zui-gun")
                return notify_fail("你现在无法使用「八仙醉打」。\n");
  
      if( (int)me->query_skill("zui-gun",1) < 100 )
                return notify_fail("你的醉棍不够娴熟，不会使用「八仙醉打」！\n");
      
      if( me->query_skill_mapped("force") != "yijin-jing" )
                return notify_fail("你现在所使的内功无法使出「八仙醉打」。\n");

      if( (int)me->query_skill("yijin-jing",1) < 100 )
                return notify_fail("你的易筋经等级不够，不能使用「八仙醉打」！\n");  
       
      if( (int)me->query_str() < 25 )
                return notify_fail("你的臂力不够强，不能使用「八仙醉打」！\n");
      
      if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力太弱，不能使用「八仙醉打」！\n");
            
        lvl = (int)me->query_skill("zui-gun", 1);
        addlvl = (int)me->query_skill("zui-gun", 1)/2 +  me->query_skill("yijin-jing",1)/3;

        if(lvl < 120) return notify_fail("你的等级太低，无法使用出「八仙醉打」！\n");

      	if( (int)me->query("neili") < 1500 )
                return notify_fail("你的内力太少了，无法使用出「八仙醉打」！\n");
      	lvl /= 20;
      	lvl--;
      	if(lvl > 8) lvl = 8; 
      	if(lvl < 1) return notify_fail("你的等级太低，无法使用出「八仙醉打」！\n");
 message_vision(HIY"\n$N已然了悟“形醉意不醉，步醉心不醉”的醉棍真谛，步履踉跄，似醉非醉，使出「八仙醉打」，醉棍威力大增！\n"NOR,me);
if(!userp(target))  target->add_busy(1+random(2));
       me->add_temp("apply/attack", addlvl/2);
        me->add_temp("apply/parry", addlvl/2);
        me->add_temp("apply/dodge", addlvl/2);
        me->add_temp("apply/damage", addlvl/2);
      	me->set_temp("zuijiu", 1);
      	for(i=0; i < lvl; i++){
      	   	if(!me->is_killing(target->query("id")) 
      	   	&& !target->is_killing(me->query("id"))
      	   	&& !target->is_fighting(me))
      	   	break;
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?3:1);
           	me->add_temp("zuijiu", 1);
                me->receive_damage("neili", 50);
                me->receive_damage("jingli", 10);
      	}
      	me->delete_temp("zuijiu");
        me->add_temp("apply/attack", -addlvl/2);
        me->add_temp("apply/parry", -addlvl/2);
        me->add_temp("apply/dodge", -addlvl/2);
        me->add_temp("apply/damage", -addlvl/2);
    me->start_perform(4, "「八仙醉打」");
        tell_object(me, HIG"\n你心神一乱，再也无法维持似醉非醉的意境了。\n"NOR); 
        return 1;
}
