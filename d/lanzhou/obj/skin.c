#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"��Ƥ"NOR, ({ "skin" }));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
                set("value", 0);
                set("treasure",1);
                set("material", "paper");
        }
}
