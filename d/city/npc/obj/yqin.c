#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN "����" NOR, ({ "yao qin", "qin"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ǰ�����ʱⳤ���Σ��û���ľ�Ƴɣ�ʮ���ҵ����١�\n");
		set("value", 2000);
		set("material", "wood");
		}
	setup();
}