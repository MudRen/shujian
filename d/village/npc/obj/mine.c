// mine.c 矿石
//Modified By ChinaNet
//By 2004/1/11

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("矿石", ({ "kuang shi", "shi","kuang","mine"})); 
       
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
                set("unit", "块");
                set("weight", 800);
		set("long", "这是一块普通的矿石。\n");
		set("no_get","这块矿石这么重，你搬不起来。\n");
		set("no_drop","别乱扔石头，砸到人怎么办？\n");
		set("material", "stone");
		set("minejob",1);
		set("value",10000+random(5000));
	}
	setup();
}

