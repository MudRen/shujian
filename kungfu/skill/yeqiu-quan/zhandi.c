// 野球拳连击


#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
   int lvl;
   lvl = (int)me->query_skill("yeqiu-quan", 1);
if (me->query("max_pot") >= 350 ) lvl = lvl /4 ;
  if( !target ) target = offensive_target(me);
  if( !objectp(target)
	 || !me->is_fighting(target)
	 || !living(target)
	 || environment(target)!=environment(me))
		return notify_fail("「野球拳战敌八方」只能在战斗中对对手使用。\n");

  if( objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用「野球拳战敌八方」！\n");

   if( (int)me->query_skill("yeqiu-quan", 1) < 100 )
		return notify_fail("你的野球拳还不够娴熟，使不出「野球拳战敌八方」绝技。\n");

   if(!me->query_skill("force", 1) || (int)me->query_skill("cuff",1)<100)
   if( (int)me->query_skill("parry", 1) < 100 )
           return notify_fail("你的基础技能等级还不够，使不出「野球拳战敌八方」绝技。\n");

   if( (int)me->query_skill("dodge",1) < 100 )
		return notify_fail("你的轻功等级不够，不能使用「野球拳战敌八方」。\n");


   if( me->query_skill_prepared("cuff") != "yeqiu-quan"
	 || me->query_skill_mapped("cuff") != "yeqiu-quan")
		return notify_fail("你现在无法使用「野球拳战敌八方」！\n");


   if( me->query_skill_mapped("parry") != "yeqiu-quan")
		return notify_fail("你需要激发招架为野球拳，方能使用「野球拳战敌八方」。\n");


   if( (int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，使不出「野球拳战敌八方」。\n");

   if( (int)me->query("neili") < 500 )
		return notify_fail("你现在真气太弱，使不出「野球拳战敌八方」。\n");

   if( (int)me->query("jingli") < 500 )
           return notify_fail("你现在太累了，使不出「野球拳战敌八方」。\n");


message_vision(HIC"\n$N朗声念道：“"HBBLU+HIM"捶把妙术在移闪，动静呼吸一气连，来来去去需随便，尽在接取玄妙间！"NOR""HIC"”随即欺身向前，连出数招！\n"NOR,me);

  if(!userp(target) && me->query("max_pot") <= 350)  target->set_temp("must_be_hit",1);

	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", lvl);
	me->add_temp("apply/cuff", lvl);
	me->add_temp("apply/strength", lvl / 3);
     
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
   me->add("jingli", -100);
   me->add("neili", -200);
   me->start_busy(random(2));

   me->start_perform(2+ random(2),"「野球拳战敌八方」");

	return 1;
}


string perform_name(){ return HIR"野球拳战敌八方"NOR; }

int help(object me)
{
	write(HIR"\n野球拳之「野球拳战敌八方」："NOR"\n\n");
	write(@HELP
           最大内力 1000 以上；
           当前内力 500  以上；
           当前精力 500  以上；
           野球拳等级 100 以上；
           基本内功 轻功 招架 拳法 等级 100 以上；
           		激发拳法为野球拳；
		激发招架为野球拳：
		备拳法为野球拳且空手。

HELP
	);
	return 1;
}
