// Room: /d/chengdu/chenggenlu2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����߲�Զ�����Ǳ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"west" : __DIR__"cgenlu1",
		"southeast" : __DIR__"cgenlu3",
	]));
	set("incity",1);
	setup();
}
