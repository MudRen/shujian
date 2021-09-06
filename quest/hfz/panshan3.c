//黑风寨盘山道
#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", CYN"盘山道"NOR);
      set("long", @LONG
这里就是从广场通往前寨的盘山石路，依山凿建，端的
是险要无比。一队队的巡山喽啰侧身走过，警惕的打量着周围。
LONG);
      set("outdoors","黑风寨");
      set("exits", ([
            "eastdown" : "/quest/hfz/panshan2",
"northup" : "/quest/hfz/qianzhai",
            "west" : "/quest/hfz/caolian",
"east" : "/quest/hfz/caolian2",
      ]));

      setup();
//  replace_program(ROOM);
}           
//是镜像
int is_mirror() { return 1; }
