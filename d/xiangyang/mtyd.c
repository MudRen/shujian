// update by Lklv for new nanyang city 2001.10.11

#include <ansi.h>
inherit ROOM;

void meet();
void create()
{
        set("short", "摩天崖顶");
        set("long", @LONG
这里是一处十分峻急的山崖，号称“摩天崖”，崖上山风吹动，沁人心脾。
LONG
        );
        set("outdoors", "襄阳郊外");
        set("exits", ([
                "down" :"/d/xiangyang/motianya",
        ]));
        set("objects",([
                "/d/xiangyang/npc/shipotian" : 1,
         ]));

        
        setup();
}


