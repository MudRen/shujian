#include <ansi.h>
inherit COMBINED_ITEM;
#include "/inherit/item/embed.h"

void create()
{
        set_name(HIY"ܽ�ؽ���"NOR, ({ "furong jinzhen","furong","jinzhen", "zhen" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "����һ��ϸ��ͷ���Ľ��룬�����䵱�ɡ�\n");
               set("unit", "Щ");
               set("damage", 3);
               set("base_value", 2000);
               set("base_unit", "ö");
               set("base_weight", 100);
               set("material", "gold");
               set("embed", 1);
        }
         set_amount(2);
}
