// Room: /d/emei/chanfang2.c

inherit ROOM;
#include <room.h>
#include <ansi.h>
//#include "jingzuo.h";
void create()
{
	set("short", "����");
	set("long", @LONG
������һ�䰲����������������ǧ�����е��Ӵ�������֮������������
�������������š���λ����ʦ̫���׼�Ů�����������붨��
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"qianfoandd",
]));
    set("jingzuo", 1);
    set("no_fight", 1);
create_door("west", "С��", "east", DOOR_CLOSED);
	setup();
}
