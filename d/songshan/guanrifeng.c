//���շ�

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR "���շ�" NOR);
	set("long", 
"�������"HIG"��ɽ���շ�"NOR"��������һվ,�㲻����һ��:\n\n"
"          ���������,ǧɽĺѩ,ֻӰ��˭ȥ?\n\n"
"�ĸо�,�����м���ʯͷ,���������ʿƽʱ���������ĵط�!\n\n"
);
	set("outdoors", "��ɽ");

	set("exits",([
		"west":__DIR__"fengchantai",
	]));
	setup();
}

void init()
{
	add_action("do_guan", "guan");
}

int do_guan(string arg)
{
	object me=this_player();
	if (me->is_busy())
		return notify_fail("��������æ���أ�\n");
	if( !arg || arg=="" ) return 0;
	if( arg=="sun" ){
		message_vision("$N��ʯͷ��һվ,���Ÿո������̫��,��������ڤ˼��\n", me);
		return 1;
	}
}
