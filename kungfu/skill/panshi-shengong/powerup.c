// powerup.c

#include <ansi.h>
string exert_name(){ return HIY"聚力"NOR; }
int exert(object me)
{       

        int skill=me->query_skill("panshi-shengong");

        if ((int)me->query_skill("panshi-shengong", 1) < 160)
                return notify_fail("你的磐石神功修为还不够。\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够。\n");
        
      if( me->query_temp("pssg/powerup")   )
                return notify_fail("你正在运用聚力！\n");

        write(HIY"猛地一声长啸，丹田一团热气直冲顶门，毛发直竖，顿时神威浩荡，大异此前。\n"NOR);

        me->add_temp("apply/attack", skill/2);
        me->set_temp("pssg/powerup", 1);  
        me->start_busy(random(2));
        me->add("neili", - 300);    
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill * 3/2 );
        return 1;
}
void remove_effect(object me, int skill)
{
       me->add_temp("apply/attack", -skill/2);
      me->delete_temp("pssg/powerup");
      tell_object(me, HIY"你的磐石神功运行完毕，将内力收回丹田。\n"NOR);
}

int help(object me)
{
	write(WHT"\n磐石神功之加力：聚力"NOR"\n");
	write(@HELP

	使用功效：
		提升自己的攻击能力

	出手要求：
	        内力500
HELP
	);
	return 1;
}

