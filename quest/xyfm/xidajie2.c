// Room: /city/xidajie2.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "С·");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"xidajie1",
		"south" : __DIR__"biaoju",
		"west" : __DIR__"ximen",
		"north" : __DIR__"caizhu",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }