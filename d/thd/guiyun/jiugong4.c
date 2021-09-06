// Room: /u/jpei/guiyun/jiugong4.c

#include <ansi.h>

inherit ROOM;

#define HERENO	4

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "æ≈π¨Ã“ª®’Û");
	set("outdoors","πÈ‘∆◊Ø");

	set("exits", ([
		"east" : __DIR__"jiugong5",
		"north" : __DIR__"jiugong1",
		"south" : __DIR__"jiugong7",
	]));
	setup();
}

#include "jiugong.c"