///kungfu/skill/haotian-zhang/lianhuan.c 重阳连环掌
// Modified by action@SJ 2008/09/15
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
string perform_name(){ return HIR"重阳连环掌"NOR; }

void remove_effect(object me, int improve);

int perform(object me, object target)
{
        int lv, i, hit,j;
        string weapon, htz_msg;

        if( !target ) target = offensive_target(me);

         if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("「重阳连环掌」只能在战斗中使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「重阳连环掌」！\n");   
                
        if( (int)me->query_skill("haotian-zhang", 1) < 100 )
                return notify_fail("你的重阳神掌还不够娴熟，使不出「重阳连环掌」绝技。\n");
                
        if (me->query_skill_prepared("strike") != "haotian-zhang"
            || me->query_skill_mapped("strike") != "haotian-zhang")
                return notify_fail("你现在无法使用「重阳连环掌」进行攻击。\n");  

        if( (int)me->query_skill("xiantian-gong", 1) < 100 )
                return notify_fail("你的先天功等级还不够，使不出「重阳连环掌」绝技。\n");
                
        if (me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("你的内功有误，无法使用「重阳连环掌」。\n");               
		            
        if( me->query("max_neili") < 1000 )
                return notify_fail("你现在内力太弱，使不出「重阳连环掌」。\n"); 
                     
        if( (int)me->query("neili") < 800 )
                return notify_fail("你现在真气太弱，使不出「重阳连环掌」。\n");
      
        
        lv = me->query_skill("haotian-zhang",1);

if(!userp(me)) lv = lv / 2;

        hit = (lv/80);
        if(hit > 7) hit = 7;
        if(hit <2) hit = 2;

        me->add_temp("apply/attack",    lv/2);
        me->add_temp("apply/damage", lv /4);
        htz_msg = HIC"\n$N默运先天功，但见天空";

        if(hit >= 1)htz_msg += "「"HIR"天璇星"HIC"」";
        if(hit >= 2)htz_msg += "、「"HIG"天枢星"HIC"」";
        if(hit >= 3)htz_msg += "、「"HIY"天玑星"HIC"」";
        if(hit >= 4)htz_msg += "、「"HIB"天权星"HIC"」";
        if(hit >= 5)htz_msg += "、「"HIM"玉衡星"HIC"」";
        if(hit >= 6)htz_msg += "、「"HIC"开阳星"HIC"」";
        if(hit >= 7)htz_msg += "、「"HIW"摇光星"HIC"」";
        
        htz_msg += "星光下泄，"+chinese_number(hit)+"星微微一闪，\n这昊天掌力竟已能引动北斗星力，当真威力无比！\n"NOR;

        message_vision(htz_msg, me, target);
        me->set_temp("htz_times",hit);
        me->set_temp("htz_effect",1);
        me->add_temp("htz/lianhuan", 3);
        me->set_temp("action_flag", member_array("strike", keys(me->query_skill_prepare())));

//昊天掌飞跃        
if( me->query("str",1)>=45 && userp(me)){
	                  me->set_temp("htzup",1);
	          if(!userp(target)) 	 target->set_temp("must_be_hit",1);
		          target->add_temp("apply/defense",-2000);
	   message_vision(HBBLU"\n只见$N先天真气引动周天星斗光华，举手投足之间竟有丝缕星光飞烁，威力更是大增！\n"NOR, me, target);
		}
		

if (me->query("quanzhen/force") =="pass" )  target->add_busy(2);
		
        for( i=0; i < hit; i++ )
        {
                me->add_temp("htz/lianhuan", 1);
          if (me->is_fighting(target))          COMBAT_D->do_attack(me, target, weapon, (lv<450)?1:3);
  
        }
        



       message_vision(HIC"\n这"+chinese_number(hit)+"招重阳连环掌，暗含周天星斗运转轨迹，变化无穷，鬼神难测！\n"NOR, me);


if(me->query_temp("htzup")) {
	   if(target) {


      message_vision(HBRED"\n只见$N顿悟「天运无穷，三光迭耀，而极星不移」之奥妙，当下抢占北极星位，轻轻一掌按向$n。\n"NOR, me, target);
                          target->start_busy(2);    

j = target->query("str");
if (j < 50) j =  target->query("con");
if (j < 50) j =  target->query("dex");
if (j < 50) j =  target->query("int");

           if( random(me->query("str",1)) > target->query("str",1)/2 
          && random(me->query("combat_exp",1)/10000) > target->query("combat_exp",1)/40000 
          && random(me->query("neili",1)/100 )> target->query("neili",1) /200 && j <50 )
{

     message_vision(HBMAG"那晶莹飞舞的星光忽的一下炸裂开来，竟然全是精纯的先天真气凝聚而成，凛冽如剑，无坚不摧！\n$n猝不及防，当下被穿胸而过，眼看是活不成了！\n"NOR, me, target);
                          target->set("eff_qi",-1);
                          COMBAT_D->report_status(target);
                                                                                }
 else  message_vision(HBMAG"那晶莹飞舞的星光忽的一下炸裂开来，竟然全是精纯的先天真气凝聚而成，凛冽如剑，无坚不摧！\n"+HIG+"$n知这星光怪异，心中早有准备，抽身急退，堪堪躲过，却已经是受伤不轻。\n"NOR, me, target);
                          target->receive_damage("jingli", me->query_skill("haotian-zhang",1)*3+ random(me->query_skill("haotian-zhang",1))*3, me);
	           	  target->delete_temp("must_be_hit");
		          target->add_temp("apply/defense",2000);
                          
		            } 
		                      }

		     
        me->add("neili", -hit*20+20);
        me->add("jing", -hit*5);
        me->start_perform(3+random(2),"「重阳连环掌」");
        me->start_busy(1+random(2));
        me->delete_temp("htz/lianhuan");
        me->delete_temp("htz_times");
        
        me->delete_temp("htzup");
        
        me->add_temp("apply/attack",   - lv/2);
        me->add_temp("apply/damage", -lv /4);
        return 1;
}


int help(object me)
{
        write(HIR"\n重阳神掌之「重阳连环掌」："NOR"\n");
        write(@HELP
       昊天掌为全真教王重阳独创，招式凌厉无比，犹如星斗变换，日月暗淡。

        要求：  最大内力 3000 以上；      
                当前内力 1000  以上；  
                昊天掌等级 100 以上；
                先天功等级 100 以上；
                激发掌法为昊天掌；
                激发招架为昊天掌；
                等级越高威力越大；
                且手无兵器；
                先天臂力>=45后有额外攻击加成
                
HELP
        );
        return 1;
}


