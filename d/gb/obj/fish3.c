// fish3.c �����

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"�����"NOR, ({ "dahuang yu", "yu","fish" }) );
        set_weight(400+random(600));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����˶�Ĵ���㡣\n");
		set("value", 300);
                set("food_remaining", 3);
                set("food_supply", 30);

        }
        setup();
}

