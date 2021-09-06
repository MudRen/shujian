

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("²§ÓÛ",({"bo yu","boyu"}));
	set_weight(400);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","xingzhe");
		set("task_owner_cname","ÐÐÕß");
		set("reward_point",1);
		set("unit","¸ö");
		set("no_sell",1);
                set("no_beg",1);
		set("value",2000);
	}
	
	setup();
	
}
