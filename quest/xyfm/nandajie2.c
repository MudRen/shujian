// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2
inherit ROOM;
void create()
{
	set("short", "野地");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

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
