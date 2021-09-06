// automake group room , Fri Jul  5 12:16:24 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","Ê¯Â·");
set("long","ÕâÊÇÒ»Ìõ¸Õ¸Õ½¨ÔìºÃ£¬»¹Ã»ÓĞ·ÛË¢µÄÊ¯Â·¡£
");
set("exits",([
"up":__DIR__"1019467371.c",
]));
set("outdoors","[1;35mÌÒ»¨Ô´[0;0m");
set("group1","taohua");
set("group2","[1;35mÌÒ»¨Ô´[0;0m");
setup();
setup_var();
}
