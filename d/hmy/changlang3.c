// /d/hmy/changlang3.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�������Ĺ������������Զ���ǽ��ÿ�������ɣ�ǽ�϶�����һ֧���λ�
�ľ���
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"lgfang",
		"east" : __DIR__"changlang4",
		"west" : __DIR__"qqiudian",
		"south" : __DIR__"shufang",
	]));
/*
	set("objects", ([ 
	  __DIR__"npc/yang" : 1,
]));
*/
	setup();
}

/*
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "�������") && dir == "north" &&
		objectp(present("yang", environment(me))))
	   return notify_fail("����ͤ�ȵ����㲻��������̵��ӣ��������ڡ�\n");
		
        return ::valid_leave(me, dir);
}
*/
