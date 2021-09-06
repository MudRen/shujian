#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIG"����"NOR);
	set("long",
"������һ�����ҡ�\n"
);
	set("exits",([
		"up" : __DIR__"mishi",
	]));
	set("objects", ([
		__DIR__"../obj/mrkey1" : 1,
		__DIR__"../obj/mrkey" : 1,
	]));

	setup(); 
}

void init()
{
	this_player()->delete_temp("left/tou");
	this_player()->delete_temp("right/tou");
	this_player()->delete_temp("mark/sit");
}
