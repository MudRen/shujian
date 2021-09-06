// automake group room , Fri Jul 29 21:15:29 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","Ê¯Â·");
set("long","ÕâÊÇÒ»Ìõ¸Õ¸Õ½¨ÔìºÃ£¬»¹Ã»ÓĞ·ÛË¢µÄÊ¯Â·¡£
");
set("exits",([
"south":"/d/group/entry/xstulu2.c","north":__DIR__"1311945302.c","east":__DIR__"1311945143.c","west":__DIR__"1311945329.c",
]));
set("objects",([
"/d/group/obj/door.c":1,
]));
set("outdoors","[1;31mÈÕ[1;34mÔÂ[1;37mÉñ½Ì[0;0m");
set("group1","rysj");
set("group2","[1;31mÈÕ[1;34mÔÂ[1;37mÉñ½Ì[0;0m");
setup();
setup_var();
}
