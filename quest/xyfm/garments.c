// Room: /city/garments.c

inherit ROOM;

void create()
{
	set("short", "古演马场");
	set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG );
	
	set("exits", ([
		"down" : __DIR__"zahuopu",
	]));

	setup();
}

//是镜像
int is_mirror() { return 1; }