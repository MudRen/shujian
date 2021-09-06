// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2
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
		"east" : __DIR__"lichunyuan",
		"south" : __DIR__"nanmen",
		"west" : __DIR__"chaguan",
		"north" : __DIR__"nandajie1",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "east" && (int)me->query("age") < 18 && !wizardp(me))
		return notify_fail("小朋友不要到那种地方去！！\n");
	return 1;
}
//是镜像
int is_mirror() { return 1; }
