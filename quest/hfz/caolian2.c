//黑风寨操练场

#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", WHT"操练场"NOR);
      set("long", @LONG
这里是一个小型的操练场，平常总有几个山寨的小头目在这里指点喽啰们操练。
LONG);
      set("outdoors","黑风寨");
      set("exits", ([
            "west" : "/quest/hfz/panshan3",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }