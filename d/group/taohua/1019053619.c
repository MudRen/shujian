// automake group room , Sun May 26 22:40:20 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[0;32m����[0;0m");
set("long","������ɽ��λ�ڴ������磬�����վ����鲼��塢���¡�Ͽ�ȡ���Ѩ��
��̫Ԫ�У�������ż���һ�Դ�ڴˣ�̫�عιο���ǲ����������Ѱ��
��־�����ԣ�������·���䵱����������ʿҲ����֮����Ȼ������
ĩ����Ѱ���ա��������ʽ��ߡ�
[0;0m");
set("exits",([
"up":__DIR__"1019055624.c","northeast":__DIR__"1019461907.c","south":"/d/group/entry/yzeroad1.c",
]));
set("objects",([
"/d/group/obj/biaozhi.c":1,"/d/group/obj/door.c":1,
]));
set("indoors","[1;35m�һ�Դ[0;0m");
set("group1","taohua");
set("group2","[1;35m�һ�Դ[0;0m");
setup();
setup_var();
}
