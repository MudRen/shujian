
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("¿×ÃÏÖ®Êé",({"book","shu"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","zhu xi");
		set("task_owner_cname","¹ËÑ×Îä");
		set("reward_point",4);
		set("unit","±¾");
		set("no_sell",1);
                set("no_beg",1);
		set("value",1000);
		
	}
	setup();
	
}
