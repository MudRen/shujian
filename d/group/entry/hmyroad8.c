// road2.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ��ȥ��ľ�µıؾ�֮·��·�ϲ����������������������������ɳ��
�����Ѽ���ָ��
LONG
        );
	set("exits", ([ 
		"west" : "/d/hmy/pingding/road7",
		"southeast" : "/d/hmy/pingding/road9",
	]));
	set("group", 1);
        set("outdoors", "ƽ����");
        setup();
}