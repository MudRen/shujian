// Room: /d/chengdu/chenggenlu5.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����������������ϱ��Ƕ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"cgenlu4",
		"south" : __DIR__"ddajie4",
	]));
	set("incity",1);
	setup();
}
