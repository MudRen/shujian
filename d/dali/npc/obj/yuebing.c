// yuebing.c ɽ����

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{      
	set_name("ɽ����", ({"shanji rou", "rou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
	 	set("long", "�����ô�ɽ��������ɽ���Ƴɵ�Ұζ��\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
