// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������������ľ����������ǡ�һ���³�������ãã��Ұ֮�ϡ��˳ǽ���
��������䣬���Ŵ󽫾���ȥ�����ڴ��������꣬��һ��ƽ����������������
�������ﶼ�о��ӳ�פ��
LONG );
	set("exits", ([
		"northwest"   : __DIR__"xjqiao",
//		"east"    : __DIR__"huanghe_3",
		"west"    : __DIR__"kedian",
		"east" : __DIR__"road4",
        ]));
        set("objects", ([
		__DIR__"npc/wujiang1" : 1,
		__DIR__"npc/bing1" : 2,
	]));
	set("outdoors", "����");
	setup();
}

