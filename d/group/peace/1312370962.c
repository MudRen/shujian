// automake group room , Wed Aug  3 19:35:32 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","·¿¼ä");
set("long","ÕâÊÇÒ»×ù¸Õ¸Õ½¨ÔìºÃ£¬»¹Ã»ÓÐ·ÛË¢µÄ·¿ÎÝ¡£
");
set("exits",([
"southeast":"/d/group/entry/dlstulin.c","northwest":__DIR__"1312371061.c",
]));
set("objects",([
"/d/group/obj/door.c":1,
]));
set("indoors","[1;36mºÍÆ½[1;37m·¹µê[0;0m");
set("group1","peace");
set("group2","[1;36mºÍÆ½[1;37m·¹µê[0;0m");
setup();
setup_var();
}
