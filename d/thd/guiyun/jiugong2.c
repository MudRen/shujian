// Room: /u/jpei/guiyun/jiugong2.c

#include <ansi.h>

inherit ROOM;

#define HERENO	2

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "�Ź��һ���");
	set("outdoors","����ׯ");

	set("exits", ([
		"west" : __DIR__"jiugong1",
		"east" : __DIR__"jiugong3",
		"south" : __DIR__"jiugong5",
	]));
	setup();
}

#include "jiugong.c"