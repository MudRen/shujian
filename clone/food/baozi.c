// dumpling.c ����
// lklv 2001.9.28 update

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"bao zi", "baozi", "dumpling"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������������ӡ�\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
