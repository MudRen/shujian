// automake group room , Sun Jul 24 10:37:22 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","����");
set("long","����һ���ոս���ã���û�з�ˢ�ķ��ݡ�
");
set("exits",([
"down":"/d/group/entry/cdtulu2.c","north":__DIR__"1311475042.c",
]));
set("objects",([
"/d/group/obj/biaozhi.c":1,"/d/group/obj/door.c":1,"/d/group/obj/qiangui.c":1,
]));
set("indoors","[1;36m�����[0;0m");
set("group1","fengyun");
set("group2","[1;36m�����[0;0m");
setup();
setup_var();
}
