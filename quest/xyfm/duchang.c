// Room: /city/duchang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "Ұ��");
	set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"up" : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
		"west" : __DIR__"duchang3",
               "north" : __DIR__"duchang4",
	]));

	setup();
}

//�Ǿ���
int is_mirror() { return 1; }