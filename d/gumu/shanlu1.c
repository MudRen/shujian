// Room: /u/xdd/gumu/shanlu1.c
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIY"ɽ´"NOR);
     set("long", @LONG
��᫵�ɽ·������ʮ�ֶ��ͣ����Ƕ༸���೤������ȫ������������
ɽ·��ʯ��Ҳ��˶�������
LONG        );

     set("outdoors","��Ĺ");     

     set("exits", ([
         "southup" : __DIR__"shanlu2",
         "northdown" : __DIR__"xiaolu3",
     ]));

     set("coor/x",-10);
  set("coor/y",10);
   set("coor/z",10);
   setup();
}
