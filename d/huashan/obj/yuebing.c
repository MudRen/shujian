// ITEM: /d/huashan/obj/yuebing.c
// Date: Look 99/03/25

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����±�", ({"bingtang yuebing", "yuebing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����˴������εı����±���\n");
		set("unit", "��");
		set("value", 250);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
