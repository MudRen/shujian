// automake group room , Wed Aug  3 20:43:20 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","���");
set("long","һ����ֱ��ʯ����ͨ��ǰ����·�ϲ�ʱ�������������ĳ�����������
�����ֳָ��ֱ�������������ϰ��֮�ˣ�����μ����Ի�ү���������ӣ�����
�����������ִ�ͳ�����ϰ��֮�����ʢ�С�
");
set("exits",([
"south":"/d/dali/dadao3","north":"/d/dali/dadao1","northwest":"/d/group/SHTM/1312375400.c",
]));
set("outdoors","����Ǳ�");
set("group",1);
setup();
}
