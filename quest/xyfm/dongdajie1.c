// Room: /city/dongdajie1.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ķϳ�ǽ");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"zahuopu",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"shuyuan",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }