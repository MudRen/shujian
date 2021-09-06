//taskob
//Made by jason@pkuxkx
//2001.1.16

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("×ÏÖñ½£",({"zhu jian","jian"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","zhang sanfeng");
		set("task_owner_cname","ÕÅÈı·á");
		set("reward_point",7);
		set("unit","±ú");
                set("no_beg",1);
		set("no_sell",1);
		set("value",1000);
		
	}
	init_sword(100);
	setup();
	
}
