// /d/mingjiao/bidao18.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
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
                "northdown" : __DIR__"bidao17",
		"westup"  :  __DIR__"bidao19",
	]));             
        setup();
}

