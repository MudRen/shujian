#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ʯ·"NOR);
        set("long", @LONG
��������һ�ΰ�ʯ·��ʯ��ƽ������ɨ�øɸɾ�����·�����и�ʽ��
�ݣ����������������������ߡ�
LONG);
        set("outdoors", "������");
        set("exits", ([             
               "west" : __DIR__"wwj",
               "east" : __DIR__"lang",               
        ]));

        set("coor/x",-300);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}