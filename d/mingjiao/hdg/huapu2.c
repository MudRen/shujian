// ���� huapu2.c
 
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
            "west" : __DIR__"xfang1",
        ]));

        setup();
}