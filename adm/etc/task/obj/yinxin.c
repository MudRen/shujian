

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("����ͷӡ��",({"yin","yinxin"}));
	set_weight(400);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","lin zhennan");
		set("task_owner_cname","������");
		set("reward_point",8);
		set("unit","��");
		set("no_sell",1);
                set("no_beg",1);
		set("value",2000);
	}
	
	setup();
	
}
