// chungongtu.c ����ͼ
// By iceland
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"����ͼ"NOR, ({ "chungong tu", "tu" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("treasure",1);
		set("long", HIM"����һ�������ľ��飬���������һЩС�ˣ����ڸ���һЩ���顣\n"NOR);
		set("value", 15000);
		set("material", "silk");
	}
	setup();
}

void init()
{
	add_action("do_kan", ({"kan"}));
}

int do_kan(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("���뿴ʲô��\n");

	else {
		message_vision(HIM"$N��������ͼרע�Ŀ��ţ���һ��ֻ���������٣���������������\n"NOR, me);
		return 1;
	}
}
