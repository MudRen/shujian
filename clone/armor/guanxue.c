// /clone/armor/guanxue.c   ��ѥ

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create()
{
	set_name(HIW"��ѥ"NOR, ({ "guan xue", "xue","shoes" }));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ˫��͢��Ա���õĹ�ѥ��\n");
		set("unit", "˫");
		set("value", 200);
		set("no_transfer",1);
		set("material", "cloth");
		set("armor_type", "feet");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 3);
	}
	setup(); 
}
