// d/hz/tianxiang.c �����ջ

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"�����ջ"NOR);
	set("long", @LONG
�����ջ�Ǻ��ݳ������Ŀ͵��ˣ����ǵ�������������ο�ƣ�ͺ�
��������С�������ջ���ϰ�ǳ��ÿͣ���������ķ�Ǯ�ȱ�Ҫ���˵�
�ࡣ��һ�߽������С����Цӯӯ��ӭ�˹�����ǽ�Ϲ���һ������(paizi)��
LONG
	);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("no_fight",1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"yuemiao",
		"north" : __DIR__"qsddao4",
		"east" : __DIR__"majiu",
		"up" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid")!="�����ջ" && dir == "up" )
		return notify_fail("��ô�ţ����ס���Ǻ����ջ����\n");
	if ((string)me->query_temp("rent_paid")=="�����ջ" && dir == "west" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ�\n"+
				"���˻���ΪС���ź����أ�\n");
	return ::valid_leave(me, dir);
}
