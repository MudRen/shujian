// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"Ϸ԰��"NOR);
        set("long", @LONG
����һ��������ﶦ��������Ϸ԰��̨�²�ʱ�ش���Ʊ���ǵĽ�Ծ���Ȳ�
��������һ����Ϸ̨��̨�����ݵľ��ʣ��ǡ����ɴ򻢡�����Ҳ�̲�ס������
������Ϸ������һ�½�ǡ�
LONG
);
        set("exits", ([ 
             "east" : __DIR__"xijie6",
	]));
        set("objects",([
              __DIR__"npc/piaoyou" : 1,
        ]));
        set("coor/x",-340);
  set("coor/y",-440);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/xiyuan",1);
      }
}
