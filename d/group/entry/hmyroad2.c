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
		"southwest" : "/d/hmy/pingding/road1",
		"eastup" : "/d/hmy/pingding/road3",
	]));
	set("group", 1);
	set("outdoors", "ƽ����");
	setup();
}
