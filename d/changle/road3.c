// automake group room , Sat May 21 12:59:36 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","�����");
set("long","������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
������������������ǳ����֡���ʱ����������������߷ɳ۶���������
һ·���������ϵ��˸������ž�װ���¼��������еĻ���������ŵ���������
����Щϰ��Ľ����ˡ���·��������������������֡�
");
set("exits",([
"north":"/cmds/leitai/bwdh/zongtai",
"southwest":__DIR__"road1",
]));
set("outdoors","���ְ�");
set("group",1);
setup();
}
