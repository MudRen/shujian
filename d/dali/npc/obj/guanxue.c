// Modify By River 98/12
#include <armor.h>
inherit BOOTS;

void create()
{
       set_name("�ڵױ�ѥ", ({ "heidi bianxue", "bianxue", "shoe" }) );
       set_weight(1000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "˫");
               set("long", "һ˫���׺�ɫ��ѥ��һ��ܻ��˼Ҿ������š�\n");               
               set("material", "boots");
               set("armor_prop/dodge", 1);
       }
       setup();
}
