// Room: /u/xdd/gumu/ryy.c
// Modify by river 98/08/29
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short", HIY"������"NOR);
     set("long", @LONG
��ȥ��·��Ȼ�վ�����ʯ���£��������ϡ��ߴ�ɭȻ��Խ����ʯ��ң���
Ӧ��һʯ��Բ�������գ�һʯ����������¡��������������ڡ�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "northdown" : __DIR__"jlg",
         "westup" : __DIR__"bzy",
       ]));

     set("coor/x",0);
  set("coor/y",-30);
   set("coor/z",40);
   setup();
}
 