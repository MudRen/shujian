// yugan.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"���"NOR, ({ "yu gan", "yugan", "gan" }) );
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_drop", 1);
                set("value", 200);
                set("long", "����һ����͡�\n");
        }
        setup();
}

