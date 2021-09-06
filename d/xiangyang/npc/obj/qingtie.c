// qingtie.c

#include <armor.h>
#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIC"侠客岛腊八粥请帖"NOR, ({ "qing tie", "qingtie", "tie" }));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
                        "这是一张侠客岛邀请武林人士喝粥的请帖。\n");
                set("value", 500);
                set("no_give", 1);
                set("treasure",1);
                set("material", "paper");
                set("no_get", "这样东西不能离开那儿。\n");
               
        }
}

