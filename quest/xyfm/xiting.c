// Room: /city/xiting.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	
	set("exits", ([
		"east" : __DIR__"ymzhengting",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }