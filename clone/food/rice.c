// rice.c ���׷�

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�׷�",({"mi fan", "rice", "fan" }));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��մӹ���ʢ�����Ĵ��׷�����ð������������\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 40);
	}
}
