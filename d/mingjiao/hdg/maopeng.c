// é�� maopeng.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "é��");
        set("long", @LONG
������һ���ª��é�����ѷ���һЩ�ɲ��é�ݣ�����������������
�ģ�ǽ�߿���һЩ�����ͽ�ˮ�õ�ˮ����
LONG
        );

        set("outdoors", "������");

        set("exits", ([
            "north" : __DIR__"xfang2",
            "west" : __DIR__"huapu3",
            "east" : __DIR__"caojing",
        ]));

        setup();
}
