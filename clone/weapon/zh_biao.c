inherit COMBINED_ITEM;
#include "/inherit/item/embed.h"
void create()
{
        set_name("׷����", ({ "zhuihun biao","zhuihun","biao" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "����һƬа�ɵ�׷���ڣ�����Ϳ�о綾��\n");
               set("unit", "Щ");
               set("damage", 3);
               set("base_value", 400);
               set("base_unit", "Ƭ");
               set("base_weight", 100);
               set("poison", "snake_poison");
               set("material", "steel");
//               set("unique", 10);
               set("embed", 1);
        }
        set_amount(1);

}

