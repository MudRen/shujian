#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"厚土旗"NOR);
       set("long", @LONG
这里是厚土旗。这里有各种各样的窟土工具，旗中弟子一个个短小而精悍，
练就一身窟土功夫，他们在教中累立奇功。四周是明教其它四行旗，五旗互成
倚角之势。
LONG);    

        set("outdoors", "明教光明顶");

	set("exits", ([
                "east" :  __DIR__"houtu"+(random(4)+1),
                "south" : __DIR__"houtu"+(random(4)+1),
                "west" :  __DIR__"houtu1",
                "north" : __DIR__"shanlu",
        ]));

	setup();
}

void reset()
{
set("exits", ([
                "east" :  __DIR__"houtu"+(random(4)+1),
                "south" : __DIR__"houtu"+(random(4)+1),
                "west" :  __DIR__"houtu1",
                "north" : __DIR__"shanlu",
        ]));
}
void init()
{      object ob, me;
       int j;
	me= this_player();
	
      

	if (random(me->query("kar")) == 2)
		{
			me->start_busy(random(20));
		message_vision(YEL"\n$N一不小心，两脚陷入陷阱之内，一时动弹不得，不由心下大骇。\n\n"NOR, me);
	}
        

   
}

//是镜像
int is_mirror() { return 1; }