// music_busy.c 

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	me->apply_condition("music_busy", duration - 1);
	return 1;
}

