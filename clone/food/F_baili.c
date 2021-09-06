// Write By Yanyang@SJ 2001.9.27
// F_baili.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
 
void create()
{
        set_name(HIW"°×Àæ"NOR, ({"bai li","baili","li"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿ÅÏãÌðµÄ°×Àæ¡£\n");
                set("unit", "¿Å");
                set("value", 40);
                set("food_remaining", 2);
                set("food_supply", 25);
          }
        setup();
}
