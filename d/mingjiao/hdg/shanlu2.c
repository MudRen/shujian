// ɽ· shanlu2.c
 
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
            "northup" : __DIR__"shanlu4",
            "southeast" : __DIR__"kongdi",
        ]));

        setup();
}
