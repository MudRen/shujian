// /d/mingjiao/bidao8.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","�ص�");
       set("long", @LONG
��������һ�����ߺ��ͣ���᫲�ƽ���������µ��ص���
LONG
     );
    
	set("exits", ([
		"out" : __DIR__"bidao7",
		"eastdown" : __DIR__"bidao9",
	]));             
        setup();
}

