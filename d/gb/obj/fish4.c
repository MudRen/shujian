// fish4.c ��Ŀ��

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIG"��Ŀ��"NOR, ({ "bimu yu", "yu","fish" }) );
        set_weight(200+random(200));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ŀ�㡣\n");
		set("value", 150);
                set("food_remaining", 2);
                set("food_supply", 30);
        }
        setup();
}

