#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "狭路");
       set("long",@LONG
这里是一条极其狭窄的小路，大约只容两个人并排而过，定非善地。
LONG);

       set("exits",([
            "westdown" : __DIR__"xialu",
            "northwest"  : __DIR__"xiaolu2",
            
       ]));
       set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",90);
   set("coor/x",-310);
 set("coor/y",110);
   set("coor/z",90);
   setup();
       set("outdoors", "明教光明顶");
}
//是镜像
int is_mirror() { return 1; }