//黑风寨小路

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", "小路"NOR);
      set("long", @LONG
这里就是前寨通往后寨的小路，一队队的巡山喽啰侧身走过，警惕的打量着周围。
LONG);
      set("outdoors","黑风寨");
      set("exits", ([
            "westdown" : "/quest/hfz/qianzhai",
            "east" : "/quest/hfz/xiaolu2",
"north" : "/quest/hfz/chaifang",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }