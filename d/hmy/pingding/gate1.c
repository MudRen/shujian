// gate1.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ƽ���ݵ������ţ�����������ƽ���ݳ����ˣ�һ������ֱͨ������
������һ��ͨ����ɽ�ĸɵ���
LONG
        );
        set("exits", ([ 
          "west" : __DIR__"road3",
          "east" : __DIR__"cj1",
]));
        set("outdoors", "ƽ����");
        setup();
}

