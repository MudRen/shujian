// Room: /city/chaguan.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "����¥");
	set("long", @LONG
������ȡ�����߽�֮�⣬��Ϊ�����ڹ���֮�⣬�ǹ������Ԭ������
�����ڴ˵�Ѳ�鿱̽���顣
LONG
	);
	
	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }