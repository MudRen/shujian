#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
       set_name(HIY "��" NOR, ({"jin hua", "jin", "hua" }));
       if( clonep() )
               set_default_object(__FILE__);
       else {
		set("long", "һ�������ã���������ģ��ƽ����ɵ�÷����\n");               
               set("unit", "��");
               set("base_value", 10000);
               set("base_unit", "��");
               set("base_weight", 10);
       }
       set_amount(81);
       init_throwing(20);
}

