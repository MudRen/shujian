// automake group room , Fri Jul 29 21:11:04 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","藏边土路");
set("long","这里已经进入了西藏，地势越来越高，空气稀薄，连呼吸都困难起来。
阳光分外刺眼，晒得人皮肤发紧，口干舌燥。遥遥往见远处一座城池，让
人不由得振奋精神，加快了脚步。
");
set("exits",([
"northeast":"/d/xueshan/tulu1","southwest":"/d/xueshan/tulu3","north":"/d/group/rysj/1311945064.c",
]));
set("outdoors","大雪山");
set("group",1);
setup();
}
