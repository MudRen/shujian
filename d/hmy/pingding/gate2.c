// gate1.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ƽ���ݵı����ţ��������߾���ƽ���ݳ����ˣ�һ������ֱͨ������
������һ��ͨ����ľ�µ���·������һЩ�����������߶��⣬�������������
���ˡ�
LONG
        );
        set("exits", ([ 
          "north" : __DIR__"road4",
          "south" : __DIR__"cj4",
]));
        set("outdoors", "ƽ����");
        setup();
}

