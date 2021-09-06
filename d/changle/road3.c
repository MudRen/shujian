// automake group room , Sat May 21 12:59:36 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","大驿道");
set("long","你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶着大
车的马夫，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起
一路尘埃。马上的人个个身着劲装，衣甲鲜明，有的还随身佩带着刀剑。看来
都是些习武的江湖人。道路两旁是整整齐齐的杨树林。
");
set("exits",([
"north":"/cmds/leitai/bwdh/zongtai",
"southwest":__DIR__"road1",
]));
set("outdoors","长乐帮");
set("group",1);
setup();
}
