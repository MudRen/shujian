// douhua.c ������

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "������" NOR, ({"douhua"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ɫ��ϸ�ۣ�����ζ�ʣ�Դ�ڶ��������ڶ�����
������Ϊ���������ö����Լ����������ļ������͡�\n");
		set("unit", "��");
		set("value", 120);
		set("food_remaining", 1);
		set("food_supply", 30);
	}
}