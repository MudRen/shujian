#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name("参丸", ({"shen wan", "shen", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("value", 3000);
                set("unit", "颗");
                set("long", "这是一颗特效参丸，可以补满精血。\n");
        }
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        if (me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if (me->query("eff_jing") >= me->query("max_jing"))
                return notify_fail("你现在不需要用参丸。\n");
        me->receive_curing("jing", me->query("max_jing"));
        me->receive_heal("jing", me->query("max_jing"));
        message_vision(HIY"$N吃下一颗参丸，身上内伤已然无碍。\n"NOR, me);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}