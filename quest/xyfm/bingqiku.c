// Room: /city/bingqiku.c
// YZC 1995/12/04 
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "荒村客栈");
	set("long", @LONG
	这里是一处废弃了的客栈，早无人打理，倒变作了野狐黄狼栖息之所。

LONG
	);
	set("exits", ([
		"north" : __DIR__"bingyin",
	]));
	setup();
}
//是镜像
int is_mirror() { return 1; }
