// /d/mingjiao/bidao19.c
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","�ص�");
       set("long", @LONG
�������ص��ĳ��ڣ�ֱͨ��ɽ����
LONG);    
	set("exits", ([
		"out" : "/d/mingjiao/shanyao",
		"eastdown"  :  __DIR__"bidao18",
	]));             
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "out")
          write(HIW"\n����ö�����ǿ����ҫ��һʱ֮�侹Ȼ�������ۡ�\n"NOR);
          return 1;
}
