#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", YEL"蒙古营帐"NOR);
                set("long", @LONG
这是蒙古攻击襄阳的临时军营，营帐中几个披挂着盔甲的将军走来走去正
在和一个看起来样子象谋士的人大声的谈论、争执着什么。营帐外有几个士兵
在巡逻。
LONG
        );

        set("no_save", 1);
        set("outdoors", "襄阳");
        

        set("objects", ([
           //     NPC_D("guanfu/wujiang") : 1,
            //    NPC_D("guanfu/bing") : 2,
        ]));
       
        set("incity",1);
        setup();
}
