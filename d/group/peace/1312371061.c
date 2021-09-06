// automake group room , Wed Aug  3 19:39:32 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","ºÍÎª¹ó[0;0m");
set("long"," [1;37mºÍÎª¹ó,[1;37mµ«ÊÇÃ»ÓÐ¾ø¶ÔºÍÆ½£¡
¡£
[0;0m");
set("exits",([
"southeast":__DIR__"1312370962.c","north":__DIR__"1312371093.c",
]));
set("objects",([
"/d/group/obj/biaozhi.c":1,
]));
set("indoors","[1;36mºÍÆ½[1;37m·¹µê[0;0m");
set("group1","peace");
set("group2","[1;36mºÍÆ½[1;37m·¹µê[0;0m");
setup();
setup_var();
}
