// kaoya.c ��Ѽ

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
set_name(MAG"��Ѽ"NOR, ({"kaoya", "ya"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ʵ����͵ı�����Ѽ��\n");
		set("unit", "ֻ");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}