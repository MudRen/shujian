// xunlei-jian perform
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int lvl ;
        object weapon;
        lvl = me->query_skill("xunlei-jian", 1) /2 + me->query_skill("kunlun-zhang",1) /2 ;

 if(!userp(me)) lvl = lvl /2;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("「迅雷破地」只能在战斗中对对手使用。\n");
                
        if (!weapon || weapon->query("skill_type") != "sword"
                         || me->query_skill_mapped("sword") != "xunlei-jian"
                         || me->query_skill_mapped("parry") != "xunlei-jian")
                return notify_fail("你必须在使用剑时才能使出「迅雷破地」\n");
                         
      if( (int)me->query_skill("kunlun-zhang", 1) < 100 )
      return notify_fail("你的昆仑掌法等级不够，不能使用迅雷破地！\n"); 
      
      if (me->query_skill_prepared("strike") != "kunlun-zhang"
                        || me->query_skill_mapped("strike") != "kunlun-zhang")
      return notify_fail("你现在无法使用迅雷破地进行攻击。\n");             
      
        if(me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("你的迅雷剑还不够娴熟，使不出「迅雷破地」。\n");
        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你现在内力太弱，使不出「迅雷破地」。\n");
        if( (int)me->query("neili") < 400 )
                return notify_fail("你现在真气太弱，使不出「迅雷破地」。\n");



        msg = HIB"\n$N猛然伏地，使出迅雷十六剑之「迅雷破地」，顿时一片白光直向前滚去！\n\n"NOR;
        message_vision(msg, me, target);

      me->set_temp("kl/podi",1);
      me->add("neili", -550); 
      me->add("jingli", -200);      
      me->add_temp("apply/strength", lvl /10 );
      me->add_temp("apply/sword", lvl/3);
      me->add_temp("apply/parry", lvl/3);
      me->add_temp("apply/damage", lvl /3 );
      me->add_temp("apply/attack", lvl /3);
      
if( random(lvl*3) > (int)target->query_skill("parry",1) /3 || !userp(target))
target->start_busy(2) ;

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?3:1);  
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?3:1);  


      weapon->unequip(); 
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3); 
      weapon->wield();

if(lvl>=350){
   if (me->is_fighting(target)) 
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
   if (me->is_fighting(target)) 
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
   }
      
      me->add_temp("apply/strength", -lvl /10 );
      me->add_temp("apply/attack", -lvl /3);
      me->add_temp("apply/parry", -lvl/3);
      me->add_temp("apply/sword", -lvl/3 );
      me->add_temp("apply/damage", -lvl /3 );

      me->start_busy(2);
       me->delete_temp("kl/podi");
       me->start_perform(3+random(2),"「迅雷破地」");
       return 1;
}
string perform_name(){ return MAG"迅雷破地"NOR; }
int help(object me)
{
write(MAG"\n迅雷剑法之「迅雷破地」："NOR"\n\n");
write(@HELP
          要求：  当前内力 400 以上；
          最大内力 1000 以上；
          迅雷剑法等级 100 以上；
          激发剑法为迅雷剑法；
          激发招架为迅雷剑法；
          激发切备有昆仑掌法
          必须手拿武器。

HELP
);
return 1;
}
