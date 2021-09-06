// Room: /city/ymdongting.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "破败正厅");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
	set("exits", ([
		"east" : __DIR__"dongting",
		"west" : __DIR__"xiting",
		"north" : __DIR__"neizhai",
		"south" : __DIR__"yamen",
	]));
	setup();
}

//是镜像
int is_mirror() { return 1; }