#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"����Ժ"NOR);
        set("long", @LONG
������ʯ·�Ե�һ��СԺ�ӣ��������񣬵���������Ʈ������롣
һ�԰��м�ֻʯ�ʣ���׼�����������Ъ���õġ�
LONG);
        set("outdoors", "������");
        set("exits", ([                           
               "north" : __DIR__"zt1",
               "east" : __DIR__"road",
        ]));
        set("coor/x",-360);
  set("coor/y",-360);
   set("coor/z",20);
   setup();
}
