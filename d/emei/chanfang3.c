// Room: /d/emei/chanfang3.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
//#include "jingzuo.h";
void create()
{
	set("short", "����");
	set("long", @LONG
������һ�䰲�������������������е��Ӵ�������֮������������
����ط���������š���λ����ʦ̫���׼�Ů�����������붨��
LONG
	);
	set("exits", ([ 
	  "west" : __DIR__"wanniananzd",
]));
    set("jingzuo", 1);
    set("no_fight", 1);
	set("no_clean_up", 0);
create_door("west", "С��", "east", DOOR_CLOSED);
	setup();

}

