// Room: /d/meizhuang/road1.c
// By Jpei
// Update by Lklv 2001.10.9

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�������ϱߵ�С·��ǰ�治Զ����һ��Ƭ÷�֣�������ȥ����ض�
��÷�����ϸɺ�б��֦Ҷï�ܣ��������÷��ʢ��֮�գ���ѩ�纣����Ȼ����
������
LONG
	);
	set("outdoors","����");

	set("exits", ([
		"south" : __DIR__"road2",
		"west" : __DIR__"shiji",
	]));
	setup();
}
