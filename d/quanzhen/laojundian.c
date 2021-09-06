#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "老君殿");
        set("long", @LONG
这里是供奉太上老君的大殿。殿中塑着老君的塑像，老君
骑在青牛上，正临云而去。两旁塑着两个童子，栩栩如生。殿
中的地都是以青砖一块块的铺成，打扫得一尘不染。
LONG);
        set("exits", ([
                "east" : __DIR__"houtang1",
                "south" : __DIR__"tongtiandian",
                "north" : __DIR__"yuanshidian",
                "west" : __DIR__"datang3",
        ]));
        set("objects", ([
                 CLASS_D("quanzhen") + "/qiu" : 1,
        ]));
        setup();
}
/*
int valid_leave(object me, string dir)
{        
        if ((string)me->query("family/family_name") != "全真教" 
           && dir == "east"  
           && present("qiu chuji", environment(me)))
	return notify_fail(
"丘处机拦住你道：“里面是我教王重阳及弟子居所，你不能进去捣乱。”\n");

	return ::valid_leave(me, dir);
}

*/



