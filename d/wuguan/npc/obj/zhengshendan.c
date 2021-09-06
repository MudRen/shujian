//zhengshendan
#include <ansi.h>

inherit ITEM;


void create()
{
        set_name(HIY"正神丹"NOR,({"zhengshen dan", "dan" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "据说是按照太上老君遗失在人间的〈炼丹残篇〉炼制而成。\n");
                set("unit", "颗");
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("value", 0);                
         }
	setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	if(!id(arg))
		return notify_fail("你要吃什么？\n");
	message_vision("$N吃下一颗" + name() + "，顿感灵台空明，精神为之一振！\n", me);
	me->set("shen", 100000);
        destruct(this_object());
	return 1;
}

int query_autoload()
{
	return 1;
}



