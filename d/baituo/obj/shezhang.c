#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(HIG"����" NOR, ({ "she zhang", "shezhang", "zhang"}));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������������ߵ����ȡ�\n");
		set("value", 5000);
		set("material", "steel");
		set("poisoned", "snake_poison");
                set("poison_number", 100);
	}
	init_staff(30);
	setup();
}


