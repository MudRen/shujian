// Room: /d/plummanor/road1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ�������ϱߵ�С·��ǰ�治Զ����һ��Ƭ÷�֣���֪ͨ��δ���
LONG
	);
	set("outdoors","÷ׯ");

	set("exits", ([
		"south" : __DIR__"road2",
		"west" : __DIR__"shiji",
	]));
	setup();
}

