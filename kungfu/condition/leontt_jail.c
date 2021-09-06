// condition leontt_jail.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
      object where;
        if (duration < 1) {
                me->move("/u/leontt/jianyu.c");
                me->set("startroom", START_ROOM);
                return 0;
        }

        if (!duration) return 0;
        
        if(!objectp(where = environment(me))) me->move("/u/leontt/jianyu.c");
                  
        if (duration >= 1 && base_name(where) != "/u/leontt/jianyu.c") {
                me->set("eff_qi", 1);
                me->set("qi", 1);
                me->apply_condition("leontt_jail", 10);
                me->move("/u/leontt/jianyu.c");
        }
        return 1;
}

string query_type(object me)
{
        return "relax";
}

