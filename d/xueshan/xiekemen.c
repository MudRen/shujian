// Room: xiekemen.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "л��ͤ");
	set("long", @LONG
ǰ��һ��ϸ��ʯ����שǽ���м�һ�Ⱥ���ľ�ţ��Ŷ��������ơ��ɺס���
����˫������ͼ������ϸ�£���˼��������Ҷ��顰л��ͤ�����֡�
�������Ÿ�С����(sign)��
LONG
	);

	set("exits", ([
		"southup" : __DIR__"zhudubadian",
		"enter" : __DIR__"rimulundian",
	]));
	set("item_desc",([ "sign" : "		����Ͳ�ֹ�ڴˡ�\n",
	]));
	set("objects", ([CLASS_D("xueshan") + "/sangjie" : 1,
		__DIR__"npc/fanseng" : 2,]));
	setup();
        create_door("enter", "����ľ��", "out", DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{        
        /*
        if ((string)me->query("family/family_name") != "������" 
           && dir == "enter"  
           && present("sang jie", environment(me)))
	return notify_fail(
"ɣ��������ס���㣬һָ���Ե����ӵ�����û��������ô��ʩ��������ذɡ���\n");
	*/
        if ((string)me->query("family/family_name") != "������" 
           && dir == "enter"  
           && present("hufa lama", environment(me)))
	return notify_fail(
"����������ס������������Ǳ��·��ɼ����Ӿ�����ʩ�����������ȥǰ�����\n");

	return ::valid_leave(me, dir);
}
