// Room: /city/nanmen.c
// YZC 1995/12/04 
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "野地");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west" : __DIR__"work3",
		"north" : __DIR__"nandajie2",
	]));

	setup();
}

//是镜像
int is_mirror() { return 1; }
