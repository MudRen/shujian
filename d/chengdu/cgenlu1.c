// Room: /d/chengdu/chenggenlu1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����������ϣ������Ǳ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"cgenlu2",
		"west" : __DIR__"beidajie4",
	]));
	set("incity",1);
	setup();
}
