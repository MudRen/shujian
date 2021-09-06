// Room: /u/qingyun/jyzj/shanlu2.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条昆仑山上到处可见的山路。只是这里已随处可见梅树，梅花盛开
时到处一片火红，花香飘溢。西边是红梅山庄。
LONG	);
	set("exits", ([
                "west" : __DIR__"hmzhuang",
		"east" : __DIR__"shanlu1",
	]));
	set("outdoors", "昆仑山");
	set("no_clean_up", 0);

	setup();
}
