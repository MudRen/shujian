// meat.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"rou", "meat"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ����յ����⣬��ð�������ء�\n");
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 2);
		set("food_supply", 25);
	}
}
