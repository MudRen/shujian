#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"洪水旗"NOR);
       set("long", @LONG
这里是洪水旗。此旗有十分厉害的水阵，旗中弟子个个深通水性。向东就
是通往碧水寒潭的山间小路了。
LONG);    
        set("exits", ([
                "west" :  __DIR__"hongshui"+(random(4)+1),
                "east" : __DIR__"hongshui"+(random(4)+1),
                "south" :  __DIR__"hongshui4",
                "north" : __DIR__"hongshui"+(random(4)+1),
        ]));
                 
        
        set("outdoors", "明教光明顶");
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

		message_vision(HIW"\n$N一个不防，被水柱喷了一身，那水竟有极强的腐蚀性。\n"NOR, me);
message_vision(HIW"\n$N大叫一声：“不好，这水有毒！”自己却未能幸免，脸上沾了几滴水珠，登时兹兹冒起了白烟。\n\n"NOR, me);
	}
        

   
}
//是镜像
int is_mirror() { return 1; }