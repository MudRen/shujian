#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1)
        {
                
                        tell_object(me, HIR"敌人援军已经赶到，一阵乱箭射来，你躲闪不及，被利箭穿胸而过。。。\n"NOR);
                        me->move("/d/city/kedian/pianting");
                        me->delete_temp("was_job");
                        me->unconcious();
                        me->apply_condition("ruanjin_poison", 100);
                
                return 0;
        }
    
                if (duration < 5)
                        tell_object(me, HIR"敌人的援兵马上就要赶到了，请抓紧时间！\n"NOR);
                else if (duration < 10)
                        tell_object(me, HIR"远处元兵大营已经灯火通明，似乎有一大队人马正在集结！\n"NOR);
                else
                        tell_object(me, HIR"远处元兵大营出现一阵骚乱，似乎有人注意到了这边的情况，请抓紧时间！\n"NOR);
    
        me->apply_condition("was_check", duration - 1);
        return 1;
}

string query_type()
{
        return "job";
}
