#include "herb.h"

void create()
{
	set_name(YEL "������" NOR, ({ "tu fuling" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
		set("long", "�ݱ�ֲ�����Ѫ�������࣬�ǲ��ɶ�õ��ϼ�ҩ�ġ�\n");
                set("base_value", 4000);
                set("base_weight", 60);
		set("cure_s", 30);
		set("cure_d", 20);
		set("cure_n", 40);
	}
	setup();
}
