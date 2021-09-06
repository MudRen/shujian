// Room: fanyinge.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "������");
	set("long", @LONG
��Ϊ���䵥���̨�����������������ש���ɵ���������С���裬����
�������ܷ���һ�𡣾��������ģ���������̨�ϣ�ͷ��ð����⡣�������о�
���ĵط����ڶ��Ͻ����Ȳ������۵ĺ���ľ�š�
LONG
	);

	set("exits", ([
		"north" : __DIR__"fatang",
		"east" : __DIR__"jingtang",
		"west" : __DIR__"jingangyuan",
		"southdown" : __DIR__"hufazhacang",
		"northwest" : __DIR__"fotang",
	]));
        set("objects", ([__DIR__"npc/fanseng" : 2]));
	setup();
        create_door("northwest", "����ľ��", "southeast", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
        if (!present("shou yu", me)
           && dir == "northwest"  
           && present("hufa lama", environment(me)))
	return notify_fail(
"����������ס���������ɽ�Ǳ����صأ���û�з��ɵ����ͣ����ܽ�ȥ��\n");

	return ::valid_leave(me, dir);
}
