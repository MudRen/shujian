// С�� xiaojing1.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "С��");
        set("long", @LONG
������С·����һ�̣������𽥶�������������Ӽӿ�Ų���ǰ��ȥ��
LONG
        );

        set("outdoors", "������");

        set("exits", ([ 
            "north" : __DIR__"xiaojing2",
            "south" : __DIR__"xiaojing",
        ]));

        setup();
}
