// ��ɽ houshan.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "��ɽ");
        set("long", @LONG
�����Ǻ����ȵĺ�ɽ���ǳ��տ����Եúܰ��������涼�������ͱڣ�����
������Դһ�㡣
LONG
        );

        set("outdoors", "������");

        set("exits", ([
            "south" : __DIR__"huapu4",
        ]));

        setup();
}
