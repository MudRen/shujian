// skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ʳ�ȹ", ({ "color skirt", "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("armor_prop/personality", 1);
		set("female_only", 1);
	}
	setup();
}

