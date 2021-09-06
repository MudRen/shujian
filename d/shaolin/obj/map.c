#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "����������ͼ��" NOR, ({ "shaolin lvyoutu", "tu" }) );
	set_weight(2);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "һ����������ͼ�����Բ鿴(show)���ָ�ò��\n");
		set("value", 50);
		set("material", "paper");
		set("map", "shaolin");
	}
	setup();
}
void init()
{
	add_action("show_map","show");
}

int show_map(string arg)
{
	if (arg != "shaolin lvyoutu" && arg != "lvyoutu")
		return notify_fail("��Ҫ�鿴ʲô��\n");
	write(read_file("/help/map/shaolin"));
	return 1;
}
