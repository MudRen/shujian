// Room: /d/fuzhou/road4.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻�����
������븣������ɽ����
LONG
	);

	set("exits", ([
                "north" : "/d/group/entry/fzroad3",
		"south" : __DIR__"road5",
	]));

	set("outdoors", "����");
	setup();
}

