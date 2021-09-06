// Room: /u/jpei/guiyun/jiugong8.c

#include <ansi.h>

inherit ROOM;

#define HERENO	8

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "�Ź��һ���");
	set("outdoors","����ׯ");

	set("exits", ([
		"east" : __DIR__"jiugong9",
		"west" : __DIR__"jiugong7",
		"north" : __DIR__"jiugong5",
	]));
	setup();
}

#include "jiugong.c"