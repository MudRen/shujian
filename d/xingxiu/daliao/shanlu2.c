
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "ɽ·");
		  set("long",@long
���н���������һ������һ�죬ֻ�ǻ�ɳ���棬����͸�ǣ�ȴҲ��ʵ�Ѱ���
long);
           set("quest",1);
		 set("exits",([
"northup" : __DIR__"shanlu3",
"southeast" : __DIR__"shanlu1",
]));
setup();
}
