// Modified by snowman@SJ 05/12/2000
// Update By lsxk@hsbbs 2007/6/14

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

void remove_effect(object me, int improve);

string perform_name() {return HIR"一指点三脉"NOR;}

int perform(object me, object target)
{
        int lev;
        
        if( !target ) target = offensive_target(me);

         if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target) 
         || !living(target) )
                return notify_fail("「一指点三脉」只能在战斗中使用。\n");

        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「一指点三脉」！\n");   

        if( (int)me->query_skill("yiyang-zhi", 1) < 120 )
                return notify_fail("你的一阳指还不够娴熟，使不出「一指点三脉」绝技。\n");

        if((int)me->query_skill("force",1) < 120 ) 
                return notify_fail("你的内功修为还不够，使不出「一指点三脉」绝技。\n");

        if( me->query_temp("pf_rong"))
                return notify_fail("你正在运用「荣」字大法！\n"); 

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) < 120)
                return notify_fail("以你现在的内功修为还使不出「一指点三脉」。\n");        

        if (me->query_skill_prepared("finger") != "yiyang-zhi" 
         || me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("你现在无法使用「一指点三脉」！\n"); 

        if (me->query_skill_mapped("force") != "kurong-changong" )
          if(me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("你所使用的内功不对。\n");                

        if( (int)me->query("max_neili") < ((int)me->query_skill("force",1)+1000) )
                return notify_fail("你现在内力太弱，使不出「一指点三脉」。\n");      

        if( (int)me->query("neili") < ((int)me->query_skill("force",1)+1100) )
                return notify_fail("你现在真气太弱，使不出「一指点三脉」。\n");

        if( (int)me->query("jingli") < ((int)me->query_skill("force",1)+ 800) )
                return notify_fail("你现在精力太少，使不出「一指点三脉」。\n");

        lev = (int)me->query_skill("yiyang-zhi", 1)/4;
        
        if(!userp(me)) lev = lev *2 /3 ;
         if(userp(me)) lev = lev * 2 ;
        message_vision(HIR"\n$N出指舒缓自如，收臂潇洒飘逸，手臂颤动，犹如蜻蜓点水，一指点出，竟分袭三道大脉，快捷无伦！\n"NOR,me,target);

        me->add_temp("apply/strength", lev /5);
        me->add_temp("apply/attack", lev);
        me->add_temp("apply/damage", lev * 2);
        me->add_temp("apply/finger", lev);


        me->set_temp("yyz/yz3m",3);
if(!userp(target)&& lev>=251) target->start_busy(2);
         COMBAT_D->do_attack(me, target, 0, 3);
        me->add_temp("yyz/yz3m",-1);
 
if( me->is_fighting(target)) {
         COMBAT_D->do_attack(me, target, 0, 3);
            me->add_temp("yyz/yz3m",-1);
        }

if( me->is_fighting(target) && (int)me->query_skill("yiyang-zhi",1) > 199 ) {
      	 COMBAT_D->do_attack(me, target, 0, 3);
	    me->add_temp("yyz/yz3m",-1);
        }

        me->start_busy(1);
        me->delete_temp("yyz/yz3m");

        me->add_temp("apply/strength", -lev /5);
        me->add_temp("apply/attack", -lev);
        me->add_temp("apply/damage", -lev * 2);
        me->add_temp("apply/finger", -lev);

        me->add("neili", -300);
        me->add("jingli", -100);
        me->start_perform(5,"「一指点三脉」");
        return 1;
}




int yzsm_attack(object me, int flag)
{
        object target;
        int lev;
        
        if( !target ) target = offensive_target(me);

         if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target) 
         || !living(target) )
                return notify_fail("「一指点三脉」只能在战斗中使用。\n");

        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「一指点三脉」！\n");   

        if( (int)me->query_skill("yiyang-zhi", 1) < 120 )
                return notify_fail("你的一阳指还不够娴熟，使不出「一指点三脉」绝技。\n");

        if((int)me->query_skill("force",1) < 120 ) 
                return notify_fail("你的内功修为还不够，使不出「一指点三脉」绝技。\n");

        if( me->query_temp("pf_rong"))
                return notify_fail("你正在运用「荣」字大法！\n"); 

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) < 120)
                return notify_fail("以你现在的内功修为还使不出「一指点三脉」。\n");        

        if (me->query_skill_prepared("finger") != "yiyang-zhi" 
         || me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("你现在无法使用「一指点三脉」！\n"); 

        if (me->query_skill_mapped("force") != "kurong-changong" )
          if(me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("你所使用的内功不对。\n");                

        if( (int)me->query("max_neili") < ((int)me->query_skill("force",1)+1000) )
                return notify_fail("你现在内力太弱，使不出「一指点三脉」。\n");      

        if( (int)me->query("neili") < ((int)me->query_skill("force",1)+1100) )
                return notify_fail("你现在真气太弱，使不出「一指点三脉」。\n");

        if( (int)me->query("jingli") < ((int)me->query_skill("force",1)+ 800) )
                return notify_fail("你现在精力太少，使不出「一指点三脉」。\n");

        lev = (int)me->query_skill("yiyang-zhi", 1)/4;
        
        if(userp(me))  lev = lev * flag;
            


        message_vision(HIR"\n$N出指舒缓自如，收臂潇洒飘逸，手臂颤动，犹如蜻蜓点水，一指点出，竟分袭三道大脉，快捷无伦！\n"NOR,me,target);

        me->add_temp("apply/strength", lev /10);
        me->add_temp("apply/attack", lev/ 2);
        me->add_temp("apply/damage", lev);
        me->add_temp("apply/finger", lev);


        me->set_temp("yyz/yz3m",3);
        
         COMBAT_D->do_attack(me, target, 0, 3);
        me->add_temp("yyz/yz3m",-1);
 
if( me->is_fighting(target)) {
         COMBAT_D->do_attack(me, target, 0, 3);
            me->add_temp("yyz/yz3m",-1);
        }

if( me->is_fighting(target) && (int)me->query_skill("yiyang-zhi",1) > 199 ) {
      	 COMBAT_D->do_attack(me, target, 0, 3);
	    me->add_temp("yyz/yz3m",-1);
        }

        me->start_busy(1);
        me->delete_temp("yyz/yz3m");

        me->add_temp("apply/strength", -lev /10);
        me->add_temp("apply/attack", -lev/ 2);
        me->add_temp("apply/damage", -lev);
        me->add_temp("apply/finger", -lev);

        me->add("neili", -300);
        me->add("jingli", -100);
        me->start_perform(5,"「一指点三脉」");
        return 1;
}















int help(object me)
{
   write(WHT"\n一阳指之「"HIR"一指点三脉"WHT"」："NOR"\n\n");
   write(@HELP

     要求: 最大内力大于基本内功1000点以上；
           当前内力大于基本内功1100点以上；
           当前精力大于基本内功800点以上；
           一阳指等级 120 以上；
           基本内功等级 120 以上；
           特殊内功等级 120 以上；
           激发指法为一阳指；
           空手，备一阳指。

           如设置 set 一阳指点穴 则威力更甚。

HELP
   );
   return 1;
}
