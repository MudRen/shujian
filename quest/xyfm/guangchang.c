// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "野外平地");
    set("long", @LONG
     这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。
LONG
    );
        set("outdoors", "city");
       set("exits", ([
        "east" : __DIR__"dongdajie1",
        "south" : __DIR__"nandajie1",
        "west" : __DIR__"xidajie1",
        "north" : __DIR__"beidajie1",
	    ]));
    setup();
}

//是镜像
int is_mirror() { return 1; }
