// road5.c
// Created by Numa 19991027

inherit ROOM;
#include "hmy_def.c"

void create()
{
        set("short", "��·");
	set("long", @LONG
����һ��ȥ��ľ�µıؾ�֮·��·�ϻ�ɳ���������߲�Զ���в���������
����������̽��ڵ��̲顣
LONG
        );
        set("exits", ([ 
          "southeast" : __DIR__"road4",
          "northwest" : __HMY__"shidao",
]));
        set("outdoors", "ƽ����");
        setup();
}

