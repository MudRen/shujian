// /d/mingjiao/bidao15.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
        set("short","�ص�");
        set("long", @LONG
����һ���������ϵ��ص���
LONG
     );
    
	set("exits", ([
             "eastup" : __DIR__"bidao16",               
             "northup"  :  __DIR__"bidao20",
             "north" : __DIR__"bidao22",
	]));             
        setup();
}
