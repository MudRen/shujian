// Room: /u/xdd/gumu/shanlu2.c
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",YEL"�ڶ�"NOR);
     set("long", @LONG
�����˰��գ����������ڶ����˴���һ��������ź��д�š��չ��¡�
�������֡������Ǽ���ߴ��������˨�ż�ƥ����
LONG        );

     set("outdoors","��Ĺ");     

     set("exits", ([
         "southup" : __DIR__"shanlu3",
         "northdown" : __DIR__"shanlu1",
     ]));

     set("coor/x",-10);
  set("coor/y",0);
   set("coor/z",20);
   setup();
}
 