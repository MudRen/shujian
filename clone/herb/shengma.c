#include "herb.h"

void create()
{
	set_name(YEL "����" NOR, ({ "sheng ma" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
		set("long", "����ɽ�ϵ���ͨҩ�ġ�\n");
                set("base_value", 4000);
                set("base_weight", 60);
		set("cure_s", 1);
		set("cure_d", 1);
		set("cure_n", 2);
	}
	setup();
}
