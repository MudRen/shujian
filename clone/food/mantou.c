// mantou.c ��ͷ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ͷ",({"man tou", "mantou", "tou" }));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���մ��������ó����İ���ͷ����ð������������\n");
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 2);
		set("food_supply", 40);
	 }
}