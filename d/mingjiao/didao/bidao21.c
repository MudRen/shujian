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
�������ص��ĳ��ڣ�ֱͨ���̺����졣
LONG
     );
    
	set("exits", ([
             "out" : "/d/mingjiao/tuqi",
             "west"  :  __DIR__"bidao20",
	]));             
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "out") {
                write(HIW"\n����ö�����ǿ����ҫ��һʱ֮�侹Ȼ�������ۡ�\n\n"NOR);
        }
        return 1;
}
