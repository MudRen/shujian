// Room: /d/shaolin/xiaolu5.c
// Date: YZC 96/01/19
// by bren

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ��
����΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ��ѵ�������
�ڡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaolu6",
		"east" : __DIR__"sblu-2",
	]));

	set("outdoors", "shaolin");
	setup();
}



