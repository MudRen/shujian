#include <weapon.h>

inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("˦��", ({ "shuaijian", "jian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������Ƴɵ�˦����\n");
		set("base_value", 2000);
		set("base_unit", "֧");
                set("base_weight", 50);		
	}
	set_amount(20);
       init_throwing(30);
}
