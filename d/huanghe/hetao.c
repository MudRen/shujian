// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ե����ƺӾź�������һ�ס������׵������ϵͳ������ط��֣���
��ׯ�ڵĺõط���
LONG );
	set("exits", ([
		"northwest" : __DIR__"huanghe_1",
		"south"      : __DIR__"weifen",
	]));

	set("objects",([
		NPC_D("tiao-fu") : 1,
	]));

	set("outdoors", "�ƺ�");
	setup();
}
