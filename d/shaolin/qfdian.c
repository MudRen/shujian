// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "ǧ���");
	set("long", @LONG
����ǧ���������������ȣ��߱����硣���﹩����������
���а��������Ľ�գ���ٰ��ޣ���ǧ���У�ʮһ���ף�ʮ��٤�����Լ���
�������������ĵȡ�ֱ�������ۻ����ҡ������е�Сľ�š�
LONG
	);

	set("exits", ([
		"south" : __DIR__"kchang",
		"north" : __DIR__"shanlu1",		
	]));

	set("objects",([
		CLASS_D("shaolin") + "/qing-guan" : 1,
	]));

//	create_door("north","ľ��","south",DOOR_CLOSED);

	set("coor/x",50);
  set("coor/y",430);
   set("coor/z",130);
   setup();
}



