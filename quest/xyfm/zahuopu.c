// Room: /city/zahuopu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "无名铺子");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
	
	set("exits", ([
		"north" : __DIR__"dongdajie1",
                "up" : __DIR__"garments",
	]));
	setup();
}

//是镜像
int is_mirror() { return 1; }