// riyue 日月鞭-日月
// campsun

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{

        int i = me->query_skill("riyue-bian", 1) /2;
     
        int j = me->query("jiali") + 20;//原来是10
   
        string msg,dodge_skill;

     object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("「日月轮转」只能在战斗中对对手使用。\n");

        if (!weapon || weapon->query("skill_type") != "whip")
                return notify_fail("手中没有武器,如何使用「日月轮转」！\n");

        if( (int)me->query_skill("riyue-bian", 1) < 180 )
                return notify_fail("你的日月鞭法不够娴熟，不会使用「日月轮转」。\n");

        if( (int)me->query_skill("yijin-jing", 1) < 180 )
                return notify_fail("你的易筋经等级不够，不能使用「日月轮转」。\n");

        if( (int)me->query_skill("buddhism", 1) < 180 )
                return notify_fail("你的禅宗心法等级不够，不能使用「日月轮转」。\n");
          
        if( (int)me->query("max_neili") < 2500 )
          return notify_fail("你现在内力修为太弱，不能使用「日月」。\n");
      
        if( (int)me->query("jingli") < 500 )
          return notify_fail("你现在体力太少，不能使用「日月」。\n");
       
        if ( me->query_skill_mapped("parry") != "riyue-bian")
          return notify_fail("你招架不对，不能使用「日月」。\n");
    
        if ( me->query_skill_mapped("force") != "yijin-jing")
          return notify_fail("你必须使用少林心法才能催动「日月轮转」。\n");
               
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你现在内力太弱，不能使用「日月」。\n");

        msg = HIC "$N口中高宣佛号，使出日月鞭中「日月轮转」绝技，手中长索滚动飞舞，宛若灵蛇乱颤，自上而下劈向$n,\n" NOR;
        msg += HIC "接着$N手腕一抖，便如张牙舞爪的墨龙相似，急升而上，又往$n扑到。\n"NOR;
        message_vision(msg, me, target);
   
         me->set_temp("ryb_riyue", 1);
         me->add_temp("apply/attack", i);
         me->add_temp("apply/damage", j);
  
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
    
    if( me->is_fighting(target) ) 
    	   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    
    if( me->is_fighting(target) && (int)me->query_skill("riyue-bian", 1) > 220)  
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/damage", -j);
        me->add_temp("apply/attack", -i);
 if(me->is_fighting(target) ){
 	
 if(random(10)<5) {          
        msg = HIY"\n紧跟着$N高宣“阿弥陀佛！”，使出「日 轮 」字诀，手中长索一扬，向$n的咽喉点去，索头未到，索上所挟\n"
                 + "劲风犹如红日当空，令对方一阵气窒，只听见「啪啪」几声巨响，索头昂起，便如一条假死的毒蛇忽地反\n"
                 + "噬挥动，带动无数风沙，呼啸而出。\n"NOR; 
        message_vision(msg, me, target);
              
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      if( me->is_fighting(target) ) 
  	         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        me->delete_temp("ryb_riyue");      
        me->add("neili", -400);
        me->start_busy(2+random(2));

        }
        
        
   else { 
          msg = HIC "\n紧跟着$N又宣“我佛慈悲！”，使出「月 转」字诀，内力返照空明，功力精纯，不露棱角，手中长索舞动时\n"
                     +"瞧不见半点影子无声无息，似缓实急，却又无半点风声，如鬼似魅，说不尽的诡异莫名。\n"NOR;
        message_vision(msg,me,target);
      
        if (random(10)>6) 
                {
                         msg=HIR"结果$N一不小心，登时淹没在漫天鞭影之中。\n"NOR;
                   message_vision(msg,target);        
                   me->delete_temp("riyue");      
                   target->start_busy(2+random(2));
                   me->add("neili",-400);
                 }
        else {
                dodge_skill = target->query_skill_mapped("dodge");
               if( !dodge_skill ) dodge_skill = "dodge";
                     msg=HIR"$N见势不好，抽身急退，躲过了漫天鞭影。\n"NOR;
                   message_vision(msg,target);        
         me->delete_temp("ryb_riyue");      
        me->start_perform(5, "「日月轮转」");
                me->add("neili",-200);
                }
        }
       
  }      
        me->delete_temp("ryb_riyue");      
return 1;

}

string perform_name(){ return HIC"日月轮转"NOR; }
int help(object me)
{
	write(HIC"\n日月鞭「日月轮转」："NOR"\n");
	write(@HELP
	
	要求：	最大内力 2500 以上；      
		当前内力 1000 以上； 
		当前精力 500 以上； 
		易筋经等级 180 以上；
		日月鞭法等级 180 以上；
		禅宗心法等级 180 以上；
		激发日月鞭法为招架；
		激发易筋经为内功；
		装备长鞭类兵器。     
HELP
	);
	return 1;
}

