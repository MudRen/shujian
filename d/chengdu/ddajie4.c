// Room: /d/chengdu/dongdajie4.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����Ƕ�����ͨ����⡣��
���Եúܷ�æ���������ų�ǽ������·��
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"cgenlu5",
		"west" : __DIR__"ddajie3",
		"east" : __DIR__"dadongmen",
	]));
	set("incity",1);
	setup();
}
