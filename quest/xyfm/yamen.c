// Room: /city/yamen.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ƾɴ���");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"ymzhengting",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }
