// Modify By River 98/12
#include <ansi.h>
#include <room.h>;
inherit ROOM;

void create()
{
        set("short", HIW"ɽ��С·"NOR);
        set("long", @LONG
��ǰ��һ��ɽ�ڣ�·��ʼ��ƽ̹�������Բ����ߣ��㲻�ϵĲ�������·
�ϵ��Ӳݣ�������ż������һ�����Ұ�޽�����ͷ����һЩ��֪����С������
����ȥ�����ܴ����ܲ����ʻ��̲��������֡�
LONG);
        set("outdoors", "����");
        set("exits", ([             
               "southeast" : __DIR__"road4",   
               "westdown" : __DIR__"road2",   
        ]));

        set("coor/x",-240);
  set("coor/y",-410);
   set("coor/z",0);
   setup();
}

void init()
{
      object me = this_player();
      if (me->query_temp("xuncheng") && random(20) < 3 ){
      me->move(__DIR__"road"+(random(3)+1));
      }
}
