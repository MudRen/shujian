// ya.c ��������Ѽ

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "��������Ѽ" NOR, ({"shenxian ya", "ya"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��������ѼѼ�������ޱȣ���֭������̣�ζ��������
��Ӫ�������һ��п�θ���������������Ч��\n");
		set("unit", "ֻ");
		set("value", 250);
		set("food_remaining", 3);
		set("food_supply", 70);
	}
}