// automake group room , Sun May 26 14:38:23 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","����");
set("long","����һ���ոս���ã���û�з�ˢ�ķ��ݡ�
");
set("exits",([
"down":__DIR__"1019053619.c",
]));
set("objects",([
"/d/group/obj/qiangui.c":1,
]));
set("indoors","[1;35m�һ�Դ[0;0m");
set("group1","taohua");
set("group2","[1;35m�һ�Դ[0;0m");
setup();
setup_var();
}
