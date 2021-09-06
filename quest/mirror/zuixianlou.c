// Room: /d/city/zuixianlou.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "箭楼");
	set("long", @LONG
	箭楼为重檐歇山顶、灰筒瓦绿琉璃剪边。上下共四层，
东、南、西三面开箭窗94个，供对外射箭用。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"beidajie2",
  	
]));
	setup();
}

//是镜像
int is_mirror() { return 1; }