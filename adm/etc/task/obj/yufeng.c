
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("Óñ·ï",({"yu feng","feng"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","yuan ziyi");
		set("task_owner_cname","Ô¬×ÏÒÂ");
		set("reward_point",6);
		set("unit","¿é");
		set("no_sell",1);
                set("no_beg",1);
		set("value",1000);
		
	}
	setup();
	
}
