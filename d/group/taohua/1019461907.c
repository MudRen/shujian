// automake group room , Mon Apr 22 17:21:35 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[1;36mСϪ[0;0m");
set("long","�������꽼���һ��СϪ��
�峺���ף����Կ��������ˮ��������ȥ�� 
[0;0m");
set("exits",([
"east":__DIR__"1019462149.c","southwest":__DIR__"1019053619.c","south":__DIR__"1019462562.c","north":__DIR__"1019462035.c","west":__DIR__"1019467295.c",
]));
set("outdoors","[1;35m�һ�Դ[0;0m");
set("group1","taohua");
set("group2","[1;35m�һ�Դ[0;0m");
setup();
setup_var();
}
