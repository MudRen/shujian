// automake group room , Mon Apr 22 16:55:03 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[1;35m�һ���[0;0m");
set("long","    һ��Ƭ�һ��֡��а����ٲ�������������������������Ӣ�ͷס����
Ȼ����һ������������ԼԼ�п����ּ����߽�ϸ����ֻ���Ȼ��ּ�����б
бû���·���ܣ�Ȼ���������������Ǹ������д����
                     [0;33m���󡣨Biaofeng������һ��
[0;0m");
set("exits",([
"south":__DIR__"1019461907.c",
]));
set("outdoors","[1;35m�һ�Դ[0;0m");
set("group1","taohua");
set("group2","[1;35m�һ�Դ[0;0m");
setup();
setup_var();
}
