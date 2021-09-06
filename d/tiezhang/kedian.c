// Room: /city/kedian.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������ţ���
������������������صķ������顣��С����������æ������ת���Ӵ�����ǻ
�����Ŀ��ˡ�
LONG
    );
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"lx",
		"up" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "up" && is_wanted(me))
		return 0;

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid")=="����ɽ��" && dir == "west" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ�\n");
	return ::valid_leave(me, dir);
}
