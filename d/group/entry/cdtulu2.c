// automake group room , Sun Jul 24 09:59:14 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","��·");
set("long","����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է�����ȥ��
���ܵ��������������ࡣ
");
set("exits",([
"southwest":"/d/chengdu/tulu1","northeast":"/d/chengdu/tulu3","up":"/d/group/fengyun/1311472754.c",
]));
set("outdoors","����ɽ");
set("group",1);
setup();
}
