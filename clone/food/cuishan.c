// cuishan.c  ��Ϫ����

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "��Ϫ����" NOR, ({"liangxi cuishan", "cuishan"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��Ϫ��������һ������������ɽ���������£�ɫ�ʽ��֣��ڹ�������
���ܽ������أ������������ڣ��������̣��н����㡣\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 2);
		set("food_supply", 35);
	}
}