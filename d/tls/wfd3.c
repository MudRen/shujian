// /u/cool/tls/wanfodong3.c
// cool 1998.2.13
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����ڶ�");
	set("long", @LONG
��������𶴵��ڶ��ˣ������Եýϻ谵�쳣���㿴����ʲô��
�������ھ����ģ�ֻ�����Լ��ĽŲ����������������������и�����
����ǽ�����š�����û��ʲô���Եĳ��ڡ�
LONG);
	set("exits", ([
	       "south" : __DIR__"wfd2",
        ]));
      
        create_door("south", "ʯ��", "north", DOOR_CLOSED);
	setup();
}


