// Room: /city/neizain.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "��լ");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"south" : __DIR__"ymzhengting",
	]));

	setup();
}

//�Ǿ���
int is_mirror() { return 1; }