#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("������", ({ "shouwei shu", "shu" }) );
       set_weight(1000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "Ƭ");
                set("long", "����һƬ����Ƭ���Ƶ����ƣ��������������ӵ����֤����\n");
               set("value", 20);
               set("material", "bamboo");          
       }
       setup();
}
