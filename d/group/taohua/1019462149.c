// automake group room , Mon Apr 22 16:42:16 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[1;35m�һ���[0;0m");
set("long","һ��Ƭ�һ��֡��а����ٲ�������������������������Ӣ�ͷס����
Ȼ����һ������������ԼԼ�п����ּ����߽�ϸ����ֻ���Ȼ��Ծ�������
����������ָ����ȥ�ģ���
                     ���أ�Action������һ��
[0;0m");
set("exits",([
"west":__DIR__"1019461907.c",
]));
set("outdoors","[1;35m�һ�Դ[0;0m");
set("group1","taohua");
set("group2","[1;35m�һ�Դ[0;0m");
setup();
setup_var();
}
