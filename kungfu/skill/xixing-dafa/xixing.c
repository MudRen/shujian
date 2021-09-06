// xixing.c 吸星大法

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string exert_name(){ return HIR"吸星大法"NOR; }

int exert(object me)
{
	int skill, i;

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");
		
	if( (int)me->query_temp("xxdf/xixing") ) 
		return notify_fail("你已经在运功中了。\n");

    skill = ((int)me->query_skill("force",1) + (int)me->query_skill("xixing-dafa",1))/2;
    i = skill/3 + random(skill/5); 

	me->add("neili", -200+random(200));
        message_vision(HIR "\n$N凝神一聚，运起吸星大法，全身骨节发出一阵爆豆般的声响，似乎要杀人了。\n" NOR, me);

	me->add_temp("apply/attack", i);
	me->add_temp("apply/dexerity", i/10);
	me->set_temp("xxdf/xixing", i);
  me->add_temp("apply/parry", i);

	call_out("remove_effect", 1, me, skill/3);
	if( me->is_fighting() ) me->start_busy(random(2));
	me->start_exert(1,"吸星大法");
	return 1;
}

void remove_effect(object me, int count)
{    
     int amount;
     if( objectp(me) && me->query_temp("xxdf/xixing") ) 
           {
              if( count-- > 0 ) {
                     call_out("remove_effect", 1, me, count);
                    return;
            }
amount = me->query_temp("xxdf/xixing");
	 me->add_temp("apply/attack", - amount);
	 me->add_temp("apply/dexerity", - amount/10);
   me->add_temp("apply/parry", - amount);
         me->delete_temp("xxdf/xixing");

     tell_object(me, HIC"\n你的"HIR"吸星大法"HIC"运行完毕，将内力收回丹田。\n"NOR);
       }
    
}
