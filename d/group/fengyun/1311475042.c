// automake group room , Sun Jul 24 21:07:04 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","·¿¼ä");
set("long","ÕâÊÇÒ»×ù¸Õ¸Õ½¨ÔìºÃ£¬»¹Ã»ÓĞ·ÛË¢µÄ·¿Îİ¡£
");
set("exits",([
"south":__DIR__"1311472754.c",
]));
set("objects",([
"/d/group/obj/qiangui.c":1,
]));
set("indoors","[1;36mºÚÉç»á[0;0m");
set("group1","fengyun");
set("group2","[1;36mºÚÉç»á[0;0m");
setup();
setup_var();
}
