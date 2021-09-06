// Room: /city/dongdajie1.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "城池");
	set("long", @LONG
	山海关的城池，周长约4公里，是一座小城，整个城池与长城相连，以
城为关。城高14米，厚7米。全城有四座主要城门，并有多种古代的防御建筑，是
一座防御体系比较完整的城关。
LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"zahuopu",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"shuyuan",
	]));
	setup();
}
//是镜像
int is_mirror() { return 1; }