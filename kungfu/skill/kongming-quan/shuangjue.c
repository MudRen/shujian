// 空明双绝


#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
   int lvl;
   lvl = (int)me->query_skill("kongming-quan", 1);
if (me->query("max_pot") >= 400 ) lvl = lvl /4;
  if( !target ) target = offensive_target(me);
  if( !objectp(target)
	 || !me->is_fighting(target)
	 || !living(target)
	 || environment(target)!=environment(me))
		return notify_fail("「空明双绝」只能在战斗中对对手使用。\n");

  if( objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用「空明双绝」！\n");

   if( (int)me->query_skill("kongming-quan", 1) < 200 )
		return notify_fail("你的空明拳还不够娴熟，使不出「空明双绝」绝技。\n");

   if(!me->query_skill("force", 1) || (int)me->query_skill("cuff",1)<200)
   if( (int)me->query_skill("parry", 1) < 200 )
           return notify_fail("你的基础技能等级还不够，使不出「空明双绝」绝技。\n");

   if( (int)me->query_skill("dodge",1) < 200 )
		return notify_fail("你的轻功等级不够，不能使用「空明双绝」。\n");
		
  if( (int)me->query_skill("xiantian-gong",1) < 200 )
		return notify_fail("你的先天功等级不够，不能使用「空明双绝」。\n");
/*
	if( !me->query("quest/jiebai/pass") )
		return notify_fail("你并未获得周伯通传授，不能使用「空明双绝」。\n");
*/
   if( me->query_skill_prepared("cuff") != "kongming-quan"
	 || me->query_skill_mapped("cuff") != "kongming-quan")
		return notify_fail("你现在无法使用「空明双绝」！\n");

   if( me->query_skill_mapped("parry") != "kongming-quan")
		return notify_fail("你需要激发招架为空明拳，方能使用「空明双绝」。\n");
if(userp(me)) 
            return notify_fail("你使不出这个绝招。\n");

   if( (int)me->query("max_neili") < 3000)
		return notify_fail("你的内力太弱，使不出「空明双绝」。\n");

   if( (int)me->query("neili") < 1500 )
		return notify_fail("你现在真气太弱，使不出「空明双绝」。\n");

   if( (int)me->query("jingli") < 1500 )
           return notify_fail("你现在太累了，使不出「空明双绝」。\n");


message_vision(HIB"\n$N凝神屏气，默念口诀：“空朦洞松、风通容梦、冲穷中弄、童庸弓虫。”使出空明拳绝技「"NOR+HBWHT+WHT"空明双绝"NOR+HIB"」！\n"NOR,me);

  

	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", lvl);
	me->add_temp("apply/cuff", lvl);
	me->add_temp("apply/strength", lvl / 3);
	if (me->query_temp("xtg/wuqi"))
		me->add_temp("apply/damage", lvl/2);
     
   COMBAT_D->do_attack(me, target, 0, 3);

	if ( me->is_fighting(target))
   COMBAT_D->do_attack(me, target, 0, 3);

	if ( me->is_fighting(target))
   COMBAT_D->do_attack(me, target, 0, 3);


	if ( me->is_fighting(target))
   COMBAT_D->do_attack(me, target, 0, 3);

	
	me->add_temp("apply/attack",- lvl);
	me->add_temp("apply/damage", -lvl);
	me->add_temp("apply/cuff", -lvl);
	me->add_temp("apply/strength",- lvl / 3);
		if (me->query_temp("xtg/wuqi"))
		me->add_temp("apply/damage", -lvl/2);
   me->add("jingli", -100);
   me->add("neili", -200);
   me->start_busy(random(2));

   me->start_perform(3+ random(3),"「空明双绝」");

	return 1;
}


string perform_name(){ return WHT"空明双绝"NOR; }

int help(object me)
{
	write(WHT"\n空明拳之「空明双绝」："NOR"\n\n");
	write(@HELP
           最大内力 3000 以上；
           当前内力 1500  以上；
           当前精力 1500  以上；
           空明拳等级 200 以上；
           激发拳法招架为空明拳；
                       备拳法为空明拳且空手。
            (NPC专用)。

HELP
	);
	return 1;
}
