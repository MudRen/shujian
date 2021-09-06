#include <ansi.h>
inherit ROOM;
void create()
{ 
           set("short",HIR"烈火旗"NOR);
       set("long", @LONG
你一到这里就闻到一股股强烈的硫簧气味。这里就是烈火旗。这里放置着
各种各样的喷火枪，十多个旗下弟子正在小心翼翼制造硫簧弹，他们个个不但
是暗器名家，而且是火器名家。由此可以看出明教是多么的强大。北边是练武
场，东面是一条走廊，往南走就是兵器库了。
LONG);    
        set("exits", ([
                "west" :  __DIR__"liehuo"+(random(4)+1),
                "east" : __DIR__"liehuo"+(random(4)+1),
                "south" :  __DIR__"liehuo1",
                "north" : __DIR__"liehuo"+(random(4)+1),
        ]));             
        
        set("outdoors", "明教光明顶");
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

		message_vision(HIR"\n忽然从地下涌出一团浓浓烈火，将$N围在当间。\n\n"NOR, me);
	}
        

   
}

//是镜像
int is_mirror() { return 1; }
