// automake group room , Fri Jul 29 21:50:40 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","ÃÜÊÒ[0;0m");
set("long","ÕâÊÇÈÕÔÂÉñ½ÌÃÜÊÒ
ÀïÃæ·Å×ÅÈÕÔÂÉñ½ÌËÄ´¦Õ÷Õ½ÇÀÀ´µÄ±¦Îï¡£
[0;0m");
set("exits",([
"west":__DIR__"1311945302.c",
]));
set("objects",([
"/d/group/obj/qiangui.c":1,
]));
set("indoors","[1;31mÈÕ[1;34mÔÂ[1;37mÉñ½Ì[0;0m");
set("group1","rysj");
set("group2","[1;31mÈÕ[1;34mÔÂ[1;37mÉñ½Ì[0;0m");
setup();
setup_var();
}
