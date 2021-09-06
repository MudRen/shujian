//rebuild by jpei 2010
//原来的思路和写法有些乱
 
#include <ansi.h>
#include <combat.h>
 
 inherit F_SSERVER;
 
 int perform(object me, object target)
 {
         string msg;
         object weapon;
         int jf,zf,sf,lvl;
         weapon = me->query_temp("weapon");

         if( !target ) target = offensive_target(me);

        if( !target 
          || !me->is_fighting(target)
          || !objectp(target)
          || environment(target)!= environment(me))
                return notify_fail("「金蛇狂舞」只能在战斗中对对手使用。\n");

 
        if (!weapon || weapon->query("skill_type") != "sword"
                         || me->query_skill_mapped("sword") != "jinshe-jianfa")
                 return notify_fail("你必须在使用剑时才能使出「金蛇狂舞」！\n");
//嘿嘿，这里貌似没判断parry啊。。9j,dkdny,dzxy...
 
         if(me->query_skill("jinshe-jianfa", 1) < 120 )
                 return notify_fail("你的金蛇剑法还不够娴熟，使不出「金蛇狂舞」绝技。\n");

         if( (int)me->query_skill("force") < 170 )
                 return notify_fail("你的内功等级不够，使不出「金蛇狂舞」绝技。\n");
 
         if( (int)me->query_str() < 27)
                 return notify_fail("你的膂力还不够强劲，使不出「金蛇狂舞」绝技。\n");
 
         if( (int)me->query_dex() < 27)
                 return notify_fail("你的身法还不够迅猛，使不出「金蛇狂舞」绝技。\n");
/*
         if( (int)me->query("dex") < 20 ||( (int)me->query("str") > 20&&  (int)me->query("str") <31) || (int)me->query("int") < 20)
                 return notify_fail(HIG"你傻头傻脑,笨手笨脚的,乱舞个什么劲.\n"NOR);
*/
         if( (int)me->query("max_neili") < 800 )
                 return notify_fail("你现在内力太弱，使不出「金蛇狂舞」。\n");      
 
         if( (int)me->query("neili") < 500 )
                 return notify_fail("你现在真气不足，使不出「金蛇狂舞」。\n");

     
         jf = me->query_skill("jinshe-jianfa", 1);
         zf = me->query_skill("jinshe-zhang", 1);
         sf = me->query_skill("wudu-yanluobu", 1);
         lvl=( jf + zf +sf ) /2;        



if(weapon->query("id") == "jinshe sword"|| weapon->query("id") == "yinshe sword" || weapon->query("imbued")>=4 || !userp(me))     me->set_temp("jsj", 1); //判断武器是不是金蛇剑或者银蛇
   
if( me->query_skill("wudu-yanluobu", 1) > 120 && me->query_skill_mapped("dodge") == "wudu-yanluobu")
           {     me->add_temp("apply/dexerity",sf /10);
                 me->add_temp("apply/attack",sf /4); 
                 me->set_temp("sfup",1); 
     }

if( me->query_skill("jinshe-zhangfa", 1) > 120&& me->query_skill_mapped("strike") == "jinshe-zhangfa" && me->query_skill_prepared("strike") == "jinshe-zhangfa")
          {           me->add_temp("apply/strength", zf/10);
                      me->add_temp("apply/damage", zf/6);
                      me->set_temp("zfup",1);
           }       
                                                                
if( me->query_skill("jinshe-jianfa",  1) > 120 && me->query_skill_mapped("sword") == "jinshe-jianfa")
         {      me->add_temp("apply/sword", lvl /4);
                me->add_temp("apply/parry", lvl  /4);
                me->add_temp("apply/damage", lvl/6);
                me->set_temp("jfup",1);
          }        


message_vision(HIC"\n$N一摆手中"+weapon->name()+HIC"使出金蛇剑法不传之秘，第"HIW"一"HIC"重金蛇狂舞之"HIY"金蛇吐芯"HIC"身法骤然加快了速倍。\n"NOR,me);
            me->add_temp("apply/damage", lvl /6);
            me->add_temp("apply/attack", lvl /4);
            me->add_temp("apply/dexerity",sf /10);
 if (me->is_fighting(target))
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

 if(  me->query_temp("jsj") &&  me->query_temp("zfup")  )
 {      
                     message_vision(HIY"\n\n$N手中"+weapon->name()+HIY"连划数剑，逼出道道金光，剑光中$N化身为二，剑掌齐出，直指$n！。\n"NOR,me,target);
                     message_vision(HIR"$N一抖手中"+weapon->name()+HIR",绽放出万道金光,$n顿时觉得眼花缭乱,被$N攻了个措手不及！。\n"NOR,me,target);
if(!userp(target))
                  {
                   target->start_busy(2);
                                  target->set_temp("must_be_hit",1);
                     }
if( userp(target))  target->add_busy(1);
  

    me->start_perform(3,"「金蛇狂舞」");
              me->add("neili", -300);
              me->add("jingli", -200);

              
        if (me->is_fighting(target)) 
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                          message_vision(HIY"                                                                     ※※※※※※※\n"NOR,me);       
                          message_vision(HIY"                                                                     ※※  金  ※※\n"NOR,me);
                          message_vision(HIY"                                                                     ※※※※※※※\n"NOR,me);       
   
        if (me->is_fighting(target)){
      weapon->unequip(); 
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                          message_vision(HIY"                                                                     ※※※※※※※\n"NOR,me);       
                          message_vision(HIY"                                                                     ※※  蛇  ※※\n"NOR,me);       
                          message_vision(HIY"                                                                     ※※※※※※※\n"NOR,me);       
      weapon->wield();
                                    }

        if (me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                          message_vision(HIY"                                                                     ※※※※※※※\n"NOR,me);       
                          message_vision(HIY"                                                                     ※※  狂  ※※\n"NOR,me);       
                          message_vision(HIY"                                                                     ※※※※※※※\n"NOR,me);       
        if (me->is_fighting(target)){
              weapon->unequip(); 
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                          message_vision(HIY"                                                                     ※※※※※※※\n"NOR,me);       
                          message_vision(HIY"                                                                     ※※  舞  ※※\n"NOR,me);       
                          message_vision(HIY"                                                                     ※※※※※※※\n"NOR,me);       
              weapon->wield();

target->delete_temp("must_be_hit");
                                    } 
}  

else if( me->query_temp("zfup")) {
       message_vision(HIC"\n突然$N绕着$n快速奔走，猛然击出两剑一掌！\n"NOR,me,target);
       me->start_perform(4,"「金蛇狂舞」");
              if (me->is_fighting(target))  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
              if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
              if (me->is_fighting(target)) {
                 weapon->unequip(); 
                COMBAT_D->do_attack(me, target, 0, 3);
                 weapon->wield();     }
}       

if (me->query_temp("sfup")){
                me->add_temp("apply/dexerity",-sf /10);      
                me->add_temp("apply/attack",   -sf /4); 
                   }
if (me->query_temp("zfup")){  
                me->add_temp("apply/strength", -zf/10);
                me->add_temp("apply/damage", -zf/ 6);
                   }
if( me->query_temp("jfup")){
                me->add_temp("apply/sword",     - lvl/4);
                me->add_temp("apply/parry",      - lvl/4);
                me->add_temp("apply/damage",  - lvl/6);
                   }

       me->delete_temp("sfup");
       me->delete_temp("jfup");
       me->delete_temp("zfup");
       me->delete_temp("jsj");
            me->add_temp("apply/damage", -lvl /6);
            me->add_temp("apply/attack", -lvl /4);
            me->add_temp("apply/dexerity",-sf /10);  
            me->start_busy(1+random(2));
            target->start_busy(1);

           return 1;
 }


int help(object me)
{
        write(HIY"\n金蛇秘籍之「金蛇狂舞」："NOR"\n\n");
        write(@HELP
        金蛇郎君夏雪宜所流传下来的的绝世武功. 可惜在争夺中金蛇秘籍被
        分割成好几部分, 金蛇狂舞的威力也大不如前. 相传在凑齐金蛇秘籍
        中的剑法, 身法, 掌法后才能发挥金蛇狂舞真正的威力. 如果有幸可
        以获得金蛇剑, 可使其威力更上层楼.

        要求：  当前内力 1500 以上；　最大内力 2800 以上；
                后天身法臂力大于27
                第一阶段：金蛇剑法等级 120 以上；基本内功等级 170 以上；
                　　　　　激发剑法为金蛇剑法；
                第二阶段：金蛇掌法等级 120 以上；激发准备掌法为金蛇掌法；
                第三阶段：五毒阎罗步等级 120 以上；激发轻功为五毒阎罗步；
                
                另外，如果装备了金蛇剑或者银蛇剑，威力可更上一层楼．

HELP
        );
        return 1;
}

string perform_name(){ return HIC"金蛇狂舞"NOR; }
