//dingyang.c 定阳针;
//Modify By jpei
//自一灯处学得定阳针后，需要反复练习才能豁然贯通
//起初标记为try,威力减半
 
#include <ansi.h>
inherit F_SSERVER;
 
string exert_name() {return HIB"定阳针"NOR;}

int exert(object me)
{
        string msg;
        object target;
        int skill, ap, dp, p, force, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("xiantian-gong",1);

        if( !(me->is_fighting() ))
                return notify_fail("「定阳针」只能对战斗中的对手使用。\n");

        if((string)me->query_skill_mapped("force") != "xiantian-gong" )
		  return notify_fail("「定阳神针」乃是道家先天功的绝学！\n");

        if( skill < 220)
                return notify_fail("你的先天功修炼不够, 不能使用「定阳针」！\n");

        if( me->query("neili") < 2000 )
                return notify_fail("你的内力不够，无法运用「定阳针」！\n");

       if( !me->query("quanzhen/force")  )
                return notify_fail("你虽然听说过「定阳针」，但是不知道如何运用。\n");     

        if( me->query("max_neili") < 2500 )
                return notify_fail("你的内力不够，无法运用「定阳针」！\n");
 
         msg = HIY"\n$N默运先天功，以先天真气运用一阳指指法，迎面一指，径直点向$n眉心，正是当年一指点破蛤蟆功的重阳绝技「"HIR"定阳针"HIY"」！。\n"NOR;

        ap = me->query_skill("force",1) + skill;
        dp = target->query_skill("force",1)+ target->query_skill("parry",1);
        if( dp < 1 ) dp = 1;
  	
if( me->query("quanzhen/force")=="try" )
 {        ap = ap/4;
    	msg += HIY"只是$N初学乍练之下，并不能很好的发挥定阳针的威力！\n"NOR;

   if( me->query("kar")<31 && random(me->query("kar"))>26 && random(50)==5 && me->query_skill("xiantian-gong",1)>=350 ){

		      	msg += HBBLU"$N忽然福至心灵，先天功真气由膻中，入缺盆，过阳池外关，交与三焦手少阳之脉，激射而出，豁然贯通！\n"NOR;	     
	           me->set("quanzhen/force","pass");
  me->set("title",HIR"全真教掌教"HIR" "HIC"先天功传人"NOR);
}
 }   
         message_vision(msg, me, target);


   if( random(ap+dp ) > dp ||   ( me->query("str")>30 && random( me->query_str(1)) > target->query_dex(1)/3 ) ||(!userp(target) &&me->query("str") >41) ){
                if(userp(me))   me->add("neili",-(1500+random(500)));
           msg = HIW"\n$n不及躲闪，被$N一指点中！只觉得先天真气透体而入，沛然浩瀚，莫与之敌。当下骇的魂飞魄散！\n" NOR;   
           message_vision(msg, me, target);
      
           p = (int)me->query_skill("force",1) + random(me->query_skill("force",1)*3);

        if( target->query_skill("hamagong",1) >=1 && target->query("oyf/hamagong",1)<3 ){
				target->start_busy(p/10);
				target->add_temp("apply/force", -p);
				target->add_temp("apply/damage", -p);
								target->add_temp("apply/attack", -p);
								target->add_temp("apply/dodge", -p);
								target->add_temp("apply/parry", -p);
							   target->add("neili", -p*200);
				   if( target->query_skill_mapped("force") )         target->map_skill(force); 
				tell_object(target, HIR"你毕生所修蛤蟆功被定阳针一指点破，不由得面如死灰！\n" NOR);
				return 1;
		       	}
      if( target->query_temp("hmg_nizhuan") && target->query("oyf/hamagong",1)==3 ){

         message_vision(HIW "\n$n经脉逆转，杂乱无序，$N一指点去，只觉得如中败革，先天真力如泥牛入海，丝毫不起作用。\n" NOR, me,target);
                target->add_busy(2);
                me->start_exert(1+random(2),"定阳针");
				return 1;
		       	}


                        qi_wound = ap * 2 +random(ap*2) ;
                     neili_wound = ap * 3 +random(ap*3);
                
                if(neili_wound > target->query("neili"))
                   neili_wound = target->query("neili");

                if(qi_wound > target->query("qi"))
                   qi_wound = target->query("qi");


      if( target->query("relife/gifts/total")>=150 ){

         message_vision(HIW "\n孰料$n参悟武学极致，体内真气绵绵不绝流转不休，$N一指点去，只觉得如中败革，威力大减。\n" NOR, me,target);
                target->add("neili", -neili_wound);
                target->add("qi", -qi_wound);
                target->add("eff_qi", -qi_wound*2/3);
                target->add_busy(2);
                me->start_exert(1+random(2),"定阳针");
				return 1;
		       	}

   
  
         if(random(3)== 1)            target->apply_condition("no_perform", 1+ random(2));
         if(random(3)== 1)            target->apply_condition("no_exert", 1+ random(2)); 
         if(random(3)== 1)            target->apply_condition("no_fight", 1+ random(2)); 
                target->add("neili", -neili_wound);
                target->add("qi", -qi_wound);
                target->add("eff_qi", -qi_wound*2/3);
                target->add_busy(2);
                if(target->query_skill_mapped("force") ) target->map_skill("force");

            me->start_exert(2+random(2),"定阳针");
if( me->query_skill("xiantian-gong",1)<=550 )
            me->start_perform(1,"定阳针");
       }

 else
              { 

         msg = YEL"\n$n只觉得$N指力透体而入，先天真气沛然浩瀚，莫与之敌。当下只得飞身后退！\n" NOR;
         message_vision(msg, me, target);
//     if (me->query("quanzhen/force") =="pass" )     target->add_busy(1);
                 me->add_busy(1+random(2));
                me->start_exert(1+random(2),"定阳针");
         }

        return 1;

}
int help(object me)
{
	write(HIC"\n先天功「定阳针」："NOR"\n");
	write(@HELP
 
先天真气之「定阳针」
 
          当年一指点破蛤蟆功的重阳绝技，以先天真气驱动一阳指指力，点破敌人护体真气。
          
	
 要求：	当前内力 2000 以上；
              最大内力 2500 以上；
              先天功 220 级以上；
              得到王重阳先天功真传的弟子可以使用。
              高的臂力和内功等级有额外的效果。 

HELP
	);
	return 1;
}

