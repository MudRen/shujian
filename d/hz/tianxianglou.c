// /u/beyond/hz/tianxianglou.c �����ջ
#include <ansi.h>
#include <room.h>
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
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
     "west" : __DIR__"yuewangmiao",
"north" : __DIR__"qsddao4",
     "east" : __DIR__"majiu",
		"up" : __DIR__"kedian2",
	]));

	set("coor/x",100);
  set("coor/y",-350);
   set("coor/z",0);
   setup();
	"/clone/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
