// 9xie.c �Ŷ���Ь

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIY "�Ŷ���Ь" NOR, ({ "jiuer maxie", "maxie","xie","shoe" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "�ɲ��ٱ�֯���ɣ�������ֽ�ʵ��ǰ��֯�оŻ�����״����䡣");
		set("value", 300);
		set("material", "boots");
		set("armor_prop/dodge", 2);
	}
	setup();
}
