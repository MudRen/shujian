// automake group room , Wed Aug  3 19:35:32 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","����");
set("long","����һ���ոս���ã���û�з�ˢ�ķ��ݡ�
");
set("exits",([
"southeast":"/d/group/entry/dlstulin.c","northwest":__DIR__"1312371061.c",
]));
set("objects",([
"/d/group/obj/door.c":1,
]));
set("indoors","[1;36m��ƽ[1;37m����[0;0m");
set("group1","peace");
set("group2","[1;36m��ƽ[1;37m����[0;0m");
setup();
setup_var();
}
