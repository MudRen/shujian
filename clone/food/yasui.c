// yasui.c Ѽ��

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("Ѽ��", ({"ya rou", "yarou","rou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ̲����ЩѪ˿��Ѽ�裬���������ҩ��\n");
		set("unit", "̲");
		set("value", 200);
		set("food_remaining", 1);
		set("food_supply", 20);
	}
}
