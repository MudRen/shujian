// baojia.c Ìì²Ï±¦¼×

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW "Ìì²Ï±¦¼×" NOR, ({ "bao jia", "jia" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("unique", 1);
		set("treasure", 1);
		set("value", 50000);
		set("material", "gold");
		set("armor_prop/armor", 50);
	}
	setup();
}
