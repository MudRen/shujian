// Room: /d/emei/baoguoshicf.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
//#include "jingzuo.h";
void create()
{
	set("short", "����������");
	set("long", @LONG
���Ǳ����µ������������е��ӻ�ɽ֮ǰͨ���ڴ˽���һ�ޣ��ñ���
������ɽ�����ڰ���һ�ų�������ǽ���м���ľ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
	  "east" : __DIR__"daxiongdian",
]));
    set("jingzuo", 1);
// create_door("east", "С��", "west", DOOR_CLOSED);
	set("coor/x",-200);
  set("coor/y",-120);
   set("coor/z",20);
   setup();
}
