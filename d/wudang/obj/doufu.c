// doufu.c ���Ŷ���

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "���Ŷ���" NOR, ({"doufu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��ѩ��ϸ�۵Ķ����ϡ���׺���غ�ɫ��ţ��ĩ�����̵������磬
��ΧһȦ͸���ĺ��ͣ����������꣬�����顢�����̡��ۡ��֡��㡢�ʵĶ��ط�ζ��\n");
		set("unit", "��");
		set("value", 60);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}