
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�嶹��", ({"ban doufu", "doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ͨ�ļҳ�������ɢ�������㡣\n");
		set("unit", "��");
		set("value", 70);
		set("food_remaining", 1);
		set("food_supply", 80);
	}
}
