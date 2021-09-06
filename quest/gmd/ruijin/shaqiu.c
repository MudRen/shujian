#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"小沙丘"NOR);
       set("long", @LONG
这是一个堆满黄沙的小沙丘。你一踏上来就迷失了方向。看来要走出这块
沙漠并非易事。
LONG);    

        set("exits", ([
                "westup" : __DIR__"shaqiu1",                                    
                "east" : __DIR__"ruijin"+(random(2)+1),
        ]));             
        
        set("outdoors", "明教光明顶");
        set("coor/x",-300);
  set("coor/y",170);
   set("coor/z",100);
   setup();
}
//是镜像
int is_mirror() { return 1; }