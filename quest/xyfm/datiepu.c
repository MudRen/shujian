// Room: /city/datiepu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "��ɽɽ��");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }