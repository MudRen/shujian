// /d/mingjiao/bidao1.c
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
		"north" : __DIR__"bidao4",				
		"west" : __DIR__"bidao2",
       ]));             
       setup();
}
