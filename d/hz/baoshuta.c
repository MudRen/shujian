// /u/beyond/hz/baoshuta.c ������
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIY"������"NOR);
        set("long", @LONG
���ϵ�ɽ�������Ǳ������ˣ����������޳�������ͦ�Σ�������������
����ء��������������⣬�и߲�����֮�У���ɽ��Զ����ͤͤ����������
���硣�����о�����˵�����������������׷������ģ����������ˡ���
LONG
        );
set("objects",([
__DIR__"npc/you1" : 2,
]));
    set("outdoors", "����");
        set("exits", ([
            "southdown" : __DIR__"qsddao1",
            "northdown" : __DIR__"shanlu",
]));
        set("coor/x",60);
  set("coor/y",-310);
   set("coor/z",0);
   setup();
}
