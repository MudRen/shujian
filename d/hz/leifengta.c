// /u/beyond/hz/leifengta.c �׷���
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIW"�׷���"NOR);
        set("long", @LONG
Ϧ��ɽ�ϱ�ֲ�����ͺ�㡣ÿ��������־�Ⱦ������׳�ۡ�ɽ����һ
�������׷������񻰡����ߴ����еİ�������Ǳ������������������ÿ
��Ϧ�����£��������ƣ���Ӱ����������������������׷�Ϧ�ա���
LONG
        );
    set("outdoors", "����");
        set("exits", ([
            "westdown" : __DIR__"shanlu",
            ]));
        set("coor/x",70);
  set("coor/y",-300);
   set("coor/z",0);
   setup();
}
 
