// By Spiderii 
inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIW"��ɫ����"NOR, ({ "shense baofu", "bao fu" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "��");
               set("long", "����һ���������۵���ɫ������\n");
               set("value", 100000);
               set("no_get",1);                 
               set("no_drop",1);
               
       }
       setup();
}
