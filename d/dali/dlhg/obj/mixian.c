// mixian.c ��������
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"��������"NOR, ({"guoqiao mixian","mixian"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ⱥ����Ĺ������ߡ�\n");
		set("unit", "��");
		set("value", 500);
		set("food_remaining", 3);
		set("food_supply", 80);
	}
}
