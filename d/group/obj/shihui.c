// shihui.c
// by augx@sj  3/15/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"ʯ��"NOR, ({ "shi hui","hui" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ˢ�����ʯ�ҡ�\n");
		set("value", 1500000);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
}
