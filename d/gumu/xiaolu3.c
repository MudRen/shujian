// Room: /u/xdd/gumu/xiaolu2
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>

void create()
{
     set("short",HIG"���С��"NOR);
     set("long", @LONG
����ɽ�µ�С��������ȫ���ƽ�����������ɽ��ȫ���ɵ������������죬
����һ�����������ٰ��ճ��������Ҳ����������ʿ������䡣
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "north" : __DIR__"xiaolu2",
         "southup" : __DIR__"shanlu1",
         "southeast" : __DIR__"shanxia",
     ]));

     set("coor/x",-10);
  set("coor/y",20);
   set("coor/z",0);
   setup();
}
