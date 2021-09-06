// Write By actiong@SJ 2009.1.6
// Room: /d/changan/zhulin1.c
inherit ROOM;

void create()
{
	set("short", "绿竹林");
	set("long", @LONG
这里是洛阳东城郊外，好大的一片绿竹丛，迎风摇曳，雅致天然。你
刚来到这里，便听得琴韵丁冬，却是有人正在抚琴，绿竹林中一片清凉宁
静，和外面的洛阳城宛然是两个世界。
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
