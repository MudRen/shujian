// automake group room , Tue Jul 23 00:20:30 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[0;36mø™–ƒ√ø“ªÃÏ[0;0m");
set("long","[1;31m GOLD GOLD CASH CASH 
[1;31m GOLD GOLD CASH CASH 
[1;31m GOLD GOLD CASH CASH 
[1;31m GOLD GOLD CASH CASH 
[1;31m GOLD GOLD CASH CASH 
[1;31m GOLD GOLD CASH CASH 
[1;31m GOLD GOLD CASH CASH 
");
set("exits",([
"north":"/d/group/entry/xsxiao2.c","southeast":__DIR__"1027350351.c",
]));
set("objects",([
"/d/group/obj/biaozhi.c":1,"/d/group/obj/door.c":1,
]));
set("indoors","[0;35m»Àº‰[0;36mÃÏÃ√[0;0m");
set("group1","tiantang");
set("group2","[0;35m»Àº‰[0;36mÃÏÃ√[0;0m");
setup();
setup_var();
}
