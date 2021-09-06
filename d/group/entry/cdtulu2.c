// automake group room , Sun Jul 24 09:59:14 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","土路");
set("long","这是一条尘土飞扬的小路，因为四川自古就是富庶之地，所以放眼望去，
四周的田垅里郁郁青青。
");
set("exits",([
"southwest":"/d/chengdu/tulu1","northeast":"/d/chengdu/tulu3","up":"/d/group/fengyun/1311472754.c",
]));
set("outdoors","峨嵋山");
set("group",1);
setup();
}
