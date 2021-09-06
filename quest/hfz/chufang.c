//厨房

#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", "厨房"NOR);
      set("long", @LONG
这里是黑风寨的厨房，平时杀猪宰牛，酿酒上菜都在这里，偶尔也杀几个肉票来做醒酒汤。
LONG);
      set("outdoors","");
      set("exits", ([
            "north" : "/quest/hfz/xiaolu2",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }