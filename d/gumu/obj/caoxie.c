// caoxie.c ��Ь
// kxkxkx 2004��3��

#include <armor.h>

inherit BOOTS;

void create()
{
   set_name("��Ь", ({"cao xie", "xie"}));
   set_weight(1000);
   if(clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "˫");
      set("long", "һ˫���ݱ�ɵ�Ь�ӡ�\n");
      set("value", 0);
      set("material", "boots");
      set("armor_prop/dodge", 1);		
   }
   setup();
}
