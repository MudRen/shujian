#include <ansi.h>
inherit ROOM;
void create()
{ 
           set("short",HIR"�һ���"NOR);
       set("long", @LONG
��һ��������ŵ�һ�ɹ�ǿ�ҵ������ζ����������һ��졣���������
���ָ��������ǹ��ʮ������µ�������С������������ɵ������Ǹ�������
�ǰ������ң������ǻ������ҡ��ɴ˿��Կ��������Ƕ�ô��ǿ�󡣱���������
����������һ�����ȣ������߾��Ǳ������ˡ�
LONG);    
        set("exits", ([
                "west" :  __DIR__"liehuo"+(random(4)+1),
                "east" : __DIR__"liehuo"+(random(4)+1),
                "south" :  __DIR__"liehuo1",
                "north" : __DIR__"liehuo"+(random(4)+1),
        ]));             
        
        set("outdoors", "���̹�����");
        set("coor/x",-250);
  set("coor/y",230);
   set("coor/z",120);
   setup();
}
void reset()
{
set("exits", ([
                "west" :  __DIR__"liehuo"+(random(4)+1),
                "east" : __DIR__"liehuo"+(random(4)+1),
                "south" :  __DIR__"liehuo1",
                "north" : __DIR__"liehuo"+(random(4)+1),
        ]));
}
void init()
{      object ob, me;
       int j;
	me= this_player();
	
      
	if (random(me->query("kar")) == 2)
		{
me->receive_wound("qi", random (me->query("max_qi") /100)  );
me->apply_condition("hyd_condition", 3 * me->query_kar());

		message_vision(HIR"\n��Ȼ�ӵ���ӿ��һ��ŨŨ�һ𣬽�$NΧ�ڵ��䡣\n\n"NOR, me);
	}
        

   
}

//�Ǿ���
int is_mirror() { return 1; }
