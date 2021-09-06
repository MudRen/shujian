// jianzhang.c 剑掌五连环

#include <ansi.h>
  string perform_name() {return HIC"剑掌五连环"NOR;}

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      object weapon;
      weapon = me->query_temp("weapon");
      lvl = ( (int)me->query_skill("huashan-jianfa", 1) + (int)me->query_skill("hunyuan-zhang", 1) ) /2;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("剑掌五连环只能在战斗中对对手使用。\n");

      if (!weapon || weapon->query("skill_type") != "sword"
         || me->query_skill_mapped("parry") != "huashan-jianfa")
      return notify_fail("你手里没有剑，无法使用剑掌五连环！\n");             
  
     if(me->query_skill_mapped("sword") != "huashan-jianfa")
     if(me->query_skill_mapped("sword") != "dugu-jiujian")
       return notify_fail("你不使用华山剑法如何使用剑掌五连环？\n");             


    if( (int)me->query_skill("sword",1) < 100 )
      return notify_fail("你的基本剑法等级不够，不能使用剑掌五连环！\n");  

      if( (int)me->query_skill("hunyuan-zhang", 1) < 100 )
      return notify_fail("你的混元掌法等级不够，不能使用剑掌五连环！\n");

      if( (int)me->query_skill("huashan-qigong", 1) < 60 )
           if( (int)me->query_skill("zixia-gong", 1) < 60 )
      return notify_fail("你的特殊内功等级不够，不能使用剑掌五连环！\n");
    
  if( (int)me->query("max_neili") < 200 )
      return notify_fail("你的内力太弱，不能使用剑掌五连环！\n");
      
      if( (int)me->query("neili") < 100 )
      return notify_fail("你的内力太少了，无法使用出剑掌五连环！\n");   
                                                                                 
      if (me->query_skill_prepared("strike") != "hunyuan-zhang"
          || me->query_skill_mapped("strike") != "hunyuan-zhang")
      return notify_fail("你现在无法使用剑掌五连环进行攻击。\n");             

      message_vision(HIG"\n$N突然招式一变，剑中夹掌，掌中藏剑，向$n奋力击出三剑两掌,正是华山气宗绝学「"HIR"剑掌五连环"HIG"」！\n"NOR, me,target);
if(me->query("quest/zixia/pass") && me->query_temp("zxg"))
{ message_vision(HBMAG"$N运起紫霞神功，将华山剑法发挥得淋漓尽致，使的虽然只是普通招式，威力却无可匹敌！\n"NOR, me,target);
  me->add_temp("apply/damage", lvl/3  ); 
target->add_busy(2);
target->set_temp("must_be_hit",1);
me->set_temp("zixia_up",1);}
      me->add("jingli", -200);      
      me->add_temp("apply/strength", lvl /20 );
      me->add_temp("apply/sword", lvl/4);
      me->add_temp("apply/damage", lvl /4 );
      me->add_temp("apply/attack", lvl /4);
if(!userp(target)) target->add_busy(1);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
      weapon->unequip(); 
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
  if (me->is_fighting(target)) 
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
      me->add_temp("apply/strength", -lvl /20 );
      me->add_temp("apply/attack", -lvl /4);
      me->add_temp("apply/sword", -lvl/4 );
      me->add_temp("apply/damage", -lvl /4  );
      weapon->wield();
if(me->query_temp("zixia_up")) {
  me->add_temp("apply/damage", -lvl/3  ); 
if(target) target->delete_temp("must_be_hit");
me->delete_temp("zixia_up");}
      me->start_perform(3 + random(2), "「剑掌五连环」");
      return 1;
}


int help(object me)
{
    write(WHT"\n华山剑法「"HIC"剑掌五连环"WHT"」："NOR"\n");
    write(@HELP
    华山气宗绝技。凝聚内力连环击出三剑两掌。
    指令： perform sword.jianzhang

     要求：紫霞神功 60级以上 
          华山剑法 混元掌 均100以上
          需要有相当的内力修为
          激发剑法 华山剑法，激发掌法 混元掌
HELP
);
 return 1;
}


