// Write By actiong@SJ 2009.1.6
// Room: /d/changan/zhulin3.c
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
  		"west" : __DIR__"zhulin2",
  		"enter" : __DIR__"xiaoshe",
	]));

	set("coor/x", -130);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
