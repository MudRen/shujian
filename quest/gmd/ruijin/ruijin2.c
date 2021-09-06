#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIY"锐金旗"NOR);
       set("long", @LONG
这里是锐金旗所在地，明教的机关武器，都出自锐金旗之手。旗下弟子不
但武功卓越，更是一等一的暗器高手，屋内堆满各类兵器防具，正中央一只巨
大火炉，奇热难当，几个大汉正自滴汗挥锤。东西各有一条长廊。
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

		message_vision(HIY"\n$N一步不慎，忽然触动了机关，从四面八方射出一片暗器。\n"NOR, me);
message_vision(HIY"\n$N大叫一声：“不好，暗器有毒！”自己却未能幸免，小臂之上中了一枚暗器，登时肿了一圈。\n\n"NOR, me);
	}
        

   
}
//是镜像
int is_mirror() { return 1; }