// /u/cool/tls/wanfodong2.c
// cool 1998.2.13
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���ⱻ�����������ס���ⶴ���Եýϻ谵���������Ǿ����ķ�
��ǽ�ϻ��ŷ����һ���¼��Ĺ��¡����ڶ���㿴��ǽ�ϵıڻ���
�����������û��ʲô���Եĳ��ڡ�
LONG);
	set("exits", ([
	       "out" : __DIR__"wfd",
	       "north" : __DIR__"wfd3",

        ]));
        create_door("north", "ʯ��", "south", DOOR_CLOSED);

	setup();
}

void init()
{
        add_action("do_linghui","���");
        add_action("do_linghui","linghui");	
}

int do_linghui()
{
	object me = this_player();
	message_vision("$N���Ⱦ�����������������ǰ�ıڻ������ã���������\n", me);
	me->set_busy(10);
//    me->set("shen",0);
	return 1;
}

