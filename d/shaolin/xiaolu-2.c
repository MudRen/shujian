// xiaolu-2.c
// by zqb

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ����ʯ�̳ɵ�С·�ϣ������������ɽ�������������мд�
�������ķ��㣬���������
LONG
	);
        set("outdoors", "shaolin");

	set("exits", ([
		"south" : __DIR__"xiaolu-3",
		"northwest" : __DIR__"xiaolu-1",
	]));
	set("coor/x",100);
  set("coor/y",210);
   set("coor/z",110);
   setup();
}

