

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("±ø·û",({"bing fu","fu"}));
	set_weight(400);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","zhao liangdong");
		set("task_owner_cname","ÕÔÁ¼¶°");
		set("reward_point",6);
		set("unit","¸ö");
		set("no_sell",1);
                set("no_beg",1);
		set("value",2000);
	}
	
	setup();
	
}
