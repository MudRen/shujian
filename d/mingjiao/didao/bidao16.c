// /d/mingjiao/bidao16.c
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
		"westdown" : __DIR__"bidao15",
		"southup"  : __DIR__"bidao17",
	]));             
        setup();
}
