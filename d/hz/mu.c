// /u/beyond/hz/mu.c ����Ĺ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",BLU"����Ĺ"NOR);
        set("long", @LONG
��ͥԺ�������ţ����뼴Ϊ����Ĺ��Ĺ������ʯ����ʯ��ʯ���ʯ��
�ٵȡ�Ĺǰ׭�С���������Ĺ�����־ޱ���Ĺǰ����˫�ֹ���������ĸ���
����������Ĺ����һ��(lian)��Ĺǰ�����ϵ�һ������ǣ�����а�Թ�ͬ
��̿�������ڽ���α�桱��
LONG
        );
set("item_desc",([
"lian" :         "��ɽ�������ҹ�    �����޹�������\n"
]));
        set("exits", ([
            "north" : __DIR__"jingzhong",
                        
]));
        set("coor/x",100);
  set("coor/y",-360);
   set("coor/z",10);
   setup();
}
