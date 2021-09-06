#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIG"树林"NOR);
       set("long", @LONG
这是一片乱树林。几十丈高的树木簇在一块，密实的枝叶象一蓬蓬巨伞般
伸向天空，把阳光遮得丝毫也无。你一走进这这觉得阴阴森林的，你的感觉告
诉你，得赶快离开。
LONG);    
        set("exits", ([
                "southwest" : __DIR__"gmd",                                    
                "eastup" : __DIR__"shulin2",
        ]));             
        
        set("outdoors", "明教光明顶");
        set("coor/x",-300);
  set("coor/y",170);
   set("coor/z",100);
   setup();
}
//是镜像
int is_mirror() { return 1; }