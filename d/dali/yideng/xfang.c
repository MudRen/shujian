// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "���᷿");
	set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵����ǽ����һ¯̴�㣬��
���һ�Ŵ󴲺������������������ǹ�Ů����Ϣ�ķ��䡣
LONG
	);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("exits", ([
		"east" : __DIR__"dadian",
	]));

	setup();
}
