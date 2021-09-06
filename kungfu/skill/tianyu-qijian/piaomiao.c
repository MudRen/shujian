// 缥缈剑法
#include <ansi.h>
#include <combat.h> 
#include <skill.h>
string perform_name(){ return HBMAG"缥缈剑法"NOR; }
inherit F_SSERVER;

int perform(object me, object target)
{
         string dodge_skill,msg;
         int i, j;
       object weapon;

    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) 
    	|| !me->is_fighting(target) 
    	|| !living(target)
      || environment(target)!=environment(me))
                return notify_fail("「缥缈剑法」只能对战斗中的对手使用。\n");

 
         if (me->query_skill_mapped("force") != "beiming-shengong")
         if (me->query_skill_mapped("force") != "bahuang-gong" )                
                return notify_fail("你的内功有误，无法使用「缥缈剑法」！\n");

       	if(!wizardp(me) && (int)me->query_skill("beiming-shengong", 1) < 350 )
       	if(!wizardp(me) && (int)me->query_skill("bahuang-gong", 1) < 350 )
                return notify_fail("你的内功还未练成，不能使用「缥缈剑法」！\n");

    if((int)me->query_skill("force", 1) < 350 )
                return notify_fail("你的基本内功不够娴熟，无法支持「缥缈剑法」。\n");

    if( (int)me->query_skill("tianyu-qijian", 1) < 350 ) 
                return notify_fail("你的剑法还未练成，不能使用「缥缈剑法」！\n");

    if((int)me->query_skill("sword", 1) < 350 )
                return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用「缥缈剑法」。\n");

    if((int)me->query_skill("dodge", 1) < 350 )
                return notify_fail("你的基本轻功不够娴熟，不能使用「缥缈剑法」。\n");

    if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "tianyu-qijian"
        || me->query_skill_mapped("parry") != "tianyu-qijian")
                return notify_fail("你手里无剑，如何使用「缥缈剑法」？\n");
                
    if((int)me->query("max_neili") < 10000 )
                return notify_fail("你现在真气不足，不能使用「缥缈剑法」！\n");

    if((int)me->query("neili") < 6000 )
                return notify_fail("你现在真气不足，不能使用「缥缈剑法」！\n");

    if((int)me->query("jingli") < 3000 )
                return notify_fail("你现在太累了，不能使用「缥缈剑法」！\n");
                

       msg = HBMAG "$N贯通灵鹫宫武学，使出了灵鹫宫的绝学之精髓！\n" NOR;
           me->add("neili", -me->query("max_neili")/10);
       message_vision(msg, me, target);          
 
 
         me->set_temp("tyqj/piaomiao", 1);
         me->start_perform(4+random(2),"「缥缈剑法」");

         message_vision(MAG"\n$N潜运逍遥心法，"+weapon->name()+MAG"光芒大作，寒光凛冽，不可逼视。\n"NOR,me,target);

         i = me->query_skill("tianyu-qijian", 1);
         j = me->query_skill("sword", 1) ;
         
if( me->query("quest/天龙八部/北冥神功/pass") ){i = i * 2;
                                                j = j * 2;}
                                                
         me->add_temp("apply/attack", j/3);
         me->add_temp("apply/damage", j/3); 

         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),3); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),3); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),3);      

        me->add_temp("apply/attack", -j/3);
        me->add_temp("apply/damage", -j/3);
	 
    if (random(me->query("combat_exp")) > target->query("combat_exp")/2 && me->fighting(target) && living(target) ){
     message_vision(HIW"\n$N运起八荒六合唯我独尊功，于无声无息间发出一道生死符，\n"NOR,me,target);
	  
           target->set_temp("must_be_hit",1);
           target->add_busy(2);
           target->apply_condition("no_fight",2);
           target->apply_condition("no_perform",2);

		}
        
        
        
         weapon->unequip();
         me->add_temp("apply/strength", i/10);
    
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3);                                
         message_vision(HIM"【弹 梅】"NOR, me, target); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3);                                     
         message_vision(HIW"【落 雪】"NOR, me, target); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3);                                       
         message_vision(HIM"【散花香】\n"NOR, me, target); 
         me->start_busy(2);
         me->add_temp("apply/strength", -i/10);
         me->delete_temp("tyqj/piaomiao");
if(target)
	       target->delete("must_be_hit");
      
         weapon->wield();
          return 1;
 }

int help(object me)
{
    write(WHT"\n天羽奇剑之「"MAG"缥缈剑法"WHT"」："NOR"\n");
         write(@HELP
   天羽奇剑之绝技缥缈剑舞，不知道谁的手笔，描述非常诡异。
   连出三剑三掌。风雨雷电弹梅落雪散花香，比倪匡还卫斯理。

   要求：
        八荒六合唯我独尊功350级，基本内功350级
        天羽奇剑，基本剑法，基本轻功各350级
        激发招架剑法为 天羽奇剑
        最大内力10000，当前内力6000，当前精力3000
        因此招消耗巨大，非生死相搏，切勿乱用。
HELP
    );
        return 1;
}
 
