// Room: /city/biaoju.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ķ�");
	set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"south" : __DIR__"zhengting",
		"north" : __DIR__"xidajie2",
	]));

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }