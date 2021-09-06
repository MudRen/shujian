// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "山海关");
    set("long", @LONG
     山海关古称榆关，也作渝关，又名临闾关，明朝洪武十四年（公元1381年），
中山王徐达奉命修永平、界岭等关，在此地创建山海关，因其北倚燕山，南连渤海，
故得名山海关。
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
