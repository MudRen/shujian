// Room: /city/beidajie1.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "��Ұ");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west" : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }