// yaoliu.c ��������

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "��������" NOR, ({"fanqie yaoliu", "yaoliu"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�����������ص����������ۣ�ζ�����ᣬ֭Ϊ��ɫ��\n�����Ｙ��λ�����������ϸ������Ҷ״�����׳�������\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}