// Room: /u/jpei/thd/njeast.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��С����Ķ���ڡ����Ӻ�С��������һƬ�ž��С��ϱ���Լ����
����һ���󽭡�����������ͨ�򺣱ߵ�С·��
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","ţ�Ҵ�");

	set("exits", ([
		"west": __DIR__"njroad3.c",
		"northeast": __DIR__"hbroad.c",
	]) );
	set("objects", ([
	"/clone/npc/kid" : 1,
	]) );

	setup();
}

