// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjfhm.c

inherit ROOM;
#include <room.h>;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ������ĺ��š��������߾��Ǻ�԰�ˣ���û���ţ�����ŵ�һ��
�����Ļ��㡣
LONG
        );
        set("exits", ([
                "north"  : __DIR__"jjfzht",
                "south"  : __DIR__"jjfhhy",
                ]));

        set("incity",1);
	setup();
        create_door("south","����","north",DOOR_CLOSED);
}
