// Write By actiong@SJ 2009.1.6
// Room: /d/changan/zhulin2.c
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ǽ��⣬�ô��һƬ����ԣ�ӭ��ҡҷ��������Ȼ����
������������������϶�����ȴ���������ڸ��٣���������һƬ������
�������������������Ȼ���������硣
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"northwest" : __DIR__"zhulin1",
  		"east" : __DIR__"zhulin3",
	]));
	
		set("objects", ([
		"d/hmy/npc/xiang" : 1,
		"d/hmy/npc/qu" : 1,
	]));

	set("coor/x", -140);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
