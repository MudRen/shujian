// /d/xiangyang/shanxiroad2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�ϣ�ż��������������ҴҶ�������ó������������
���������ؽ磬�����Ͻ���������ڡ�������˿���·���������������ĳ���
���������������ǻ�ɽ���µ�һ��С���䡣
LONG
	);
        set("outdoors", "����");

	set("objects", ([
		__DIR__"npc/duxing-daxia" : 1,
	]) );
	set("exits", ([
		"northwest" : __DIR__"lantian",
		"southeast" : __DIR__"shanxiroad1",
		"north" : "/d/village/hsroad3",
	]));

	setup();
}

