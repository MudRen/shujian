// Room: /u/jpei/guiyun/jiugong6.c

#include <ansi.h>

inherit ROOM;

#define HERENO	6

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "�Ź��һ���");
	set("outdoors","����ׯ");

	set("exits", ([
		"west" : __DIR__"jiugong5",
		"north" : __DIR__"jiugong3",
		"south" : __DIR__"jiugong9",
	]));
	setup();
}

#include "jiugong.c"