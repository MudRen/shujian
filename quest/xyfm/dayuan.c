// Room: /city/dayuan.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "������Ժ");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"caizhu",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }