#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"��ˮ��"NOR);
       set("long", @LONG
�����Ǻ�ˮ�졣������ʮ��������ˮ�����е��Ӹ�����ͨˮ�ԡ��򶫾�
��ͨ����ˮ��̶��ɽ��С·�ˡ�
LONG);    
        set("exits", ([
                "west" :  __DIR__"hongshui"+(random(4)+1),
                "east" : __DIR__"hongshui"+(random(4)+1),
                "south" :  __DIR__"hongshui4",
                "north" : __DIR__"hongshui"+(random(4)+1),
        ]));
                 
        
        set("outdoors", "���̹�����");
        set("coor/x",-270);
  set("coor/y",190);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",190);
   set("coor/z",120);
   setup();
}

void reset()
{
set("exits", ([
                "west" :  __DIR__"hongshui"+(random(4)+1),
                "east" : __DIR__"hongshui"+(random(4)+1),
                "south" :  __DIR__"hongshui4",
                "north" : __DIR__"hongshui"+(random(4)+1),
        ]));
}
void init()
{      object ob, me;
       int j;
	me= this_player();
	
      
	if (random(me->query("kar")) == 2)
		{
me->receive_wound("qi", random (me->query("max_qi") /100)  );
me->apply_condition("fs_poison", 3 * me->query_kar());

		message_vision(HIW"\n$Nһ����������ˮ������һ����ˮ���м�ǿ�ĸ�ʴ�ԡ�\n"NOR, me);
message_vision(HIW"\n$N���һ���������ã���ˮ�ж������Լ�ȴδ�����⣬����մ�˼���ˮ�飬��ʱ����ð���˰��̡�\n\n"NOR, me);
	}
        

   
}
//�Ǿ���
int is_mirror() { return 1; }