// ROOM : /u/numa/thd/shidi.c
// Created by Numa 19990902

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "Сʯ��");
        set("long", @LONG
��̤��Сʯ�̣��������У����Ժ�Ҷ��������������󡣱��治
Զ����һ�����ӡ�
LONG
        );
        set("exits", ([
                "south" :  __DIR__"hetang",
                "north" : __DIR__"shilu",
        ]));

        set("outdoors", "�һ���");

        setup();
}


