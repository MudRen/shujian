// Room: /city/caizhu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�Ĳݵ�");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" : __DIR__"dayuan",
	]));

	setup();

}
//�Ǿ���
int is_mirror() { return 1; }