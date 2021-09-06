// Modified by action@SJ 2008/09/15

#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, int count);
string perform_name() {return HIR"鹰"HIC"飞"HIW"雁"HIM"舞"NOR;}
int perform(object me, object target)
{
        string msg;
        int i;
        
        if (! me->is_fighting())
                return notify_fail("你只能在战斗种使用「鹰飞雁舞」。\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 100)
                return notify_fail("你的先天功还不够火候，使不出「鹰飞雁舞」。\n");  

        if ((int)me->query_skill("jinyan-gong", 1) < 100)
                return notify_fail("你的金雁功还不够火候，使不出「鹰飞雁舞」。\n");  

        if ((int)me->query("jing", 1) < 500)
                return notify_fail("你现在精不够。\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("你现在内力不够。\n");

        if (me->query_temp("quanzhen/parry"))
                return notify_fail("你正在使用「鹰飞雁舞」。\n");

        msg = HIC "你长啸一声，身法陡然加快，犹如鹰击长空、又如群雁飞舞，令人眼花撩乱，煞是好看。\n\n" NOR; 

        me->add("neili", -200 + random(100));
        me->recieve_damage("jing", 50);
        
        tell_object(me,msg);
        
        i = me->query_skill("xiantian-gong", 1) / 6;

        me->add_temp("apply/dodge", i);
        me->add_temp("apply/parry", i);
        me->set_temp("quanzhen/parry", i);
        
    //    remove_call_out("remove_effect");
        call_out("remove_effect", 1, me, (int)me->query_skill("force",1) / 3);
        return 1;
}

void remove_effect(object me, int count)
{
	   int i;
	   if(!me) return;
     if ( objectp(me) && me->query_temp("quanzhen/parry") ) {
     	 if(count-->0) {
           call_out("remove_effect", 1, me, count);
                      return;
                                     }
        i = me->query_temp("quanzhen/parry",1);
         me->add_temp("apply/dodge", -i);
         me->add_temp("apply/parry", -i);
         me->delete_temp("quanzhen/parry");
       tell_object(me, HIC "你身形渐停，深吸一口气，收回了「鹰飞雁舞」轻功绝技。\n" NOR);
            return;
       }
}


