
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��䶹��", ({"feicui doufu", "doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ����Ĵ󶹸����۵����˲����뵽�ϰ������������\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 50);
	}
}
