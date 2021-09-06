#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("·üÉß¹Ü",({"she guan","guan"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","he hongyao");
		set("task_owner_cname","ºÎºìÒ©");
		set("reward_point",7);
		set("unit","Ö¦");
		set("no_sell",1);
                set("no_beg",1);
		set("value",1000);
		
	}
	setup();
	
}
