inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
������һƬï�ܵ������֣������ߴ�֦Ҷïʢ����һ�߽�����
�����ʧ�˷��������ľ������·������ס�ˡ�
LONG);

     set("outdoors", "������");
     set("exits",([
           "east" : __DIR__"songlin-4",
           "west" : __DIR__"songlin-1",
           "north" : __DIR__"songlin-4",
           "south" : __DIR__"songlin-3",
     ]));
    
     set("coor/x",-310);
  set("coor/y",-290);
   set("coor/z",40);
   setup();
}
#include "songlin.h"