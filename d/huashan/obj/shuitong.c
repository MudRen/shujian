// ITEM: /d/huashan/obj/shuitong.c
// Date: Look 99/03/25

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("ˮͰ", ({"shui tong", "shuitong", "tong"}));
	set_weight(90000);
	set_max_encumbrance(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ľͷ�Ƴɵ�СˮͰ��\n");
		set("unit", "��");
		set("no_drop", 1);
		set("no_get", 1);
		set("value", 100);
	}

}

int is_container() { return 1; }


