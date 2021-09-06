// Write By Yanyang@SJ 2001.9.27
// F_lizhi.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
 
void create()
{
        set_name(MAG"¿Û÷¶"NOR, ({"li zhi", "lizhi" }));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "“ªø≈œ„Ãµƒ¿Û÷¶°£\n");
                set("unit", "ø≈");
                set("value", 40);
                set("food_remaining", 2);
                set("food_supply", 25);
          }
        setup();
}
