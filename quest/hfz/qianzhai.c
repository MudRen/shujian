//黑风寨前寨

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", HIC"前寨"NOR);
      set("long", @LONG
这里是黑风寨的前寨，是半山腰一块平坦的所在。寨子中的小
头目们如果不在前头广场较量或训练喽啰，往往自己在这个地方呆着。
LONG);
      set("outdoors","黑风寨");
      set("exits", ([
"southdown" : "/quest/hfz/panshan3",
            "eastup" : "/quest/hfz/xiaolu",
"north" : "/quest/hfz/kufang",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }