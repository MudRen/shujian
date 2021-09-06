
// Room: /city/kedian.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN"有间客栈"NOR);
        set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
        );

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜一两白银。\n",
        ]));

        set("exits", ([
                "west" : __DIR__"beidajie1",
                "up" : __DIR__"kedian2",
        ]));
        setup();
}

//是镜像
int is_mirror() { return 1; }
