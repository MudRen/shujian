// ���� huapu3.c
 
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

        set("outdoors", "������");

        set("exits", ([
            "east" : __DIR__"maopeng",
        ]));

        setup();
}