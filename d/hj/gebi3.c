// gebi1.c
#include <room.h>
inherit ROOM;
void create()
{
       set("short","����");
       set("long", @LONG
��������Ĵ��ڣ�Ҫ�߳����ﲢ�����¡���Զ������ɳ������ǵذ㴵
��������Ҫ��籩�ˡ�
LONG);
        set("exits", ([
                "north" : __DIR__"gebi2",
                "south" : __DIR__"gebi1",
                "east" : __DIR__"gebi4",
                "west" : __FILE__,
        ]));
        set("outdoors", "����");
        set("coor/x",-310);
  set("coor/y",150);
   set("coor/z",0);
   setup();
}

#include "gebi.h";
