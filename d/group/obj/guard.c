// guard.c
// by augx@sj  3/22/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"����"NOR, ({ "bao biao","guard" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("value", 5000000);
		set("guard",1);
		if( GROUP_D->need_encrypt() )
			set("guard_file","/d/group/npc/guard.o");
		else
			set("guard_file","/d/group/npc/guard.c");
	}
	setup();
}
