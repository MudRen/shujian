// nanlin.c 南林 越女阿青之住处
// By Jpei

inherit ROOM;

void create()
{
        set("short", "南林");
        set("long",@long
出了铁岭关，你不禁眼前一亮。满眼俱是郁郁葱葱的翠绿竹林。期间飞鸟回翔，
苍猿攀援，竹浪如涛。你信步走入竹林，只觉清幽深邃，心旷神怡。
long);
	set("outdoors", "suzhou");

	set("exits",([
                "south" : __DIR__"tielingguan",
	]));

	set("objects", ([
                __DIR__"npc/aqing" : 1,
	]));

	set("coor/x",50);
  set("coor/y",-250);
   set("coor/z",0);
   setup();
}
