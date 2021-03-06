// chan 
// 99.3.17  by emnil

#include <ansi.h>

inherit F_SSERVER;

void do_chan(object me, object target, object weapon, int times);

int perform(object me, object target)
{
	string *mapped,msg;
	mapping map;
	object weapon;
	int skill, time,exp,cs;

       if( !target ) target = offensive_target(me);


      weapon = me->query_temp("weapon");

      if (!weapon || weapon->query("skill_type") != "whip"
       || me->query_skill_mapped("whip") != "lingshe-bianfa")
          return notify_fail("你手里没有鞭，无法使用「金蛇缠丝」！\n");             
 	if( !target || !target->is_character()|| !me->is_fighting(target) )
		return notify_fail("「金蛇缠丝」只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if( (int)me->query_skill("lingshe-bianfa", 1) < 100 )
		return notify_fail("你的灵蛇鞭法不够娴熟，不会使用「金蛇缠丝」绝技。\n");

	if( (int)me->query_skill("dulong-dafa", 1) < 100 )
		return notify_fail("你的毒龙大法不够深厚，不会使用「金蛇缠丝」。\n");

	if( (int)me->query("neili")<200)
		return notify_fail("你现在内力太弱，不能使用金蛇缠丝。\n");

       if(me->query_skill_mapped("force") != "dulong-dafa")
              return notify_fail("你现在使用的内功与毒龙大法相抵触，不能使用「金蛇缠丝」。\n");

	me->add("neili", -150);
	
	msg = HIY+"\n$N"+HIY+"突然以回旋劲摔出手中的"+weapon->query("name")+HIY+"，企图缠住$n的脖子！\n"NOR;
	
	exp=random(me->query("combat_exp")*16/10);
	cs=me->query_temp("chanfail",1);
	if ( (exp > random( target->query("combat_exp"))) || (cs>2 &&
	     (cs>target->query("combat_exp")*2/me->query("combat_exp"))))
	{
		me->delete_temp("chanfail");
		msg +=HIR+"$n一个没留神，被"+weapon->query("name")+HIR+"缠个正着，出招的速度慢了下来！\n"NOR;
		me->start_busy(1);
		target->start_busy(1);
                me->set_temp("lingshe/chan",1);

		weapon->unequip();
		if(!objectp(find_object("/d/sld/md1")))
    		{
        		load_object("/d/sld/md1");   
    		}
		//weapon->move(__DIR__"emptyroom");
		weapon->move("/d/sld/npc/xjjl");

		time = me->query_skill("whip")/40 +1 ;	
		me->start_call_out( (: call_other, __FILE__, "do_chan", me, target , weapon, time:), 1);
	}
	else {
		msg += CYN+"可是$n"+CYN+"看破了$N"+CYN+"的企图，逃了过去。\n"NOR;
		me->start_busy(2);
		cs++;
		me->set_temp("chanfail",cs);
	}

	message_vision(msg,me,target);

	return 1;
}

void do_chan(object me, object target, object weapon, int times)
{
	int force;

	if(!objectp(me))
	{
		if(objectp(target) && !target->is_ghost())
		{
			if(objectp(weapon))
			{
				weapon-> move(environment(target));
				message("vision",HIY+weapon->name()+HIY+"「啪」的一声掉在了地上。\n"NOR,environment(weapon));
			}
		}
		else if(objectp(weapon))
			destruct(weapon);
		return;
	}
	if( !living( me ) || me->is_ghost() ) 	{
                me->delete_temp("lingshe/chan");
		if(objectp(target) && !target->is_ghost())
		{
			if(objectp(weapon))
			{
				weapon-> move(environment(target));
	message("vision",HIY+weapon->name()+HIY+"「啪」的一声掉在了地上。\n"NOR,environment(weapon));
			}
		}
		else if(objectp(weapon))
			destruct(weapon);
		return;
	}
	if(!objectp(target) || target->is_ghost())
	{
		me->delete_temp("lingshe/chan");
		if(objectp(weapon))
		{
			weapon->move(me);
			weapon->wield(me);
			tell_room(environment(weapon),HIY+weapon->query("name")+HIY+"回到"+me->name()+HIY+"的手中。\n"NOR);
		}
		return;
	}
	if(!objectp(weapon))
	{
		me->delete_temp("lingshe/chan");
		return;
	}
	if(!me->is_fighting(target)) {
		message_vision(HIY+weapon->query("name")+HIY+"回到"+"$N"+HIY+"的手中。\n"NOR,me,target);
		weapon->move(me);
		weapon->wield(me);
                me->delete_temp("lingshe/chan");
		return ;
	}

	if(times<=0) {
		message_vision(HIY+"\n$n"+HIY+"内力一震，总算摆脱了"+weapon->query("name")+HIY+"的纠缠，"
			+weapon->query("name")+HIY+"回到"+"$N"+HIY+"的手中。\n"NOR,me,target);
                me->delete_temp("lingshe/chan");
		weapon->move(me);
		weapon->wield(me);
		return ;
	}

	if (me->query_temp("weapon")) {
		message_vision(HIY+"\n$N"+HIY+"拿着兵器，无法再集中精神。"
			+weapon->query("name")+HIY+"回到"+"$N"+HIY+"的手中。\n"NOR,me,target);
		weapon->move(me);
                me->delete_temp("lingshe/chan");
		return ;
	}
	
	target->add("jingli",- (me->query_skill("whip")/4));
	if ( target->query("jingli")<1 ) target->set("jingli",1);

	force=random(me->query_skill("force")*13/10);
	if(force  > random(target->query_skill("force")) ) {
		target->start_busy(2+random(2));
		message_vision( HIR"$n"+HIR+"被御缠在他脖子上的"+weapon->query("name")
			+HIR+"弄的手忙脚乱，没有时间出招了！\n"NOR,me,target);
		call_out("do_chan",3,me,target,weapon,times-1);
	}
	else
		call_out("do_chan",2,me,target,weapon,times-1);

}
