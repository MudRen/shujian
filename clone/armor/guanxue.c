// /clone/armor/guanxue.c   ¹ÙÑ¥

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create()
{
	set_name(HIW"¹ÙÑ¥"NOR, ({ "guan xue", "xue","shoes" }));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","ÕâÊÇÒ»Ë«³¯Í¢¹ÙÔ±¹ßÓÃµÄ¹ÙÑ¥¡£\n");
		set("unit", "Ë«");
		set("value", 200);
		set("no_transfer",1);
		set("material", "cloth");
		set("armor_type", "feet");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 3);
	}
	setup(); 
}
