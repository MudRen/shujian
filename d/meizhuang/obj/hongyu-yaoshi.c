// hongse-yaoshi.c
// action@SJ 2009/1/11
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"红玉钥匙"NOR, ({"hongyu yaoshi", "yaoshi"}));
  if (clonep())
        set_default_object(__FILE__);
        else {
        set("long",
                "这是一把看起来很古怪的钥匙。\n");
        set("unit", "把");
        set("unique", 1);
        set("value", 1);             
        set("material", "steel");
        set("treasure",1);
        set_weight(10);
        }
        setup();
}

