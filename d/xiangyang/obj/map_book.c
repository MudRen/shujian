#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "��������ͼ�᡻" NOR, ({ "xiangyang dituce", "dituce", "tuce", "map" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "һ����װ�ĵ�ͼ�ᣬ���Բ鿴(show)�����Ĵ��������\n");
		set("value", 50);
		set("material", "paper");
	}
	setup();
}
void init()
{
	add_action("show_map","show");
}

int show_map()
{
	write(read_file("/help/map/xiangyang"));
	return 1;
}
