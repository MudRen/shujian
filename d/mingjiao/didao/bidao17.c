// /d/mingjiao/bidao17.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{ 
       set("short","�ص�");
       set("long", @LONG
����һ���������ϵ��ص���
LONG
     );
       set("exits", ([
		"northdown" : __DIR__"bidao16",	
		"southup"  :  __DIR__"bidao18",
                "eastdown"  :  __DIR__"bidao4",
       ]));             
       setup();

}

int valid_leave(object me, string dir)
{
        if (dir == "eastdown" )
         return notify_fail(HIY"\n����������ȥ��������ȷʵ̫���޷��Žš�\n\n"NOR);
        return ::valid_leave(me, dir);
}
