// 18muou.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ʮ��ľż", ({ "muou", "ou" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY "����һ��Сľ�У����е����޻�������������ľż�������ϲ\n"+
			"�ò�������ʹ�����ᣬ�������ŭ����ȺͿ��ף���һ��ͬ��\n"NOR);
		set("value",0);
		set("treasure", 1);
		set("material", "wood");
	}
}
