// /clone/weapon/tiejili.c
// by leontt 2000/10/26

inherit COMBINED_ITEM;
#include <ansi.h>
#include "/inherit/item/embed.h"

void create()
{
        set_name(CYN"����޼"NOR, ({ "tie jili","jili"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", CYN"����һ���������İ��������泤���˵��̡�\n"NOR);
               set("unit", "Щ");
               set("damage", 6);
               set("value", 400);
               set("base_value", 400);
               set("base_unit", "��");
               set("base_weight", 200);
               set("material", "steel");
               set("embed", 1);
        }
        set_amount(1);
}
