#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIY"�����"NOR);
       set("long", @LONG
��������������ڵأ����̵Ļ��������������������֮�֡����µ��Ӳ�
���书׿Խ������һ��һ�İ������֣����ڶ�������������ߣ�������һֻ��
���¯�������ѵ������������Եκ��Ӵ�����������һ�����ȡ�
LONG);    
        set("exits", ([
                "west" :  __DIR__"ruijin"+(random(2)+1),
                "east" : __DIR__"ruijin"+(random(3)+1),
                "south" :  __DIR__"ruijin2",
                "north" : __DIR__"ruijin"+(random(4)+1),
        ]));             
        
        
        set("coor/x",-270);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}
void reset()
{
set("exits", ([
                "west" :  __DIR__"ruijin"+(random(2)+1),
                "east" : __DIR__"ruijin"+(random(3)+1),
                "south" :  __DIR__"ruijin2",
                "north" : __DIR__"ruijin"+(random(4)+1),
        ]));
}
void init()
{      object ob, me;
       int j;
	me= this_player();
	
     

	if (random(me->query("kar")) == 2)
		{
me->receive_wound("qi", random (me->query("max_qi") /100)  );
me->apply_condition("man_poison", 3 * me->query_kar());

		message_vision(HIY"\n$Nһ����������Ȼ�����˻��أ�������˷����һƬ������\n"NOR, me);
message_vision(HIY"\n$N���һ���������ã������ж������Լ�ȴδ�����⣬С��֮������һö��������ʱ����һȦ��\n\n"NOR, me);
	}
        

   
}
//�Ǿ���
int is_mirror() { return 1; }