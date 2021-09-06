inherit ROOM;

#include <ansi.h>
#include <room.h>



void create()
{
        set("short", "中军大帐");
        set("long", @LONG
  据说最近蒙古大军因为久攻襄阳不下，准备绕行西南进取大理，以便迂回。
这里就是蒙古准备进攻大理方面的临时指挥军帐，时时有士兵来回巡逻。
LONG
        );
        set("xyjob", 1);
        set("outdoors", "襄阳");
        set("objects", ([
                __DIR__"npc/ci-en" : 1,
               __DIR__"npc/jinlun-fawang" : 1,
        ]));

      	setup();
}


