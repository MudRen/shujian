// Room: /d/xiangyang/xiaolu1.c
// Lklv Modify 2001.9.22

inherit ROOM;
void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С·�ϣ�ż��������������ҴҶ������������ĳ���������
��ͨ�������ǣ�����ͨ���Ĵ���
LONG
	);
        set("outdoors", "����");
        set("xyjob", 1);
	set("objects", ([
		__DIR__"npc/mengmian-dadao" : 1,
	]) );
	set("exits", ([
		"northeast" : __DIR__"tanxi",
		"north" : __DIR__"lzz/xiaolu",
		"southwest" : __DIR__"xiaolu2",
	]));

	setup();
}
