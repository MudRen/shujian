// /d/mingjiao/bidao19.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","�ص�");
       set("long", @LONG
�������ص��ĳ��ڣ�ֱͨ��ɽ����
LONG
     );
    
	set("exits", ([
               "east" : __DIR__"bidao21",
               "southdown"  :  __DIR__"bidao15",
	]));             
        setup();
}
