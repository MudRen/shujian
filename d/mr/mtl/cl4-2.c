// /u/beyond/mr/cl4-2.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"长廊"NOR);
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃瓦，
使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、家丁们走
来走去，都忙着自己的事情，东面是长廊的延伸，南面是客厅，西面就是后院。
long);
	set("exits", ([
		"west" : __DIR__"houyuan",
		"south" : __DIR__"keting",
		"north" : __DIR__"cl4",
		"east" : __DIR__"cl4-3",
	]));
	setup();
}
