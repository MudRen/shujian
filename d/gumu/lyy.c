// Room: /u/xdd/gumu/lyy.c
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",YEL"������"NOR);
     set("long", @LONG
ɽ���˴���Ȼ��խ�������ľ����ضٰ���ӭ����һ����ʯ��������״��
ɭ�ɲ����Կ�ƾ�٣�����һ�������������ӡ�˵�����Ĺ����������Һ�����
��֪���ж���ɱ����
LONG        );

     set("outdoors","��Ĺ");
    
     set("exits", ([
         "east" : __DIR__"shulin1",
         "northdown" : __DIR__"bzy",
     ]));
     
     set("coor/x",-10);
  set("coor/y",-40);
   set("coor/z",60);
   setup();
}
