// road3.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ��ȥ��ľ�µıؾ�֮·��·�ϻ�ɳ��������Ŭ����������ȥ������
��һ��С�ǣ��Ǿ���������̹�Ͻ��ƽ�����ˡ�
LONG
        );
	set("exits", ([ 
		"west" : __DIR__"dongmen",
		"eastup" : __DIR__"road7",
	]));
        set("outdoors", "ƽ����");
        setup();
}

