// automake group room , Mon Jun 17 07:44:07 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","·¿¼ä");
set("long","ÕâÊÇÒ»×ù¸Õ¸Õ½¨ÔìºÃ£¬»¹Ã»ÓĞ·ÛË¢µÄ·¿Îİ¡£
");
set("exits",([
"north":__DIR__"1019461907.c",
]));
set("indoors","[1;35mÌÒ»¨Ô´[0;0m");
set("group1","taohua");
set("group2","[1;35mÌÒ»¨Ô´[0;0m");
setup();
setup_var();
}
