// Room: /d/chengdu/xidajie2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣������������ͨ����⡣��
���Եúܷ�æ��
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"xidajie1",
		"west" : __DIR__"daximen",
		"north" : __DIR__"guandm",
	]));

	set("incity",1);
	setup();
}

