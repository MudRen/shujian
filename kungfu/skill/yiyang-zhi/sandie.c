// /kungfu/skill/yiyang-zhi/sandie.c
// COOL@SJ
// Modified by snowman@SJ 05/12/2000

#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>
#include <combat.h>
 
string perform_name() {return YEL"阳关三叠"NOR;}

int perform(object me, object target)
{       
        string msg;
        int damage;
        
        if( !target ) target = offensive_target(me);
 
        if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target))
                return notify_fail("「阳关三叠」只能在战斗中使用。\n");
        if( !living(target) )
        	return notify_fail("对方已经晕过去了。\n");
        	
        if( objectp( me->query_temp("weapon")) )
                return notify_fail("只有空手才能施展「阳关三叠」。\n");

        if((int)me->query_skill("yiyang-zhi", 1) < 100 
         ||(int)me->query_skill("finger", 1) < 100 
         ||(int)me->query_str() < 25)
                return notify_fail("你有的功夫还不够娴熟，不会使用「阳关三叠」。\n");

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) <100)
                return notify_fail("以你现在的内功修为还使不出「阳关三叠」。\n");        
         
        if (me->query_skill_mapped("force") != "kurong-changong" )
        if (me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("你所使用的内功不对。\n");

        if (me->query_skill_prepared("finger") != "yiyang-zhi" 
         || me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("你现在无法使用「阳关三叠」进行攻击。\n");
 
        if(me->query_temp("start_6mai"))
                return notify_fail("你已经在运用六脉神剑的无形剑气了！\n");

        if (me->query_skill_mapped("parry") != "kurong-changong" )
           if (me->query_skill_mapped("parry") != "yiyang-zhi")
                return notify_fail("你所使用的招架不对。\n");

        if((int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力修为太弱，不能使用「阳关三叠」！\n");

        if((int)me->query("neili") < 800 )
                return notify_fail("你的真气不够！\n");
               
    
                if((string)me->query("class")=="bonze")
           	msg = YEL "\n$N双掌合什，口中低诵佛号，凝气于指，一式「破煞」点出，但听得嗤的一声轻响，一股纯阳的内力直袭$n胸口！\n" NOR;
        else if ((string)me->query("class")=="officer")
           	msg = YEL "\n$N使出「阳关三叠」绝招，须发飞舞, 威猛之极，大喝一声「破煞」,一指点出，但听得嗤嗤有声，一股纯阳的内力直袭$n胸口！\n" NOR; 

        else msg = YEL "\n$N使出「阳关三叠」绝招，大喝一声「破煞」,一指点出，但听得嗤嗤有声，一股纯阳的内力直袭$n胸口！\n" NOR; 

        
 if( random( me->query("combat_exp") ) > target->query("combat_exp")/2  
        || target->is_busy() 
        || me->query("env/一阳指") == "破煞" 
     )
         {
             	damage =(int)me->query_skill("kurong-changong", 1) * 3 + (int)me->query_skill("finger",1) * 3 + (int)me->query_skill("qiantian-yiyang", 1) * 3;
             	damage += (int)me->query_skill("kurong-changong", 1);

             	if( random(me->query("neili")) > target->query("neili")/2 )
                     	damage += random(me->query("jiali"))*2;
                if (me->query("max_neili") > target->query("max_neili")*2 ) 
                       	damage *= 2;
                       	
        	damage = random(damage)+damage;

               if(!userp(me)) damage = damage / 3;
               
            	target->receive_damage("qi", damage, me);
            	target->receive_wound("qi", damage/3, me);               
            	me->add("neili", -(damage/5));
            	msg += damage_msg(damage, "内伤")+
        	"( $n"+eff_status_msg((int)target->query("qi")*100/(int)target->query("max_qi"))+" )\n"; 

              if(me->query_skill("yiyang-zhi", 1) >=140)
            	{      	me->start_perform(5, "三叠");
                   	call_out("perform2",1,me, target);       
                }
                else me->start_perform(4, "破煞");
	}
else
        {
                me->start_busy(2);
                me->add("neili", -70);                
                msg += HIY"$p听得指力袭来，知道无法硬挡，一个巧云翻身，远远的躲了开去。\n"NOR;
              if(me->query_skill("yiyang-zhi", 1) >= 140)
                        { 
                    	me->start_perform(5, "三叠");
                    		call_out("perform2", 1, me, target);
        	        }
                else me->start_perform(4, "破煞");
	}        
        message_vision(msg, me, target);
            	
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"HIR+ damage+ WHT"点攻击伤害。\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"HIR+ damage+ WHT"点伤害。\n"NOR);
 
       return 1;
}

int perform2(object me, object target)
{
        int f,i;
        string msg;
        
	if (!me ) return 0;        
        
        if( !living(me) ) return 0;
        
        if(!target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
               return notify_fail("你正要发一招，却见对手已经不用打了。\n");;

        if((int)me->query("neili", 1) < 400 )
               return notify_fail("你待要发出一指，却发现自己的内力不够了！\n");;    

        if( (int)me->query_skill("yiyang-zhi", 1) < 140)               
               return notify_fail("你的一阳指修为不够，无发使出「阳关三叠 之 惊神」。\n");;
     
   
 
        f = (int)me->query_skill("yiyang-zhi",1);
          
        
        if( target->is_busy() ){
          	msg = YEL "\n紧跟着$N一阳指第二次点出，反手一指，一式「惊神」点出，但听得嗤的一声轻响，一股纯阳的指力透入$n体内任脉紫宫穴！\n" NOR;
          	i = 2+random(2);
        }
        else {
   	msg = YEL "\n紧跟着$N一阳指第二次点出，以纯阳内力，同时透入$n体内任脉紫宫穴、阴维脉大横穴、冲脉幽门穴、带脉章门穴和阴跤脉晴明穴！\n"NOR;        
          	i = 2;
        }


 if( random(me->query_skill("force")) > target->query_skill("force")/i
   || me->query("env/一阳指") =="惊神" 
)
         {
        	
                me->add("neili", -f/2);
                msg += HIR "$n只觉一股灼热之气侵入体内奇经八脉,全身上下暖洋洋的，竟然提不起一丝力气！\n" NOR;
                target->add_temp("apply/attack", -f/6);
                target->add_temp("apply/dodge", -f/6);
                target->add_temp("apply/parry", -f/6); 
                target->add_temp("apply/strength", -f/6); 
                if( random(2) ) 

                 	target->apply_condition("no_exert", 2);
                else  
                 	target->apply_condition("no_perform", 2);
                 target->add_busy(random(2)+1);
                 	
                target->set_temp("sandie/jingshen",f/6);

     call_out("sandie_back", 5+random(20), target, f/6);

                if((int)me->query_skill("yiyang-zhi", 1) >= 180 )
                {
                 	remove_call_out("perform3");
                 	call_out("perform3", 1, me, target);
                 }
        }



 else{
   
               me->add("neili", - 100);
                msg += HIY"\n两人身形一合瞬间分开,却见$p运起独门内功，消去了攻入体内的一阳指劲。\n" NOR;
                if((int)me->query_skill("yiyang-zhi", 1) >= 180)
                {
                  	call_out("perform3", 1, me, target);
                 }
        }
        me->start_perform(4, "惊神");     
        message_vision(msg, me, target);


        return 1;
}



int perform3(object me, object target)
{
       
        int i,j;
 	string msg;
	if( !me ) return 0;

	if( !living(me) ) return 0;
	
	if(!target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
               return notify_fail("你正要发一招，却见对手已经不用打了。\n");

        if((int)me->query("neili", 1) < 300 )
		return notify_fail("你待要发出一指，却发现自己的内力不够了！\n");

        if( (int)me->query_skill("yiyang-zhi", 1) < 180)
               return notify_fail("你的一阳指修为不够，无发使出「阳关三叠 之 截天」。\n");
        
                j= me->query_skill("yiyang-zhi",1);
        i = j /35;
     
        if(i>5) i=5; 
   
	me->start_perform(5, "截天");

       msg = YEL"\n接着$N踏前一步，出第三指「截天」隔空点向$n胸前“玉堂穴”，认穴竟无厘毫之差！\n"NOR;

        if( random(me->query_skill("parry")) > target->query_skill("parry")/3 
             || me->query("env/一阳指") =="截天" 
          ){
       msg += HIR "结果一指点中，$n只觉得气脉通道阻塞，真气立受干挠！\n"NOR;
                target->start_busy( i );
                target->add("neili", -me->query_skill("force"));
                me->add("neili", -(me->query_skill("force")/3));
             
             if( (i >=5  && userp(me))
                 || ( random(10)> 5 && me->query("env/一阳指") =="三叠") 
                 )
                  {
          	msg += HIM"\n$N潜运内力，面色波澜不惊！\n"NOR;
                          me->start_call_out( (: call_other, __DIR__"yizhisanmai", "yzsm_attack", me, 2 :), 1 );
                   }
  }
       
         else {
               	me->start_busy(1+random(2));
                me->add("neili", -200);
                target->add("neili", -random(100));
                msg += HIY"\n$p听得指力袭来，知道无法硬挡，便也隔空一击，两股力道相碰，$p顺势跳了开去。\n" NOR;
               }


        message_vision(msg, me, target);
        return 1;
}

void sandie_back(object target, int i)
{        
        if( !target ) return;
        target->add_temp("apply/attack", i);
        target->add_temp("apply/dodge", i);
        target->add_temp("apply/parry", i); 
        target->add_temp("apply/strength", i); 
        target->delete_temp("sandie/jingshen");
}



int help(object me)
{
   write(WHT"\n一阳指之「"HIY"阳关三叠"WHT"」："NOR"\n\n");
   write(@HELP
　           渭城朝雨，一霎挹轻尘。
             更洒遍客舍青青，弄柔凝，千缕柳色新。 
             更洒遍客舍青青，千缕柳色新。
             休烦恼，劝君更尽一杯酒，
             人生会少，自古富贵功名有定分，莫遣容仪瘦损。
             休烦恼，劝君更尽一杯酒，
             只恐怕西出阳关，旧游如梦，眼前无故人

       取阳关三叠反复咏叹之意思，连出三指。以破煞伤敌气血，以惊神将一阳指指力送入
       敌人体内造成内伤并封招闭气，削弱敌人防御和招架，降低敌人命中。最后以截天指
       力点穴使之忙乱。出招虽然缓慢，但是一阳指当世无双，威力无比。


  基本要求：一阳指，基本指法各100级以上。
           乾天一阳100级以上 或使用枯荣禅功。
           最大内力1500以上，当前内力800以上。

  设置内容： 
       set 一阳指  破煞   效果为提高破煞命中
                   惊神   效果为提高惊神命中
                   截天   效果为提高截天命中
                   三叠   效果为提高后招的几率


HELP
   );
   return 1;
}




