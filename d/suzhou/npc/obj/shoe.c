// shoe.c � ̤ѩ�޺� 
#include <armor.h>
inherit BOOTS;
#include <ansi.h>

void create()
{
        set_name(GRN"̤ѩ�޺�"NOR, ({ "shoes", "xie" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long","����һ˫��ɫ�Ĳ��ƿ�ѥ��\n");
                set("value", 0);
                set("material", "boots");
                set("armor_prop/dodge", 20);
              }
         setup();
}

