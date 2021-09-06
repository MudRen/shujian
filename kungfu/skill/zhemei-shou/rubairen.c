// 空手入白刃  action@SJ 2008/12/28
//modified by zhuifeng@SJFY 2010/07/17

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target,object tweapon)
{
        int i;

        if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("「空手入白刃」只能在战斗中使用。\n");
                
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「空手入白刃」！\n");   
        tweapon = target->query_temp("weapon");
	      if( !tweapon )
		            return notify_fail("对方没有使用任何兵器，你无法使用「挑字诀」。\n");
                
        if( (int)me->query_skill("zhemei-shou", 1) < 200 )
                return notify_fail("你的天山折梅手还不够娴熟，无法使出「空手入白刃」绝技。\n");     
                
        if( (int)me->query_skill("hand", 1) < 200 )
                return notify_fail("你的基本手法还不够娴熟，无法使出「空手入白刃」绝技。\n");   
                
        if( (int)me->query_skill("force", 1) < 200 )
                return notify_fail("你的内功修为不足，无法使出「空手入白刃」绝技。\n");                                                         

        if (me->query_skill_mapped("force") != "bahuang-gong" )
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你所使用的内功不对，无法使出「空手入白刃」。\n");  
                
        if ( me->query_skill_mapped("parry") != "zhemei-shou"
	            && me->query_skill_mapped("hand") != "zhemei-shou")
		            return notify_fail("你现在无法使用「空手入白刃」。\n");
		            
		    if (me->query_skill_prepared("hand") != "zhemei-shou"
	             || me->query_skill_mapped("hand") != "zhemei-shou")
	              return notify_fail("你现在无法使用「空手入白刃」。\n");

        if( (int)me->query_temp("rubairen") > 0 )
                return notify_fail(HIW"你刚刚用过「空手入白刃」，等一会再使用吧。NOR\n"NOR);
                
        if( (int)me->query("max_neili", 1) < 3000 )
                return notify_fail("你现在内力修为不足，无法使出「空手入白刃」。\n");

        if( (int)me->query("neili", 1) < 2000 )
                return notify_fail("你现在内力太弱，无法使出「空手入白刃」。\n");
                
        if( me->query("jingli") < 2000 )
		            return notify_fail("你现在精力不够, 无法使出「空手入白刃」! \n");
		            
        i = me->query_skill("zhemei-shou",1);
        
        if( userp(me)&&tweapon && i > 150 && living(target)
	                   && random(me->query("combat_exp")) > target->query("combat_exp")/2 ) {
	                   	
		message_vision(HIC"$N凝神閉息，使出灵鹫宫絕技「空手入白刃」，双手快速向$n飞动，宛如双蝶飞舞着迅速扣住$n手中"+tweapon->name()+HIW"！\n"NOR, me,target);
		
		    if( random(me->query("str")) > target->query("str")/3 ) {
			        me->add("neili", -500);
			        me->start_perform(2+random(1),"「空手入白刃」");
			        message_vision(HIC"$n只觉一股香气扑鼻而来，頓時覺得眼前一花，手腕一麻，$n手中"+tweapon->name()+HIC"脫手而出！\n"NOR, me,target);
			        tweapon->unequip();
			        tweapon->move(environment(target));
		}
		else {
			message_vision(HIC"可是$n的看破了迷路者的企圖，立刻采取守勢，使$N沒能奪下兵刃！\n"NOR, me,target);
              me->start_perform(3,"「空手入白刃」");
              me->add("neili", -500);
              me->start_busy(1+random(1));
		}
	} 
        return 1;
}

string perform_name(){ return HIC"空手入白刃"NOR; }

int help(object me)
{
	write(YEL"\n天山折梅手之"HIC"「空手入白刃」："NOR"\n");
	write(@HELP
	灵鹫宫天山童姥之绝技。

	要求：
	当前内力 2000 以上；
	最大内力 3000 以上：
	当前精力 2000以上；
	天山折梅手等级 200 以上；
	八荒六合唯我独尊功等级 200 以上；
	北冥神功等级 200 以上；
	内功有效等级 200 以上：
HELP
	);
	return 1;
}
