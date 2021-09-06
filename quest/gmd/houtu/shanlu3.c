#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"山路"NOR);
    set("long",@LONG
这是一条一窄又陡的山路，这里已见白雪，白雪盖着山路两旁又高又杂的
乱草杂树，极是美丽。你感到阵阵的寒意涌上心头。南边是半山腰。
LONG);
    set("exits",([
        "northdown"  :     __DIR__"gmd",
        "westup"   :     __DIR__"shanlu2",
    ]));
    set("coor/x",-320);
  set("coor/y",120);
   set("coor/z",70);
   set("coor/x",-320);
 set("coor/y",120);
   set("coor/z",70);
   setup();
    set("outdoors", "明教光明顶");
}
int is_mirror() { return 1; }