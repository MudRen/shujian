// Room: /d/shaolin/lhtang.c
// Date: by zqb

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�Һ�");
	set("long", @LONG
��������޺����Ҷ�֮�󣬺������ʲô�����������
LONG
	);
	set("indoors", "shaolin");
	set("objects",([
		__DIR__"obj/baitie" : 1,   
	]));
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me=this_player();  

	if (arg!="down") return 0;
	if (me->is_busy()) return 0;
	message_vision("$Nһ����������ȥ��\n", me);
	me->move(__DIR__"lhtang");
	tell_room(environment(me), me->name()+"���Ҷ������˹�����\n", me);
	return 1;
}
