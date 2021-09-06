// Room: /city/shuyuan.c 
inherit ROOM;

void create()
{
	set("short", "Î×Ê¦µñÏñ³ÂÁÐÊÒ");
	set("long", @LONG

LONG
	);

	set("exits", ([
		"down" : __DIR__"shuyuan",
	]));

	
	set("objects", ([
        __DIR__"obj/bbb" : 1,
        __DIR__"obj/yuj" : 1,
	]));

	set("coor/x",110);
  set("coor/y",0);
   set("coor/z",10);
   set("incity",1);
	setup();
}
