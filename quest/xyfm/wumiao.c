// Room: /city/wumiao.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "土地庙");
    set("long", @LONG
时逢乱世，神仙也不能自保，土地公公早已不知去向。


LONG
    );

    set("exits", ([
        "east" : __DIR__"beidajie2",
    ]));
        setup();
}
//是镜像
int is_mirror() { return 1; }