// automake group room , Wed Aug  3 19:37:54 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","��Դ����[0;0m");
set("long"," [1;31m��Դ������!
[0;0m");
set("exits",([
"south":__DIR__"1312371061.c",
]));
set("objects",([
"/d/group/obj/qiangui.c":1,
]));
set("indoors","[1;36m��ƽ[1;37m����[0;0m");
set("group1","peace");
set("group2","[1;36m��ƽ[1;37m����[0;0m");
setup();
setup_var();
}
