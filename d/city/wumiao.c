// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	�����������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ��Ͼ�
��������ݡ��Ա��ƺ���һ�����š�
LONG
	);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

/*
	set("objects", ([
            "/quest/mirror/npc/office":1,
	]));

*/
	set("exits", ([
		"east" : __DIR__"beidajie2",
//		"up" : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
        create_door("northwest", "����", "southeast", DOOR_CLOSED);
	setup();
	call_other("/clone/board/wizto_b", "???");
}

