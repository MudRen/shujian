#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
       set_name(HIY "������" NOR, ({"shenlong biao", "biao"}));
       if( clonep() )
               set_default_object(__FILE__);
       else {
		set("long", "һ��ɫ�󰵺죬�����з���ͼ���ķ��ڡ�\n");               
               set("unit", "��");
               set("base_value", 10000);
               set("base_unit", "��");
               set("base_weight", 10);
       }
       set_amount(100);
       init_throwing(20);
}

