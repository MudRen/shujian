//黑风寨聚义厅

#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", HIY"聚义厅"NOR);
      set("long", @LONG
这里就是寨子中头几把交椅平常讨论事情的地方，学着侠义小说当
中的样子起个【聚义厅】的名号。但实际上恐怕叫做【分金堂】更为合适。
LONG);
      set("outdoors","黑风寨");
      set("exits", ([
            "west" : "/quest/hfz/xiaolu2",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }