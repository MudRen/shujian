// Room: /d/emei/daxiongdian.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "���۵�");
	set("long", @LONG
�����Ǳ����´��۵�������Ƕ���ɽ�����Ժ֮һ�����۵��ڹ��Ž��
�Ӳӵķ�������������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
	  "enter" : __DIR__"cangjinglou",
	  "out" : __DIR__"baoguosi",
	  "east" : __DIR__"xiuxishi2",
	  "west" : __DIR__"baoguosicf",
]));
	set("coor/x",-190);
  set("coor/y",-120);
   set("coor/z",20);
   setup();
}
