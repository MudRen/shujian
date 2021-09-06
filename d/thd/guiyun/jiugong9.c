// Room: /u/jpei/guiyun/jiugong9.c

#include <ansi.h>

inherit ROOM;

#define HERENO	9

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "�Ź��һ���");
	set("outdoors","����ׯ");

	set("exits", ([
		"west" : __DIR__"jiugong8",
		"north" : __DIR__"jiugong6",
	]));
	setup();
}

#include "jiugong.c"