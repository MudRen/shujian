// automake group room , Fri Jul 29 21:16:11 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","ʯ·");
set("long","����һ���ոս���ã���û�з�ˢ��ʯ·��
");
set("exits",([
"east":__DIR__"1311945302.c",
]));
set("outdoors","[1;31m��[1;34m��[1;37m���[0;0m");
set("group1","rysj");
set("group2","[1;31m��[1;34m��[1;37m���[0;0m");
setup();
setup_var();
}
