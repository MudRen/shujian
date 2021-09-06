//黑风寨山寨大门

#include <ansi.h>

inherit ROOM;
void create()
{
set("short", "山寨门");
      set("long", @LONG
这里就是本地最大的山寨“黑风寨”了。头里就是寨子的大门，有寨
子里的喽啰走来走去的巡逻。从寨子里不时传来一阵阵粗野的叫喊声。
LONG);
      set("outdoors","黑风寨");
      set("exits", ([
            "northup" : "/quest/hfz/guangchang",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }
