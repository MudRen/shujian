// /clone/drug/renshen.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"»À≤Œ"NOR, ({"ren shen"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ø≈");
                set("value", 6500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
