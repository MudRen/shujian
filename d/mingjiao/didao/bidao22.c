// /d/mingjiao/bidao19.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
        set("short","����");
       set("long", @LONG
�����������ص����һ��СС�����ҡ�
LONG
     );
    
	set("exits", ([
                  "south" : __DIR__"bidao15",
	]));             
        set("objects",([
                CLASS_D("mingjiao") + "/cheng" : 1,
        ]));
        setup();
}
