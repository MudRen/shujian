// Room: /d/huashan/jinshe/obj/jinshe-zhui.c
// Date: Look 99/03/25

#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
       set_name(HIY "����׶" NOR, ({"jinshe zhui", "jinshe", "zhui" }));
       if( clonep() )
               set_default_object(__FILE__);
       else {
		set("long", "���������������εİ�����\n");               
               set("unit", "��");
       set("base_value", 0);
               set("base_unit", "ö");
               set("base_weight", 10);
       }
      set_amount(1);
       init_throwing(40);
}

