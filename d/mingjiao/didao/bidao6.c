// /d/mingjiao/bidao6.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
inherit ROOM;
void create()
{ 
        set("short","�ص�");
        set("long", @LONG
����һ���������µ��ص���
LONG
     );
    	set("exits", ([
		"southup" : __DIR__"bidao5",
		"eastdown" : __DIR__"bidao7",
	]));             
        setup();
}

