// gdebug
// by augx@sj 3/29/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) || !arg ) return 0;
	GROUP_D->debug_info(me,arg);
	return 1;
}
