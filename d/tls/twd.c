#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"������"NOR);
        set("long", @LONG
����ǰԺһ�ΰ�ʯС·�������߲�ʯ�ף������������������
�����Ĵ��ħ��գ����й�������յ�������������ۻ��棬һ������
�ߵ��������������ơ�������������Ժ��ի�á�
LONG);
        set("exits", ([             
               "southdown" : __DIR__"road",
               "northdown" : __DIR__"road1",                             
        ]));
        set("coor/x",-350);
  set("coor/y",-350);
   set("coor/z",30);
   setup();
}