//Cracked by Roath
// caoliao.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"cao", "cao liao"}));
	set_weight(200+random(200));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ι�������õĲ��ϡ�\n");
		set("unit", "��");
		set("value", 20+random(50));
		set("food_remaining", 1);
		set("food_race","����");
		set("food_supply", random(100));
	}
}
