// thread.c
// By jpei
// Modify By River@SJ

#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
	set_name(HIW"ϸ˿"NOR, ({ "xi si", "thread", "si" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��������Ƥ��ɵ�ϸ˿��\n");
		set("material", "wood");
                set("base_unit", "��");
                set("base_weight", 100);
	}
        set_amount(1);
	setup();
}
