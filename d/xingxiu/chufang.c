//chufang.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","����");
       set("long", @LONG
�������޵ĳ���, ��Ȼ����, ���ǹ���ư��, ���ν���, ������ȫ����̨
�϶��������ʹϹ��߲�, �����Ϻ, ���ݵĹ�������㣬ʹ��һ�߽������
��������������������뱥��һ�١���һ����������æµ�š�
LONG);

        set("exits", ([         
                "east" : __DIR__"xx3",
        ]));             

        set("objects",([
                FOOD_D("hulu") : 2,
                FOOD_D("caiyao") : 1,
                __DIR__"npc/chuzi"  : 1,
        ]));

        set("no_fight", 1);

        set("coor/x",-330);
  set("coor/y",180);
   set("coor/z",0);
   setup();
}
