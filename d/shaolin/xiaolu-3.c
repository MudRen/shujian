// xiaolu-3.c
// by zqb

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ����ʯ�̳ɵ�С·�ϣ������������ɽ�������������мд�
�������ķ��㣬���������������һƬ�ܴ�Ĳ�԰�ӡ�
LONG
	);
        set("outdoors", "shaolin");

	set("exits", ([
		"south" : __DIR__"cyzi-1",
		"north" : __DIR__"xiaolu-2",
	]));
	set("coor/x",100);
  set("coor/y",200);
   set("coor/z",110);
   setup();
}

