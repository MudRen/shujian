// Write By actiong@SJ 2009.1.6
// Room: /d/changan/zhulin1.c
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
  		"southeast" : __DIR__"zhulin2",
  		"northeast" : __DIR__"suishi1",
	]));
	set("objects", ([
		"d/hmy/npc/lu" : 1,
	]));

	set("coor/x", -140);
	set("coor/y", -20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
