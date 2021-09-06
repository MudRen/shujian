// automake group room , Wed Aug  3 20:50:17 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","·¿¼ä");
set("long","ÕâÊÇÒ»×ù¸Õ¸Õ½¨ÔìºÃ£¬»¹Ã»ÓĞ·ÛË¢µÄ·¿Îİ¡£
");
set("exits",([
"down":__DIR__"1312375400.c",
]));
set("objects",([
"/d/group/obj/qiangui.c":1,
]));
set("indoors","[1;32mËÄº£Í¬ÃË[0;0m");
set("group1","SHTM");
set("group2","[1;32mËÄº£Í¬ÃË[0;0m");
setup();
setup_var();
}
