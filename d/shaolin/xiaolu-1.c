// xiaolu-1.c
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
		"southeast" : __DIR__"xiaolu-2",
		"north" : __DIR__"chufang2",
	]));
	set("coor/x",90);
  set("coor/y",220);
   set("coor/z",110);
   setup();
}

