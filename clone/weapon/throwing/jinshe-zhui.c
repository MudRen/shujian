#include <ansi.h>
inherit COMBINED_ITEM;
#include "/inherit/item/embed.h"
void create()
{
        set_name("����׶", ({ "jinshe zhui","jinshe","zhui" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "����һö���������������εİ�����\n");
               set("unit", "Щ");
               set("damage", 50);
               set("unique", 2);
               set("base_value", 30000);
               set("base_unit", "ö");
               set("base_weight", 1000);
               set("material", "steel");
               set("embed", 1);
        }
        set_amount(50+random(10));

}

