// yuebing.c �±�
// Lklv 2001.9.28 update

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"�±�"NOR, ({"yue bing", "yuebing", "bing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
	 	set("long", "���Ǹ��й���������ڳ��Ե��±������ƾ�ϸ��������塣\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}