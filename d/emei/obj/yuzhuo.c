// zhihuan.c
// ָ��
#include <ansi.h>
#include <armor.h>
inherit HANDS;
inherit F_UNIQUE;
void create()
{
       set_name("������", ({ "yu zhuo", "zhuo" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "֧");
               set("long", "����һ֧�������ഫ�Ǵ�������͸�������������\n");
               set("value", 100000);
               set("no_get",1);                 
               set("no_give",1);
               set("unique", 1);
               set("treasure",1);
               set("material", "steel");
               set("armor_prop/armor", 10);
               set("no_put",1);
	       set("no_steal", 1);
               set("no_drop",1);
       }
       setup();
}


                

