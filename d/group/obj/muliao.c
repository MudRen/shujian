// shiliao.c
// by augx@sj  3/15/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"ľ��"NOR, ({ "mu liao","liao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������޽����ݵ�ľ�ϡ�\n");
		set("value", 2000000);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
}
