// Room: /d/city/bingqiku.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰�����
�����������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һʱ��֪
����ʲô�á�
LONG
	);

	set("exits", ([
		"north" : __DIR__"bingying",
	]));

//	create_door("north", "����", "south", DOOR_CLOSED);
	set("coor/x",80);
  set("coor/y",-20);
   set("coor/z",0);
   set("incity",1);
	setup();
}
