// ROOM : /u/numa/thd/hetang.c
// Created by Numa 19990901

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIW"����"NOR);
        set("long", @LONG
���������۵�ת�����֣���ǰ����һ��Ƭ���������а���ʢ�ţ���
��������Ҷ���һ��Сʯ�̴����������롣
LONG
        );
        set("exits", ([
                "south" :  __DIR__"zhulin1",
                "north" : __DIR__"shidi",
        ]));

        set("outdoors", "�һ���");

        setup();
}


