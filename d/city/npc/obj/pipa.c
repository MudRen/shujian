#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "����" NOR, ({ "pi pa"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ǰ���ͷ�������⣬����̴�Ƴɵ�����ʮ��Ʒ���á�\n");
		set("value", 2000);
		set("material", "wood");
		}
	setup();
}