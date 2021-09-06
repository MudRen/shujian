// duzun.c
// action@SJ 2009/1/17
#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name(){ return HIR"八荒六合唯我独尊"NOR; }

int exert(object me, object target)
{
	int skill;

	if( me->query("neili") < 1000 )
		return notify_fail("你的内力不够。\n");

	if( me->query_skill("bahuang-gong", 1) < 150 )
		return notify_fail("你的八荒六合唯我独尊功等级不够。\n");

	if( me->query_skill_mapped("force") != "bahuang-gong" )
		return notify_fail("你的内功不对。\n");

	if( me->query_temp("bhg/duzun") )
		return notify_fail("你已经在运「八荒六合唯我独尊」了。\n");

	skill = me->query_skill("force")/3;
	if( skill > 150 ) skill = 150;

	me->receive_damage("neili", -300);
	message_vision(HIR "$N凝神息气，运起八荒六合唯我独尊功，只见一股轻烟缭绕周身！\n" NOR, me);

  me->set_temp("bhg/duzun", me->query_skill("bahuang-gong", 1)); 
  me->add_temp("apply/armor", me->query_skill("bahuang-gong", 1)/5); 
  me->add_temp("apply/hand", me->query_skill("bahuang-gong", 1)/10);
  me->add_temp("apply/attack", me->query_skill("bahuang-gong", 1)*5/10);

	call_out("remove_effect", 1, me, skill);
	me->start_exert(1, "八荒六合唯我独尊");
	if( me->is_fighting() )
		me->start_busy(random(2));
	return 1;
}

void remove_effect(object me, int count)
{
	int amount;
	if( objectp(me) && me->query_temp("bhg/duzun") ) {
		if( count-- > 0 ) {
			call_out("remove_effect", 1, me, count);
			return;
		}
		amount = me->query_temp("bhg/duzun");
    me->add_temp("apply/attack",-me->query_skill("bahuang-gong", 1)*5/10);
    me->add_temp("apply/hand",-me->query_skill("bahuang-gong", 1)/10);
    me->add_temp("apply/armor", -me->query_skill("bahuang-gong", 1)/5);
    me->delete_temp("bhg/duzun");
		tell_object(me, HIR"你的「八荒六合唯我独尊功」运行完毕，将内力收回丹田。。。\n"NOR);
	}
}

int help(object me)
{
	write(HIW"\n八荒六合唯我独尊功之「唯我独尊」："NOR"\n\n");
        write(@HELP
	要求：  最大内力  2000 以上；
          当前内力  1000  以上；
          八荒六合唯我独尊功  150  级以上；
HELP
        );
        return 1;
}