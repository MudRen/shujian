// Room: /d/chengdu/chenggenlu4.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·���ϱ߲�Զ�����Ƕ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"northwest" : __DIR__"cgenlu3",
		"south" : __DIR__"cgenlu5",
	]));
	set("incity",1);
	setup();
}
