// �յ� kongdi.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "�յ�");
        set("long", @LONG
������һƬ��Ŀյأ���˵�����������ʦ��������������еģ��յ�
�ұ���һ��СϪ������������֪ͨ���η���
LONG
        );

        set("outdoors", "������");

        set("exits", ([ 
            "north" : __DIR__"niupeng",
            "northeast" : __DIR__"shanlu1",
            "northwest" : __DIR__"shanlu2",
            "southwest" : __DIR__"xiaojing2",
        ]));

        setup();
}
