// road1.c
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
		"west" : "/d/changan/northroad10",
		"northeast" : "/d/group/entry/hmyroad2",
	]));
        set("outdoors", "ƽ����");
        setup();
}
