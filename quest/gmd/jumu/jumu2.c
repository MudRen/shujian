#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIG"巨木旗"NOR);
       set("long", @LONG
这里是巨木旗的所在地。这里放着各种各样的砍伐工具和一根根的大树木，
在南面有几条竖起的木大木桩，上面有许多被掌击过的痕迹，为旗中弟子平时
练功之用。旗中不但有许多力大如牛的武林高手，更有许多能工巧匠。光明顶
的宏大的建筑就是出自本旗之手。因为光明顶处在高出，所以这里是光明顶的
第一道防线，当真有一夫当关万夫莫开之势。两面是一片阴森的大树林。
LONG);    
        set("outdoors", "明教光明顶");

	set("exits", ([
                "west" :  __DIR__"jumu"+(random(4)+1),
                "south" : __DIR__"jumu"+(random(2)+3),
                "east" :  __DIR__"jumu1",
                "north" : __DIR__"jumu"+(random(3)+2),
        ]));

	setup();
}

void reset()
{
set("exits", ([
                "west" :  __DIR__"jumu"+(random(4)+1),
                "south" : __DIR__"jumu"+(random(2)+3),
                "east" :  __DIR__"jumu1",
                "north" : __DIR__"jumu"+(random(3)+2),
        ]));
}
void init()
{      object ob, me;
       int j;
	me= this_player();
	
     
	if (random(me->query("kar")) == 2)
		{
			me->apply_condition("neishang", 3 * me->query_kar());
;
		message_vision(HIG"\n$N一不小心，被飞来的一只巨木桩正撞在当胸。\n\n"NOR, me);
	}
        

   
}

//是镜像
int is_mirror() { return 1; }