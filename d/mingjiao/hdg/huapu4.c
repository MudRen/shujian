// ���� huapu4.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "����");
        set("long", @LONG
�����Ǻ����ȵĻ��ԣ��ǡ��������ȡ�����ţ�����ָ��ָ���ҩ�ĵģ���
����������㻨�ݡ�
LONG
        );

        set("no_clean_up", 0);
        set("outdoors", "������");

        set("exits", ([
            "north" : __DIR__"houshan",
            "south" : __DIR__"chufang",
        ]));

        setup();
}