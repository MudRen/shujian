// é�� maowu.c
 
#include <ansi.h>

inherit ROOM;

void create() 
{ 
        set("short", "é��");
        set("long", @LONG
������һ���ª��é�ݣ����аڷ���һ��ľ������Χ����ط��ż��ŵ���
��һ��Сͯ������������˯�������������ˣ���æ�����ӭ�������������
����������һ��ҩ�����˹���������һ�����ӣ���֪����ʲô�ط���
LONG
        );

        set("exits", ([
            "north" : __DIR__"caotang",
            "west" : __DIR__"xfang2",
            "south" : __DIR__"caojing",
            "east" : __DIR__"yaofang",
        ]));

        setup();
}
