// huazangancf.c
// ����
inherit ROOM;
#include <room.h>
#include <ansi.h>
//#include "jingzuo.h";
void create()
{
	set("short", "����");
	set("long",@long
������Ƕ��һ����ֵ�����������ɢ�ҵط���������ţ�ľ��ȣ��˴�
���Ǳ��ɵ��Ӵ�������֮������λ����ʦ̫���׼�Ů�����������붨��
long);
	set("exits",([
	    "north" : __DIR__"xcelang",
	    "south" : __DIR__"xiuxishi",
	    "east" : __DIR__"daxiong",
]));
    set("jingzuo", 1);
    set("no_fight", 1);
create_door("south", "С��", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
        if ((string)me->query("gender")=="����" && dir == "south")
                return notify_fail("������ʦ̫����Ϣ�ĵط����㲻�ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

