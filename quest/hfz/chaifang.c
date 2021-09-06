//柴房

#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", "柴房"NOR);
      set("long", @LONG
这里是黑风寨的柴房，平时也用来关押一些绑来的“肉票”。
LONG);
      set("outdoors","");
      set("exits", ([
            "south" : "/quest/hfz/xiaolu",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }