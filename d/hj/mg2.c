// mg2.c �Թ�����
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN "�߲��Թ�" NOR);
        set("long", @LONG
����������ȥ�������Թ��ڹ���Խ��Խ�ڣ���������µ�·��ǰ�������
���˼��������
LONG);
        set("no_sleep_room", 1);
        set("exits", ([            
              "south" : __DIR__"mg1",
              "north" : __DIR__"mg4",            
        ]));        
   set("coor/x",-310);
  set("coor/y",170);
   set("coor/z",20);
   setup(); 
}
