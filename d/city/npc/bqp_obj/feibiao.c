#include <weapon.h>

inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("��Ǯ��", ({ "jinqian biao", "feibiao" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ϸ����");
		set("base_value", 1000);
		set("base_unit", "��");
                set("base_weight", 20);		
	}
	set_amount(20);
       init_throwing(20);
}
