// guifei 贵妃回眸
// 重新写了哈哈---by daidai
/*
     洪夫人身子微曲，纤腰轻扭，右足反踢，向教主小腹踹去。教主后缩相避，
洪夫人顺势反过身来，左手搂住教主的头颈，右手竟已握住了匕首，剑尖对准了
教主后心，笑道：“这是第一招，叫做‘贵妃回眸’，你记住了。”

*/
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <combat_msg.h>

string perform_name(){ return HIR"贵妃回眸"NOR; }

int perform2(object me, object target);

int perform(object me, object target)
{
        object weapon;
        string msg,dodge_skill;
 int ap,dp,damage,effect;
 	 
        if(!target) target = offensive_target(me);

        if(!target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("「贵妃回眸」只能在战斗时使用！\n");

        if(userp(me) && me->query("family/master_id")!="hong antong")
                return notify_fail("「贵妃回眸」只有拜了教主后才能用！\n");

        if(!objectp(weapon=me->query_temp("weapon"))
        || weapon->query("skill_type") != "dagger")
             return notify_fail("你手上没有匕首，如何使用「贵妃回眸」。\n");
	
        if((int)(me->query("dex")+me->query_skill("dodge",1)/10) < 30 )
                return notify_fail("你身法不够，使用「贵妃回眸」，恐怕会伤到自己！\n");

        if((int)me->query_skill("tenglong-bifa", 1) < 150 )
                return notify_fail("你的腾龙匕法还不够熟练，不能使用「贵妃回眸」！\n");
	if((int)me->query_skill("shenlong-tuifa",1) < 150)
		return notify_fail("你的神龙腿法不够熟练，不能使用「贵妃回眸」！\n");
	
        if(me->query_skill_mapped("dagger") != "tenglong-bifa")
                return notify_fail("只有使用腾龙匕法时才能使用「贵妃回眸」！\n");

	if(me->query_skill_mapped("leg") != "shenlong-tuifa"
	|| me->query_skill_prepared("leg") != "shenlong-tuifa")
		return notify_fail("你现在没有做好准备，无法使用「贵妃回眸」！\n");
		
        if( (int)me->query_skill("dulong-dafa", 1) < 150 )
                return notify_fail("你的毒龙大法功力不足，不能用「贵妃回眸」。\n");

        if((int)me->query("jingli", 1) < 400)
                return notify_fail("你现在精力不足，不能使用「贵妃回眸」！\n");

        if((int)me->query("neili", 1) < 800)
                return notify_fail("你现在内力不足，不能使用「贵妃回眸」！\n");

        /* if(me->query("gender") == "男性" )
                return notify_fail("不是女人怎么能使用「贵妃回眸」呢！\n");
*/
 //取消使用限制  
     if( me->query_skill_mapped("force") != "dulong-dafa")
                return notify_fail("你现在所使用的内功同毒龙大法相互抵触，不能使用「贵妃回眸」。\n");

        
        message_vision( HIR"\n$N乘$n稍稍走神之机，拼尽全力使出苏夫人不传之绝技－－「贵妃回眸」！"NOR,me,target);
   if(me->query("gender") == "男性" )
   message_vision(MAG"\n$N身子微曲，水桶般的粗腰猛的一扭，右足反踢，向$n小腹踹去。\n"NOR,me,target);
  else    message_vision( MAG"\n$N身子微曲，纤腰轻扭，右足反踢，向$n小腹踹去。\n"NOR,me,target);
  	me->receive_damage("neili",300);
  	me->receive_damage("jingli",150);


   ap = me->query_skill("tenglong-bifa",1)*me->query_dex();
   dp = target->query_skill("dodge",1)* target->query_dex();
  if( target->is_busy() ) dp= dp/2;
 if(random(ap)>dp/4)
 		{
 			effect = SKILL_D("dulong-dafa")->force_effect(target->query_skill_mapped("force"));
                        damage = (me->query_skill("force")+me->query("jiali"))*5;
 			damage *= (5-effect);
 		//	if(damage>3000)
 		//		damage = 2800+random(damage-2000)/5;
 			target->receive_damage("qi",damage,me);
 			target->receive_wound("qi",damage/3,me);
	msg = HIY"\n$n闪避不及，被$N一脚踢中，面色立刻变的惨白！\n"NOR;	
	msg += damage_msg(damage, "瘀伤");
       message_vision(msg,me,target);
	COMBAT_D->report_status(target);

if ( me->is_fighting(target)){
 message_vision( HIY"\n$N再顺势反过身来，咯咯轻笑数声，左手向着$n的头顶轻轻拂去。\n"NOR,me,target);
	perform2(me, target);}	}

else
 		{
                	dodge_skill = target->query_skill_mapped("dodge");
                	if( !dodge_skill ) dodge_skill = "dodge";
                	msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
 
if ( me->is_fighting(target))
     {          msg += HIY"\n$n后缩避过，$N顺势反过身来，咯咯轻笑数声，左手向着$n的头顶轻轻拂去！\n"NOR;	 	 
 message_vision(msg,me,target);
 perform2(me, target);}  
     	}

 me->start_perform(4,"「贵妃回眸」");
	return 1;
}


int perform2(object me, object target)
{
  object weapon; 

 int ap,dp,lvl;  
      if(!target) target = offensive_target(me);

        if(!target
        || !target->is_character()
        || !me->is_fighting(target) )
                return 0;
if((int)me->query("jingli", 1) < 200)
                return 0;
if((int)me->query("neili", 1) < 400)
                return 0;
weapon=me->query_temp("weapon");
 lvl = me->query_skill("tenglong-bifa",1);

ap = me->query_skill("tenglong-bifa",1)*me->query_dex();
dp = target->query_skill("dodge",1)* target->query_dex();
  if( target->is_busy() ) 
    dp= dp/2; 
if(random(ap)>dp/2)
{
      message_vision( MAG"$n被$N搂住头顶，只觉得心中一荡，神情迷糊之间却没发觉到$P右手竟已握住了"+weapon->name()+MAG"！\n"NOR,me,target); 
 target->add_busy(2);  
        me->add_temp("apply/attack",lvl);
        me->add_temp("apply/damage",lvl/2);
        me->add_temp("apply/strength",lvl/8);
        me->set_temp("sld/pfm/guifei",1); 
      
COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
     


    if ( me->is_fighting(target) && me->query_skill("tenglong-bifa",1) > 300)  {
weapon->unequip();
   COMBAT_D->do_attack(me,target,0,3);
     weapon->wield();
 }    
    me->delete_temp("sld/pfm/guifei"); 

        me->add_temp("apply/damage",-lvl/2);
        me->add_temp("apply/attack",-lvl);
        me->add_temp("apply/strength",-lvl/8);
        me->add("neili",-250);
  	 me->add("jingli",-130);
 
} 

else {  
switch(random(2)){
                	case 2: message_vision( HIC"$n虽然缩头躲过，狼狈之余使出的招式略见滞涩！\n"NOR,me,target); 
                   target->add_temp("lost_attack", 2+random(2));	
                   target->apply_condition("no_perform",1);
                   break;
                	case 1: message_vision( HIC"$n虽然缩头躲过，却也心下大震，数招之间手忙脚乱，不成章法！\n"NOR,me,target);  
                  target->add_busy(random(2) + 1);
                   target->apply_condition("no_fight",1);

                   break;
                   default:  message_vision( HIC"$n虽然缩头躲过，狼狈之余使出的招式略见滞涩！\n"NOR,me,target); 
                  target->add_temp("lost_attack", 2+random(2)); 
                  target->add_busy(1);
                   break;
                } me->add("neili",-150);
  	me->add("jingli",-50);
 }
}
/*
 int help(object me)
 {   write(WHT"\n腾龙匕法「"HIR"贵妃回眸"WHT"」："NOR"\n");
    write(@HELP

     要求：当前内力 1500 以上；
           当前精力 800 以上；
           腾龙匕法等级 150 以上；
           毒龙大法等级 150 以上；
           后天身法 30 以上。
 HELP
    );
    return 1;
}

*/