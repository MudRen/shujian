
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ɽ��", ({"dong shanyang", "dong", "shanyang"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ճ����������⣬�����ز���\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
