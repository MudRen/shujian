#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("ÈıÊ¬ÄÔÉñµ¤",({"shendan","dan"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
                set("task_owner","yaopu huoji");
                set("task_owner_cname","Ò©ÆÌ»ï¼Æ");
		set("reward_point",3);
		set("unit","Ã¶");
		set("no_sell",1);
                set("no_beg",1);
		set("value",1000);
		
	}
	setup();
	
}
