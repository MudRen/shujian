// automake group room , Fri Jul 29 21:16:11 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","Ê¯Â·");
set("long","ÕâÊÇÒ»Ìõ¸Õ¸Õ½¨ÔìºÃ£¬»¹Ã»ÓĞ·ÛË¢µÄÊ¯Â·¡£
");
set("exits",([
"east":__DIR__"1311945302.c",
]));
set("outdoors","[1;31mÈÕ[1;34mÔÂ[1;37mÉñ½Ì[0;0m");
set("group1","rysj");
set("group2","[1;31mÈÕ[1;34mÔÂ[1;37mÉñ½Ì[0;0m");
setup();
setup_var();
}
