// Room: /u/xdd/gumu/ztm.c
// Modify By river 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIG"������"NOR);
     set("long", @LONG
�˵�����ȫ��������ţ�һ��ߴ���Ʒ������ڰ�ɽ�Ŀ������ϣ�ȫ���
�����µ�ʿ�ڴ˷����������ʴ˴�����������ƣ�����������Ů���Ĺ����
�����ġ�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "southdown" : __DIR__"jlg",
         "westdown" : __DIR__"shanlu3",
     ]));

     set("coor/x",0);
  set("coor/y",-10);
   set("coor/z",40);
   setup();
}
