// /u/beyond/hz/shuichi.c ˮ��
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"ˮ��"NOR);
        set("long", @LONG
��ɽ�������ʯ��һ��Ȫˮ����������ӿ�������γɶ༶�ٲ���ע����
�ء���������ɽʯ�Ϸֱ���š�ˮ����������������顱����������һ��
԰��С����
LONG
        );
set("objects",([
__DIR__"npc/you" : 2,
]));
        set("exits", ([
            "northwest" : __DIR__"huanglong",
            "west" : __DIR__"xiaozhu",
]));
        set("coor/x",70);
  set("coor/y",-300);
   set("coor/z",0);
   setup();
}
