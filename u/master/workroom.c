// Room:jpei隐居之地
// Date: Jpei 2010

#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",  HIW "迷雾山崖" NOR);
	set("long", @LONG
这里是一个数丈高的山崖，你抬头一看，忽然发现山崖上生长着一颗朱果树，
不由得心中狂喜！你不住的往上看，竟然没注意到这里没有任何出路。
LONG
);

        set("no_clean_up", 0);
        set("no_death", 1);
        set("exits", ([
               "down" : "d/city/dangpu",
        ]));
        setup();
}
