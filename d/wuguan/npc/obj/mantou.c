// mantou.c ��ͷ

inherit ITEM;

void init();
inherit F_FOOD;

void create()
{
	set_name("��ͷ",({"mantou", "man tou", "tou" }));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���մ��������ó����İ���ͷ����ð������������\n");
		set("unit", "��");
		set("value", 120);
		  set("food_remaining", 5);
		  set("food_supply", 40);
	 }
}


