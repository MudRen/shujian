// Room: /city/dongdajie2.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ķϳ�ǽ");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"dongmen",
		"south" : __DIR__"datiepu",
		"west" : __DIR__"dongdajie1",
		"north" : __DIR__"yaopu",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }