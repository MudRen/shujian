#include "herb.h"

void create()
{
	set_name(YEL "ɽ��" NOR, ({ "shan ju" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("base_unit", "��");
		set("long", "����ɽ�ϵ�ɽ�գ�ҩ�ģ����\n");
                set("base_value", 200);
                set("base_weight", 50);
		set("cure_s", 1);
		set("cure_d", 3);
		set("cure_n", 1);
	}
	setup();
}
