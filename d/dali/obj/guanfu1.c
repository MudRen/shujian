#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�ٷ�", ({ "guanfu", "cloth" }));
	set("long", "����һ�����������ļҽ�������ɫ�ٷ���������������������˿����������ơ�\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 0);
		set("armor_prop/armor", 10);
	}
	setup();
}
