// Room: /u/numa/thd/caodi.c
// Modified by Numa 19980903

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"�ݵ�"NOR);
        set("long",@LONG
һƬ�����͵Ĳݵ�ӳ��������������ʱ�е���Χ������һ�����µ����ա�
������һ��ͩľ��ɵ�ͤ�ӣ��������������ܲ�������������һ����ͺͺ��
ɽ·�������徿��ͨ�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "eastup" : __DIR__"shanjiao",
                "west" : __DIR__"shijian-ting",
                "south" : __DIR__"shangang",
                "north" : __DIR__"zhulin1",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","�һ���");

        setup();
}

