#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"����Ժ"NOR);
        set("long", @LONG
������ʯ·�Ե�һ��СԺ�ӣ�Ժ�ڱ�ֲ����������紵������
�����Ʈ��������ɳɳ�����졣һ�԰��м�ֻʯ�ʣ���׼���������
��Ъ���õġ�
LONG);
        set("outdoors", "������");
        set("exits", ([                           
               "north" : __DIR__"zt",
               "west" : __DIR__"road",
        ]));
        set("coor/x",-340);
  set("coor/y",-360);
   set("coor/z",30);
   setup();
}
