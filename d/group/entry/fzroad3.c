// Room: /d/fuzhou/road3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻�����
������븣������ɽ����
LONG
	);
	set("group", 1);
	set("exits", ([
                "northeast" : "/d/fuzhou/road2",
                "south" : "/d/fuzhou/road4",
	]));

	set("outdoors", "���ݳ�");
	setup();
}
