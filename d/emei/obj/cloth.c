// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIC"Çà²¼ç»ÒÂ"NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "cloth");
		set("female_only", 1);
		set("armor_prop/armor", 1);
	}
	setup();
}
