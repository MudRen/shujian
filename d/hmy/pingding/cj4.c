// cj4.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ƽ�����ڵ�һ�����֣�·���������������ַǷ�����Ϊ�˵غ����½�
��̳��ľ����ȥ��Զ�����Գ������Ķ�����������������߾ͳ�ƽ�����ˡ�
LONG
        );
        set("exits", ([ 
          "south" : __DIR__"cj3",
          "north" : __DIR__"gate2",
]));
        set("outdoors", "ƽ����");
        setup();
}

