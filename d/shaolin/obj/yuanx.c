// mala-doufu.c ��������

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Ԫ��", ({"yuanxiao", "yuan", "xiao"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ������Ử������ɿڵ�Ԫ������Ϊ�˼ѽ��ص����˸��Ƶġ�\n");
                set("unit", "��");
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
