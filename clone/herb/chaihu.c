#include "herb.h"

void create()
{
        set_name(CYN "���" NOR, ({ "chai hu", "chai", "hu", "herb_chaihu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 4000);
                set("base_weight", 60);
		set("cure_s", 2);
		set("cure_d", 1);
		set("cure_n", 1);                
        }
        setup();
}
