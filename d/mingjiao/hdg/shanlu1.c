// ɽ· shanlu1.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "ɽ·");
        set("long", @LONG
����һ������������ɽ·����֪ͨ��η���
LONG
        );

        set("outdoors", "������");

        set("exits", ([ 
            "northup" : __DIR__"shanlu3",
            "southwest" : __DIR__"kongdi", 
        ]));

        setup();
}
