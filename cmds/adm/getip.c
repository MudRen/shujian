#include <ansi.h>

int main(object me, string arg)
{
	if (!arg) return notify_fail("ÇëÊäÈëIPµØÖ·¡£\n");
	arg = replace_string(arg," ","");
	write( arg + "   ==>   "+IP_D->ip2name(arg) + "\n");
	return 1;
}
