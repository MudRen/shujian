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
           "east" : __DIR__"songlin-2",
           "west" : __DIR__"songlin-4",
           "north" : __DIR__"songlin-3",
           "south" : __DIR__"songlin-1",
     ]));
    
     set("coor/x",-310);
  set("coor/y",-290);
   set("coor/z",40);
   setup();
}
#include "songlin.h"