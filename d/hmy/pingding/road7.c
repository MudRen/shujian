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
		"westdown" : __DIR__"road6",
		"east" : "/d/group/entry/hmyroad8",
	]));

	set("objects",([
		__DIR__"npc/jiaozhong" : 1,
	]));

        set("outdoors", "ƽ����");
        setup();
}
