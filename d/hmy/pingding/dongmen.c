// gate1.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ƽ���ݵĶ����ţ�����������ƽ���ݳ����ˣ�һ������ֱͨ������
������һ��ͨ������ĸɵ���
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"cj5",
		"east" : __DIR__"road6",
	]));
        set("outdoors", "ƽ����");
        setup();
}
