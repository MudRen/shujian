// ROOM : /u/numa/thd/shilu.c
// Created by Numa 19990902

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
��̤��Сʯ�̣���ʱһ������ӳ������,�������������١�������
һ���鷿������������һ��������
LONG
        );
        set("exits", ([
                "south" : __DIR__"shidi",
                "north" : __DIR__"jingshe",
                "east" : __DIR__"bookroom",
                "west" : __DIR__"hall",
        ]));

        set("outdoors", "�һ���");

        setup();
}


