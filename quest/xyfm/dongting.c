// Room: /city/dongting.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "��ս��");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"west" : __DIR__"ymzhengting",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }
