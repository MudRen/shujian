

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("����",({"bing fu","fu"}));
	set_weight(400);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","zhao liangdong");
		set("task_owner_cname","������");
		set("reward_point",6);
		set("unit","��");
		set("no_sell",1);
                set("no_beg",1);
		set("value",2000);
	}
	
	setup();
	
}
