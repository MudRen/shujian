// xiuxishi.c 
// ��Ϣ��
inherit ROOM;
#include <room.h>
void create()
{
	set("short", "��Ϣ��");
	set("long",@long
�����Ƕ��һ����ֵ���Ϣ�ҡ���������������������������˺ܶ�ľ����
�м���ҹ�����ֵ�Сʦ̫����˯����
long);
	set("exits",([
	    "north" : __DIR__"huazangancf",
]));
create_door("north", "С��", "south", DOOR_CLOSED);
        set("no_get_from", 1);
	set("sleep_room", 1);
     set("no_fight",1);
	setup();
}
