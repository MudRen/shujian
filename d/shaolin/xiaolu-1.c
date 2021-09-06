// xiaolu-1.c
// by zqb

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条碎石铺成的小路上，两侧青草茵茵，山花烂漫。空气中夹带
着泥土的芳香，扑面而来。
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

