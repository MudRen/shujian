
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIW"ѩ��Ь"NOR, ({ "xuehong xie", "shoe", "shoes", "xie" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ˫С�ɵ�Ů��Ь��\n");
		set("unit", "˫");
		set("value", 300);
		set("female_only",1);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("armor_prop/dodge", 10);
	}
	setup();
}
