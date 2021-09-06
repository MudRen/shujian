#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_drink", "drink");
}

void create()
{
	set_name(HIW "ÈéÀÒ" NOR, ({ "ru lao", "cheese"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÍëÏãÌðµÄÏÊÄÌÀÒ£¬²»ºÈÄÌÀÒ¾Í²»ËãÀ´¹ý´ó²ÝÔ­¡£\n");
		set("unit", "Íë");
		set("value",5000);
             }
}

int do_drink(string arg)
{
	object me = this_player();
	object ob = this_object();

	if (!arg || !id(arg))
		return notify_fail("ÄãÏëºÈÊ²Ã´£¿\n");
	if( me->query("water") < me->max_water_capacity()
	 && me->query("food") < me->max_food_capacity()){
		message_vision(HIG "$N¹ÇÂµ¹ÇÂµµØºÈÍêÒ»Íë" + ob->name()+ HIG "£¬Ä¨ÁËÄ¨×ì¡£\n"NOR,me);
		me->add("food", 100);
		me->add("water", 100);
		destruct(ob);
		return 1;
	}
}
