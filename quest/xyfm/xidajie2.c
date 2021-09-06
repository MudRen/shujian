// Room: /city/xidajie2.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "小路");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"xidajie1",
		"south" : __DIR__"biaoju",
		"west" : __DIR__"ximen",
		"north" : __DIR__"caizhu",
	]));
	setup();
}

//是镜像
int is_mirror() { return 1; }