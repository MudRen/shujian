// paper.c ��ֽ
// By River@SJ 

inherit ITEM;
#include <ansi.h> 

void create()
{
	set_name(HIW"��ֽ"NOR, ({ "bai zhi", "bai", "zhi" }));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ÿɸɾ����İ�ֽ�����������������۵�Щʲô��\n");
		set("value", 100);
		set("material", "paper");
	}
	setup();
}
