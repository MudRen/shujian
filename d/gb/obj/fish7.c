// fish7.c ����

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"����"NOR, ({ "suo yu", "yu","fish" }) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������������㡣\n");
		set("value", 200);
                set("food_remaining", 5);
                set("food_supply", 30);
        }
        set_weight(100+random(200));
        setup();
}