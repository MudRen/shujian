// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ʯ���᷿");
	set("long", @LONG
����С���ϵ���һ¯̴�㣬�����ı���Ȼ����һ�����⣬ֻ����������
������İڷ��š�
LONG
	);
	set("exits", ([
		"west" : __DIR__"shiwu",
	]));

	setup();
}
