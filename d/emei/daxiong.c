// daxiong.c
// ���۱���

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "�����ִ��۱���");
	set("long",@long
���Ƕ���ɽ�����ֵĴ��۱�����й���������������һȺ����Сʦ̫��
�ڵ����о��������е�С��ͨ����
long);
	set("exits",([
	    "south" : __DIR__"houdian",
	    "east" : __DIR__"huazanganzt",
	    "west" : __DIR__"huazangancf",
	    "northdown" : __DIR__"huazangangc",
]));
create_door("south", "С��", "north", DOOR_CLOSED);
	setup();
}
