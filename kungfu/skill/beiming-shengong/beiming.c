// beiming.c
// modified by action@SJ 2009/2/5
//updated by Zmud@Sjmud 12/3/2009

#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name(){ return HIC"北溟真气"NOR; }

int exert(object me, object target)
{
	int skill;

        if( me->query("neili") < 5000 )
		return notify_fail("你的内力不够。\n");

        if( me->query_skill("beiming-shengong", 1) < 300 )
		return notify_fail("你的北冥神功等级不够。\n");

	if( me->query_skill_mapped("force") != "beiming-shengong" )
		return notify_fail("你的内功不对。\n");

	if( me->query_temp("bmsg/bm") )
		return notify_fail("你已经在运「北溟真气」了。\n");

	skill = (int)me->query_skill("beiming-shengong", 1);

	me->receive_damage("neili", -1000);
	message_vision(HIB "\n$N运起北冥神功口中默念"NOR"："HIB"真气经由灵台，尺泽，曲池，灵海，天宗汇入气海["HIG"北溟"HIB"]，形成一股浩荡之气。\n" NOR, me);

  me->set_temp("bmsg/bm", me->query_skill("beiming-shengong", 1)); 
  me->add_temp("apply/armor", me->query_skill("beiming-shengong", 1)); 
  me->add_temp("apply/attack", me->query_skill("beiming-shengong", 1)/6);
  me->add_temp("apply/intelligence", me->query_skill("beiming-shengong", 1)/30);
  me->add_temp("apply/dexerity", me->query_skill("beiming-shengong", 1)/20);

	call_out("remove_effect", 1, me, skill);
	me->start_exert(1, "北溟真气");
	if( me->is_fighting() )
		me->start_busy(random(2));
	return 1;
}

void remove_effect(object me, int count)
{
	int amount;
	if( objectp(me) && me->query_temp("bmsg/bm") ) {
		if( count-- > 0 ) {
			call_out("remove_effect", 1, me, count);
			return;
		}
		amount = me->query_temp("bmsg/bm");
    me->add_temp("apply/armor", -me->query_skill("beiming-shengong", 1));
    me->add_temp("apply/attack",-me->query_skill("beiming-shengong", 1)/6);
    me->add_temp("apply/intelligence", -me->query_skill("beiming-shengong", 1)/30);
    me->add_temp("apply/dexerity", -me->query_skill("beiming-shengong", 1)/20);

    me->delete_temp("bmsg/bm");
		tell_object(me, HIC"你渐渐地散去了聚于气海["HIB"北溟"NOR+HIC"]真气。\n"NOR);
	}
}

int help(object me)
{
	write(HIW"\n北冥神功之「北溟真气」："NOR"\n\n");
        write(@HELP
        要求：  
                当前内力  10000  以上；
                北冥神功  300  级以上；
                如果在无量山洞中解出北冥神功之精髓将有奇异功效。
HELP
        );
        return 1;
}
