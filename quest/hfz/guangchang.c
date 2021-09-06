//黑风寨广场


#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", WHT"广场"NOR);
      set("long", @LONG
广场上两侧竖立着兵器架，当中一根旗杆高耸入云，上面飘扬着一面大旗，
上书【替天行道】几个大字。
LONG);
      set("outdoors","黑风寨");
      set("exits", ([
            "northup" : "/quest/hfz/panshan",
            "southdown" : "/quest/hfz/damen",
            "east" : "/quest/hfz/yanwu1",
            "west" : "/quest/hfz/yanwu2",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }