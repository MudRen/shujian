// Room: /d/nanyang/xiaolu.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��Ƨ����С·��������ï�ܵĴ��֡�·����ϡ�ɼ������߹����µ�
�ۼ���ż���м���������ɫ�ҴҴ�����߾����������ߵ���Ҽ���ȥ�����淽
���������ǡ�
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"qslu",
		"west" : __DIR__"yidao2",
	]));
	setup();
}
