// /d/mingjiao/bidao13.c �ؽ���
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
inherit ROOM;
void create()
{ 
        set("short","�ؽ���");
        set("long", @LONG
����һ�������ص��µ�һ���ر����ĵط��������������ˣ��ܶ��������
���⣬�������á�
LONG
     );
    	set("exits", ([
		"north" : __DIR__"bidao12",
	]));             
        
	set("objects",([
		"/d/mingjiao/obj/dafu"  :        1,
	]));
	setup();
}
