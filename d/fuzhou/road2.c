// Room: /d/fuzhou/road2.c

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
                "northeast" : __DIR__"road1",
		"southwest" : "/d/group/entry/fzroad3",
                "southeast" : "/d/putian/road01",
	]));

	set("objects",([
		__DIR__"npc/tangzi" : 1,
	]));

	set("outdoors", "����");
	setup();
}
