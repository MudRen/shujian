// /d/mingjiao/bidao10.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
inherit ROOM;
void create()
{ 
        set("short","�ص�");
        set("long", @LONG
��������һ�����ߺ��ͣ���᫲�ƽ���������µ��ص����ص�Խ��Խխ����
������ֻ������һ�����ˣ�����һ�����
LONG
     );
    
	set("exits", ([
		"eastdown" : __DIR__"bidao11",
		"westup" : __DIR__"bidao9",
	]));             
        setup();
}
