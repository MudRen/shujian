// fish5.c ����

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIB"����"NOR, ({ "qing yu", "yu","fish" }) );
        set_weight(400+random(400));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������������㡣\n");
		set("value", 100);
                set("food_remaining", 2);
                set("food_supply", 10);
        }
        setup();
}

