// shiliao.c
// by augx@sj  3/15/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"ʯ��"NOR, ({ "shi liao","liao" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������޽���·��ʯ�ϡ�\n");
		set("value", 5000000);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
}
