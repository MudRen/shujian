// xiaodao4.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ���������ּ�С�����Ӷ���һֱͨ�����ߣ�һ����ȥ��������·
�ľ�ͷ�����԰ٻ����ޡ���������������
LONG );
	set("exits", ([
    "northeast" : "/d/hj/senlin",
		"west" : __DIR__"qingcaop",
		"north" : __DIR__"liangong",
		"south" : __DIR__"mubanlu",
	]));
 	set("objects", ([
		__DIR__"npc/mengmianr": 2,
	]));
	set("outdoors", "xiaoyao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
