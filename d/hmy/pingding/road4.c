// road4.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ��ȥ��ľ�µıؾ�֮·��·�ϻ�ɳ�������ϱ���ƽ���ݵı����ţ�
���߲�Զ����һ��ǳ̲��
LONG
        );
        set("exits", ([ 
          "south" : __DIR__"gate2",
          "northwest" : __DIR__"road5",
]));
        set("outdoors", "ƽ����");
        setup();
}
