// Room: /city/kedian3.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "��¥��");
	set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"out" : __DIR__"zuixianlou2",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }