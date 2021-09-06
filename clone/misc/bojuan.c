// bojuan.c ²¯¾î

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"²¯¾î"NOR, ({"bo juan", "bojuan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "
            Ò»¾í°×É«µÄ²¯¾î£¬Ö¯¹¤Ò»°ã¡£\n");
                set("unit", "¾í");
                set("value", 30);
        }
}
