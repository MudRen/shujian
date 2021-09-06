// wuqi.c
// action@SJ 2009/1/17

#include <ansi.h>
inherit F_CLEAN_UP;
string exert_name(){ return HIR"五气朝元"NOR; }


 void remove_effect(object me, int count);
int exert(object me, object target)
{
	int skill;

	if( me->query("neili") < 1000 )
		return notify_fail("你的内力不够。\n");

	if( me->query_skill("xiantian-gong", 1) < 150 )
		return notify_fail("你的先天功等级不够。\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("你的内功不对。\n");

	if( me->query_temp("xtg/wuqi") )
		return notify_fail("你已经在运「五气朝元」了。\n");

	skill = me->query_skill("force",1);
	
	me->receive_damage("neili", -300);
	
	message_vision(
HIR"$N默念“心藏神，肝藏魂，脾藏意，肾藏精，肺藏魄”的法诀，正合道家[五气朝元]之理，霎时间\n"+

"便领悟了“人之修道，必由五行归五老，三花而化三清，始能归原无极本体，而达圆通究竟”的法门。\n" NOR, me);

  me->set_temp("xtg/wuqi", skill );

	call_out("remove_effect", 1, me, skill);
	me->start_exert(1, "五气朝元");
	if( me->is_fighting() )
		me->start_busy(random(2));
	return 1;
}

void remove_effect(object me, int count)
{
        int amount;
        if(!me)  return;
  if( objectp(me) && me->query_temp("xtg/wuqi")) {
		if( count-- > 0 ) {
			call_out("remove_effect", 1, me, count);
			return;
		                        }
		
		amount = me->query_temp("xtg/wuqi");
    me->delete_temp("xtg/wuqi");
    
		tell_object(me, HIW"你的["+HIR+"五气朝元"+HIW+"]运行完毕，将内力收回丹田。\n"NOR);
      }
}

int help(object me)
{
	write(HIW"\n先天功之「五气朝元」："NOR"\n\n");
        write(@HELP
	要求：  最大内力  2000 以上；
          当前内力  1000  以上；
          先天功  150  级以上；
HELP
        );
        return 1;
}
