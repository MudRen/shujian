// /d/mingjiao/diechong6.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","秘道");
       set("long", @LONG
这里是明教秘道，你似乎迷失了方向，象没头苍蝇般到处乱闯。
LONG
     );
    
	set("exits", ([
		"west" : __DIR__"mbidao"+(random(5)+1),			
		"south" : __DIR__"mbidao"+(random(5)+1),
		"east" : __DIR__"mbidao5",
		"north" : __DIR__"mchukou",
	]));    

        setup();

}

void init()
{
	object me,room;
	me=this_player();
	room=this_object();
	message_vision(YEL"\n$N一不小心，在秘道中迷路了！看来要走出去要花很多时间。\n\n"NOR,me);
}
