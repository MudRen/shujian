#include <weapon.h>

inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("��Ҷ�ɵ�", ({ "liuye feidao", "feidao", "liuye" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ʺ�Ů��ʹ�õ���Ҷ�ɵ���\n");
		set("base_value", 1000);
		set("base_unit", "��");
                set("base_weight", 20);		
	}
	set_amount(20);
       init_throwing(20);
}
