#define FLOOR 9
#define SAVE_NPC "何太冲"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "宝塔九层");
        set("long","这里是万安寺内宝塔的第九层，戒备森严，一看就知道关押着重要人物。\n");
        set("exits", ([
                "down" : __DIR__"baota-8",
                "up" : __DIR__"baota-10"
        ]));
        setup();
}

#include "baota.h"