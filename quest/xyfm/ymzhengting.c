// Room: /city/ymdongting.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ư�����");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"east" : __DIR__"dongting",
		"west" : __DIR__"xiting",
		"north" : __DIR__"neizhai",
		"south" : __DIR__"yamen",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }