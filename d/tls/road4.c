#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ʯ·"NOR);
        set("long", @LONG
�����������º�ɽɮ�˺��׼ҵ�������֮�������ߴ����˷�����
���������������µ������������ٵ���������ѡ�Լ����ֵı�������
���Ǵȱ�Ժ������ɽ���Ƕ�ĸ��������������ɮ��˯����
LONG);
        set("outdoors", "������");
        set("exits", ([             
               "west" : __DIR__"dmg",
               "east" : __DIR__"cby",  
               "north" : __DIR__"sroom",                            
               "southdown" : __DIR__"yz3",                           
        ]));
        set("coor/x",-350);
  set("coor/y",-280);
   set("coor/z",30);
   setup();
}