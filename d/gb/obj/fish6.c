// fish6.c ����

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR"����"NOR, ({ "gui yu", "yu","fish" }) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������������㡣\n");
		set("value", 200);
                set("food_remaining", 2);
                set("food_supply", 20);
	}
	set_weight(400+random(600));
        setup();
}