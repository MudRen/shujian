// /u/beyond/hz/wenlange.c ������
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIC"������"NOR);
        set("long", @LONG
������λ�ڹ�ɽ����´�������ṹ���أ�ȫΪľ�ṹ�����Եĵ�ʯ��ɽ��
һ����ˮ��������ԭ��һ����󣬺���ս����رա����ڵ��������������
���飬��������ã������ܹ�����һ����
LONG
        );
        set("exits", ([
            "north" : __DIR__"gushan",
]));
        set("coor/x",70);
  set("coor/y",-360);
   set("coor/z",0);
   setup();
}
