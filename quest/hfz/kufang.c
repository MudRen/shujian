//库房

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", HIB"库房"NOR);
      set("long", @LONG
这里是黑风寨的库房，这里存放着土匪们平常下山劫掠来的物资和
宝物，自然是派了重兵把守。
LONG);
      set("outdoors","");
      set("exits", ([
            "south" : "/quest/hfz/qianzhai",
      ]));

      setup();
//  replace_program(ROOM);
}
//是镜像
int is_mirror() { return 1; }