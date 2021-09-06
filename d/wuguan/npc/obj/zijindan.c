// zijindan
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"紫金丹"NOR,({"zijin dan", "dan" }));
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
	int per,kar,pur;
	per = me->query("per");
	kar = me->query("kar");
	pur = me->query("pur");
	if(!id(arg))
		return notify_fail("你要吃什么？\n");
	message_vision("$N吃下一颗" + name() + "，身体犹如抽丝剥茧一般判若两人！。\n", me);
	message_vision("一个声音说道：$N的容貌是"+per+"点,富源是"+kar+"点,淳朴是"+pur+"点。\n", me);
	me->reincarnate();
	me->set("neili", me->query("max_neili")*2);
        destruct(this_object());
	return 1;
}

int query_autoload()
{
	return 1;
}






