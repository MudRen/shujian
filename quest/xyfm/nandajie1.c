// Room: /city/nandajie1.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "Ұ��");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		"west" : __DIR__"duchang",
		"north" : __DIR__"guangchang",
	]));

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }