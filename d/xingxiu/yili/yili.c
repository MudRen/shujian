// Room: /d/xingxiu/yili.c
// Modify by Lklv 2001.10.16

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "��Զ");
	set("long", @LONG
���磬������Զ����ͨ��˹���ϵ����ã��������ء�������������������
ͨ��Ҫ�壬��˿��֮·����Ҫ����վ֮һ�������λ�ڱ�����ɽѩˮ�㼯����
��������Ա���
LONG);
	set("outdoors", "����");

	set("exits", ([
		"west" : "/d/xingxiu/shanjiao",
		"northwest" : "/d/xingxiu/xxh",
		"north" : __DIR__"yilihe",
		"south" : "/d/xingxiu/silk10",
	]));

	set("objects", ([
		__DIR__"../npc/shangren" : 1,
        ]));
	setup();
}

#include "/d/xingxiu/job2.h";
