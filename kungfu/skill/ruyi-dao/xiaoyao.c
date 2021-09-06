// xiaoyao.c 逍遥
// modified by action@SJ 28/12/2008
// modified by zhuifeng@SJFY 2010/7/20

#include <ansi.h>
  string perform_name() {return HIC"逍遥"NOR;}

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      object weapon;
      weapon = me->query_temp("weapon");
      lvl = ( (int)me->query_skill("ruyi-dao", 1) /4+ (int)me->query_skill("liuyang-zhang", 1) ) /4;
      if(!userp(me)) lvl = lvl /2 ;

      if( !target ) target = offensive_target(me);
     
  if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("逍遥刀只能对战斗中的对手使用。\n");

      if (!weapon || weapon->query("skill_type") != "blade"
       || me->query_skill_mapped("blade") != "ruyi-dao"
       || me->query_skill_mapped("parry") != "ruyi-dao")
      return notify_fail("你手里没有刀，无法使用逍遥！\n");  
                 
      if( (int)me->query_skill("blade",1) < 200 )
      return notify_fail("你的基本刀法等级不够，不能使用「逍遥」！\n");  

      if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
      return notify_fail("你的天山六阳掌等级不够，不能使用「逍遥」！\n");
   
   if(!wizardp(me) && (int)me->query_skill("bahuang-gong", 1) < 250 )
	if(!wizardp(me) && (int)me->query_skill("beiming-shengong", 1) < 200 )
      return notify_fail("你的北冥神功等级不够，不能使用「逍遥」！\n");
  
  

         if (me->query_skill_mapped("force") != "bahuang-gong" )       
      if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你所使用的内功不对。\n");
                
      if( (int)me->query("max_neili") < 4000 )
      return notify_fail("你的内力太弱，不能使用「逍遥」！\n");
      
      if( (int)me->query("neili") < 2000 )
      return notify_fail("你的内力太少了，无法使用出「逍遥」！\n");   
                                                                                 
      if (me->query_skill_prepared("strike") != "liuyang-zhang"
          || me->query_skill_mapped("strike") != "liuyang-zhang")
      return notify_fail("不使用六阳掌，你如何使用「逍遥」进行攻击。\n");             

      message_vision(HIC"\n$N融会贯通逍遥派武学，使出逍遥派武功之精髓「逍遥」绝学，向$n轻描淡写的挥出两刀两掌！\n"NOR, me,target);
if(!userp(target)) target->add_busy(2);
me->set_temp("xiaoyao",1);
      me->add("neili", -300); 
      me->add("jingli", -200);      
      me->add_temp("apply/strength", lvl /10 );
              if (me->query("family/family_name") == "逍遥派") {
      me->add_temp("apply/blade", lvl/2);
      me->add_temp("apply/damage", lvl/2);
    };
                  if (me->query("family/family_name") == "灵鹫宫") {
      me->add_temp("apply/blade", lvl);
      me->add_temp("apply/damage", lvl);
      me->add_temp("apply/attack", lvl /2);
    };
    
    
      me->add_temp("apply/attack", lvl /2);

  if( random(lvl*3) > (int)target->query_skill("parry",1) /3 )
      target->start_busy(1 + random(1)) ;
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);  
      
if (me->is_fighting(target)){
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);  
      weapon->unequip(); }
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
  if (me->is_fighting(target)) 
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
  
     me->add_temp("apply/strength", -lvl /10 );
      if (me->query("family/family_name") == "逍遥派") {
      me->add_temp("apply/blade", -lvl/2);
      me->add_temp("apply/damage", -lvl/2);
    };
                   if (me->query("family/family_name") == "灵鹫宫") {
      me->add_temp("apply/blade", -lvl);
      me->add_temp("apply/damage",- lvl);
      me->add_temp("apply/attack", -lvl /2);
    };
    
      me->add_temp("apply/attack", -lvl /2);
      weapon->wield();
me->delete_temp("xiaoyao");
      me->start_perform(3 + random(2), "「逍遥」");
      return 1;
}

int help(object me)
{
        write(HIC"\n如意刀法之「逍遥」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                最大内力 4000 以上；
                如意刀法等级 200 以上；
                北冥神功等级 200 以上；
                天山六阳掌等级 200 以上；
                激发刀法为如意刀法；
                激发招架为如意刀法；
                激发掌法为天山六阳掌；
                备手法为天山六阳掌；
                且手持兵器。

HELP
        );
        return 1;
}
