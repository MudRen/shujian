// guoba.c ������Ƭ

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "������Ƭ" NOR, ({"rou pian", "rou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��������Ƭ����ζ���ء�
�ϴ˲�ʱ����Ӧһ�ֶ�ʢ�н��ɫը�õĹ��Ͳ�����ϯ�ϣ� 
һ�ֳ���֭���룬Ѹ�ٽ���֭���ڹ����ϣ�������������Ȥ������\n");
		set("unit", "��");
		set("value", 120);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}