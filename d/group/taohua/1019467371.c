// automake group room , Wed Jul 10 14:36:50 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","ʯ·");
set("long","����һ���ոս���ã���û�з�ˢ��ʯ·��
");
set("exits",([
"east":__DIR__"1019467295.c","down":__DIR__"1025842584.c",
]));
set("objects",([
__DIR__"npc/1025050720.c":1,__DIR__"npc/1026282922.c":1,
]));
set("outdoors","[1;35m�һ�Դ[0;0m");
set("group1","taohua");
set("group2","[1;35m�һ�Դ[0;0m");
setup();
setup_var();
}
