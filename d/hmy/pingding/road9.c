// road2.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��ȥ��ľ�µıؾ�֮·��·�ϲ��������������������������ɳ��
�����Ѽ���ָ��
LONG
	);
	set("exits", ([ 
		"northwest" : "/d/group/entry/hmyroad8",
		"east" : "/d/cangzhou/sancakou",
	]));
	set("outdoors", "ƽ����");
	setup();
}
