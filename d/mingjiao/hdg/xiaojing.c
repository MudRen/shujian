// С�� xiaojing.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "С��");
        set("long", @LONG
������һ��ͻȻ���ּ�ֻ������ǰ��ȥ�������ﲻ��һϲ�����ź�����
�ķ������˹�ȥ��
LONG
        );

        set("outdoors", "������");

        set("exits", ([ 
            "north" : __DIR__"xiaojing1",
            "south" : __DIR__"huacong1",
        ]));

        setup();
}
