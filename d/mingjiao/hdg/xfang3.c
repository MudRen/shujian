// �᷿ xfang3.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "�᷿");
        set("long", @LONG
����һ�䲻����᷿������ڷ�ʮ�����룬������ǽ�ߵĵط�����һ��С
���������ǰ�ҩ������������Сͯ��Ϣ�ĵط���
LONG
        );

        set("exits", ([ 
            "west" : __DIR__"caotang",
            "south" : __DIR__"yaofang",
            "east" : __DIR__"shufang",
        ]));

        setup();
}
