// buzhan.c ����ճ

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "����ճ" NOR, ({"sanbuzhan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����ճ�Ƹ�Ǹ⣬������࣬�������������ζ����\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 35);
	}
}