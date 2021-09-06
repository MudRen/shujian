// Room: /u/jpei/guiyun/jiugong5.c

#include <ansi.h>

inherit ROOM;

#define HERENO	5

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "�Ź��һ���");
	set("outdoors","����ׯ");

	set("exits", ([
		"east" : __DIR__"jiugong6",
		"west" : __DIR__"jiugong4",
		"north" : __DIR__"jiugong2",
		"south" : __DIR__"jiugong8",
	]));
	setup();
}

#include "jiugong.c"