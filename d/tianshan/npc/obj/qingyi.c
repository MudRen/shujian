//qingyi.c
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("����", ({"qing yi", "cloth","yi"}) );
	set_weight(1000);
	if( clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǽ������ϼ����£�����ȥ�������Ĳ÷�������\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",0);
	}
	setup();
}
