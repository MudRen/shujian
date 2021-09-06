//黑风寨演武场
#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", "演武场"NOR);
      set("long", @LONG
这里是黑风寨的演武场，平常总有几个山寨的小头目在这里指点喽啰们操练。
LONG);
      set("outdoors","黑风寨");
      set("exits", ([
            "east" : "/quest/hfz/guangchang",
      ]));

      setup();
//  replace_program(ROOM);
}
int is_mirror() { return 1; }