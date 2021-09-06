// leiting 雷霆万钧
//这里只是个控制文件。
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	    object weapon;
	 if( !target ) target = offensive_target(me);
  
    if( !target  
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("「雷霆万钧」只能在战斗中使用。\n");
/*
        if(me->query("eff_qi") > me->query("max_qi")*2/3)
		return notify_fail("目前情况不是很危机，没必要使用「雷霆万钧」。\n");
  */      
	if( (int)me->query_skill("songshan-jian", 1) < 160 )
		return notify_fail("你的嵩山剑法还不够娴熟，无法使出「雷霆万钧」。\n");

	if( (int)me->query_skill("force", 1) < 160 )
		return notify_fail("你的内功等级还不够，无法使出「雷霆万钧」。\n");

	if (me->query_skill_mapped("force") != "hanbing-zhenqi")
		return notify_fail("你目前的内功无法使出「雷霆万钧」。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "sword"
	|| me->query_skill_mapped("sword") != "songshan-jian")
		return notify_fail("你无法使出「雷霆万钧」。\n");
              
	if( (int)me->query("max_neili") < 2500)
		return notify_fail("你的内力修为太差，无法使出「雷霆万钧」。\n");

     	if( (int)me->query_temp("ssj/leiting") )
		return notify_fail("你已经蓄积内力正在使用「雷霆万钧」。\n");   
        
	if( (int)me->query("neili") < 1000)
		return notify_fail("你现在真气太弱，使不出「雷霆万钧」。\n");
		
 message_vision(HIW"\n$N慢慢提起"+weapon->name()+HIW"，剑尖对准了$n胸口，将毕生的功力都运到了右手之上。
$N右手衣袖鼓了起来，犹似吃饱了风的帆篷一般，这一剑之出，自是雷霆万钧之势。\n"NOR,me,target);
  	         me->set_temp("ssj/leiting",1);
//if(!userp(target)) target->add_busy(2);
 	me->add("jingli", -80);
if(me->query_skill("songshan-jian",1)<=450 )
        me->start_perform(3, "雷霆万钧");

        return 1;
}

string perform_name(){ return YEL"雷霆万钧"NOR; }

int help(object me)
{
        write(YEL"\n嵩山剑法之「雷霆万钧」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                最大内力 2500 以上；
                当前精力 1000 以上；
                嵩山剑法等级 160 以上；
                内功    等级 160 以上；
                有效内功等级 250 以上；
                激发剑法为嵩山剑法；
                激发内功为寒冰真气；
                且手持兵器。


HELP
        );
        return 1;
}
