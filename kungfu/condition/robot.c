// robot.c

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
	object *inv;
	int i;
	if (duration < 1) {	       
		if(present("jiqiren faguan",environment(me))) {
			inv = all_inventory(me);
			for( i=0;i<sizeof(inv);i++)
			if(!inv[i]->query_autoload() && !inv[i]->query("imbued"))
				"/cmds/std/drop.c"->do_drop(me,inv[i]);
		}
		return 0;
	}
	me->apply_condition("robot",duration-1);
	return 1;
}


