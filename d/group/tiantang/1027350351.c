// automake group room , Tue Jul 23 00:23:40 2002
inherit ROOM;
#include <ansi.h>
#include "/d/group/gate.h"
void create()
{
set("short","[1;33m�����[0;0m");
set("long","[1;36mһ��ʮ���׸ߵ�[0;33m������(Tie men)[1;36m������������ǰ,������
һ�����صķ�ӡ,���ַ�ӡֻ�������������ܴ򿪡���ǽ���и�ħ�����Ĺ�
��,�ڹ������ҫ��,ֻ��������һ���������򳡴�С��ʯ��,��������˸�
�ָ����������챦,��������κ�һ����������ֵ���ǡ�
[0;0m");
set("exits",([
"northwest":__DIR__"1027350275.c",
]));
set("objects",([
"/d/group/obj/qiangui.c":1,__DIR__"npc/1027354920.c":1,
]));
set("indoors","[0;35m�˼�[0;36m����[0;0m");
set("group1","tiantang");
set("group2","[0;35m�˼�[0;36m����[0;0m");
setup();
setup_var();
}
