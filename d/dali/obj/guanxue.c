#include <armor.h>

inherit BOOTS;

void create()
{
       set_name("��ѥ", ({ "bianxue", "xue", "xie" }) );
       set_weight(1000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "˫");
               set("long", "һ˫���׺�ɫ��ѥ");
                 set("value", 10);
               set("material", "boots");
               set("armor_prop/dodge", 1);
       }
       setup();
}
