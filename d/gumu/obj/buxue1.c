// buxue1.c   ��ѥ
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIW "�ײ�ѥ" NOR, ({ "bai buxue", "buxue", "shoe" }) );
	set_weight(150);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫�ײ������Ƴɵ�ѥ�ӡ�\n");
		set("value", 0);
		set("material", "boots");
		set("armor_prop/dodge", 2);		
	}
	setup();
}
