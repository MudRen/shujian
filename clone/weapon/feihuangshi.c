#include <weapon.h>

inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("�ɻ�ʯ", ({ "feihuang shi", "shi", "feihuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ѵ�С���ȵķɻ�ʯ��\n");
		set("base_value", 500);
		set("base_unit", "��");
                set("base_weight", 30);		
	}
	set_amount(50);
       init_throwing(10);
}
