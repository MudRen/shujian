
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({"doufu gan", "doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ɫ��ɹ�ĺܸɵĶ����ɣ���\n");
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
