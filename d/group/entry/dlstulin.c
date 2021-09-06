// automake group room , Wed Aug  3 19:29:22 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","土林");
set("long","一踏进土林。那千姿百态的造型，就仿佛使人进入另一个新奇天地。有的
土柱如锥似剑，直蓝天；有的象威严武士，整装待发；有的如婷婷少女，凝视
远方，有的土柱顶上杂草丛生，间或长有野花；有的砂石垒垒，裸露身躯。
");
set("exits",([
"north":"/d/dali/dalisouth/dg1","west":"/d/dali/yideng/fanpu","southup":"/d/dali/dalisouth/xiushan","northwest":"/d/group/peace/1312370962.c",
]));
set("outdoors","大理城南");
set("group",1);
setup();
}
