// Room: /u/jpei/thd/bay.c

inherit ROOM;

void create()
{
	set("short", "С���");
	set("long", @LONG
�����Ǻ��ߵ�һ��С��ۣ�����Ψһ���Գ����ĵط����������ˡ���Ҫ��
��������æµ������������һ�����ϴ�������������ƴ���������ڴ������﹤
����Һ��ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/laoda.c":1,
	]));
	set("outdoors","�һ���");

	set("exits", ([
		"west": __DIR__"hbroad.c",
	]) );

	setup();
}
