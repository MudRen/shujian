// /kungfu/skill/liuyang-zhang/jie.c 
//modified by zhuifeng@SJFY 2010/07/17

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target )
{
        string msg;
        int pow;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("你要给谁解生死符。\n");

        if(target == me)
                return notify_fail("你无法给自己解生死符！\n");

        if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
                return notify_fail("你的天山六阳掌不够娴熟，不能解生死符。\n");

        if(!target->query_condition("shengsi_poison"))
        return notify_fail("对方并没有中生死符，不需要你折腾。\n");

        if( (int)me->query("neili") < 3000 )
                return notify_fail("你现在内力太弱，不能解生死符。\n");

 if(me->query("family/family_name") != "逍遥派"&& me->query("family/family_name") != "灵鹫宫") 
           return notify_fail("你又不是灵鹫宫宫主，不晓得如何解生死符。\n");

        me->add("neili", -3000);
        msg = HIC "$N使出天山六阳掌，按解生死符的手法，快速的拍向$n的周身大穴。\n"NOR;

        pow=((int)me->query_skill("liuyang-zhang",1)
             +(int)me->query_skill("bahuang-gong",1))/5;
        pow=pow+random(pow);

        if(target->query_condition("shengsi_poison")<=pow)
        {
         target->clear_condition("shengsi_poison");
         msg +=HIW"$N擦了擦额头的大汗，长吁一口气，看来$n身上所中的生死"
               +"符已经全部拔除了。\n"NOR;
        } else
        {
        target->apply_condition("shengsi_poison",
                                target->query_condition("shengsi_poison")-pow);
        msg +=HIR"$N头上真气缭绕，片刻竟将$N和$n笼罩在其中，一会而$N站起身"
                  +"来，面露颓然之色，\n"
                  +"看来$N还没有找到办法完全拔除$n身上的生死符。\n"NOR; 
        }
        me->start_busy(pow/10);       

        message_vision(msg, me, target);
        return 1;
}
string perform_name(){ return HIC"解生死符"NOR; }

int help(object me)
{
	write(YEL"\n天山六阳掌之「解生死符」："NOR"\n");
	write(@HELP

	要求：
	当前内力 3000 以上；
        最大内力 3000 以上：
        八荒六合为我独尊功等级 200 以上；
        内功有效等级 200 以上：
HELP
	);
	return 1;
}