#include <ansi.h>
inherit ITEM;
void create()
{
       set_name("������", ({ "tieyan ling", "ling" }) );
       set_weight(1000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "Ƭ");
               set("long", "����һƬ�������ƣ��ɻ�����״��\n");
               set("value", 20);
               set("no_drop",1);
               set("no_get",1);
               set("no_steal",1);
               set("material", "iron");          
       }
       setup();
}

