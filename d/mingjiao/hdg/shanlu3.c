// ɽ· shanlu3.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "ɽ·");
        set("long", @LONG
����һ������������ɽ·�����洫���������㣬��ѭ���������˹�ȥ��
LONG
        );
        
        set("outdoors", "������");

        set("exits", ([ 
            "southdown" : __DIR__"shanlu1",
            "eastdown" : __DIR__"huapu1",
        ]));

        setup();
}
