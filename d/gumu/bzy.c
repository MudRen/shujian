// Room: /u/xdd/gumu/bzy.c
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short", HIG"������"NOR);
          set("long", @LONG
���������ң��㲻������������û�м�������ʵ�������ʵǡ��Ⱨ������
��������֣�����һ�����˱��Ÿ�����һ�㡣���񹤣�׿Ȼ��ɣ�����̾����
LONG        );

         set("outdoors","��Ĺ");

         set("exits", ([
               "eastdown" : __DIR__"ryy",
               "southup" : __DIR__"lyy",
         ]));

//       set("objects", ([
//              __DIR__"obj/limochou" : 1,
//       ]));
         set("coor/x",-10);
  set("coor/y",-30);
   set("coor/z",50);
   setup();
}
