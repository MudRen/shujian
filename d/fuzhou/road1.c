// Room: /d/fuzhou/road1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻�����
��������븣������ɽ�����������ֱ�������ǡ�
LONG
	);

	set("exits", ([
                "northeast" : "/d/ningbo/ttcsi",
                "southwest" : __DIR__"road2",
	]));

	set("outdoors", "����");
	setup();
}

