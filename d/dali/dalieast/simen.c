// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY"�黨��"NOR);
	set("long", @LONG
��վ��һ��СС�Ĺ���ǰ����������д�š��黨�¡����֡�����Ǵ����
�̡����������⣬������ʮ��С���԰ټƣ��������黨�¡��ش�ƫƧ������
��𣬼������Ӵ���֮�ˣ����Ҳ��֪����
LONG
	);
        set("outdoors", "����");
	set("exits", ([ 
               "northwest" : __DIR__"road4",   
               "enter" : __DIR__"nianhuasi",   
        ]));

        set("objects", ([
	      __DIR__"npc/shami" : 1,
        ]));

	set("coor/x",-220);
  set("coor/y",-430);
   set("coor/z",0);
   setup();
}
void init()
{
            object me = this_player();
     if(me->query_temp("xuncheng"))
     {
       me->set_temp("dali_xc/nianhuasimen",1);
      }
}