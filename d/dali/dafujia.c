// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"��֮��"NOR);
        set("long", @LONG
����һ�Ҵ�����ڵĸ����˼ң�������˾���һ���ӣ����˲���Ǯ���ڴ�
����ڸ�����ô����լ�ӣ��ſ�����������ʯʨ�ӣ�վ�������Ҷ���
LONG
       );
        set("exits", ([ 
           "north" : __DIR__"nanjie4", 
	]));

        set("objects", ([
             __DIR__"npc/jiading" : 2, 
             __DIR__"npc/mawude" : 1,
        ]));
        set("coor/x",-300);
  set("coor/y",-470);
   set("coor/z",-20);
   set("coor/x",-300);
  set("coor/y",-470);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/dafujia",1);
      }
}
