//zhulin3.c
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ��Ƭ���ܵ����֣������дУ�һ����������ͷ��΢�紵������Ҷ��
���˳���Ϊ֮һ�ӣ�����������������ȥ���ߣ���Ҫ�ҵ�������·����������
������ֻ���û���ҵ�������·��
LONG
	);
	set("outdoors","���");
	set("exits", ([
		"north" : __DIR__"zhulin4",
		"east"  : __FILE__,
		"west"  : __FILE__,
		"south" : __FILE__,
	]));

	set("objects", ([
		"/d/wuguan/npc/snake" : 1,
	]));

	setup();
}
