// Room: /dali/xijie2.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�������֣�������հ���������½֣��ֽй����֡��ǰ�������ó
�йŽ֡�ÿ�����£����Ｗ���˽��׵���Ⱥ������������¥����ʱ��������
���������в����������ߵĲ÷������ѡ�·���
LONG
	);
	set("outdoors", "����");
	set("exits", ([ 
		"east" : __DIR__"fengwei",
		"west" : __DIR__"caifeng",
		"north" : __DIR__"beijie1",
		"south" : __DIR__"xijie2",
	]));
	set("objects", ([
		__DIR__"npc/haoke" : 1,
	]));
	set("incity", 1);
	setup();
}
