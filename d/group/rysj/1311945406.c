// automake group room , Fri Jul 29 21:50:40 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","����[0;0m");
set("long","���������������
���������������Ĵ���ս�����ı��
[0;0m");
set("exits",([
"west":__DIR__"1311945302.c",
]));
set("objects",([
"/d/group/obj/qiangui.c":1,
]));
set("indoors","[1;31m��[1;34m��[1;37m���[0;0m");
set("group1","rysj");
set("group2","[1;31m��[1;34m��[1;37m���[0;0m");
setup();
setup_var();
}
