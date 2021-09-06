// tieqinju.c 铁琴居

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",MAG"铁琴居"NOR);
        set("long",@long
这儿便是“铁琴先生”何太冲的居处。房间陈设颇为精巧，物品与中土所
见别是不同。几个昆仑派弟子守在这里，个个深有忧色。东边通往三圣堂，西
边通往卧室，上面便是何太冲日常教授弟子所在之处。
long);

        set("objects",([
            __DIR__"npc/kl-dizi2.c" :   1,
           __DIR__"npc/kl-dizi4.c" :   1,
        ]));

        set("exits", ([
             "northeast" : __DIR__"jiuqulang1",
             "west" : __DIR__"sleeproom",
             "up" : __DIR__"tieqinju1",
        ]));

        set("no_clean_up", 0);
        create_door("west", "小门", "east", DOOR_CLOSED);
        setup();
}

