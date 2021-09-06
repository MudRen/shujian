#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"洪水旗"NOR);
       set("long", @LONG
这里是洪水旗。此旗有十分厉害的水阵，旗中弟子个个深通水性。向东就
是通往碧水寒潭的山间小路了。
LONG);    
        set("exits", ([
                "west" :  __DIR__"hongshui4",
                "south" : __DIR__"hongshui2",
                "east" :  __DIR__"hongshui3",
                "north" : __DIR__"hongshui1",
        ]));
                 
        
        set("outdoors", "明教光明顶");
     
   setup();
}


//是镜像
int is_mirror() { return 1; }
