// /u/beyond/hz/yuanmen.c ԰��
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIW"԰��"NOR);
        set("long", @LONG
��Ĺ԰����һ��СͥԺ�������ϱ��������ȣ����ȳ�����������������
ʫ�˸������ɵ��Ĵʱ��̣����������ɵ��ּǡ������졷����ǰ���ʦ����
�������¡��θ���گ�顢���ɵ�ʯ����ȡ�
LONG
        );
        set("exits", ([
            "east" : __DIR__"jingzhong",
            "out" : __DIR__"yuemiao",
            
]));
        set("coor/x",90);
  set("coor/y",-350);
   set("coor/z",10);
   setup();
}
