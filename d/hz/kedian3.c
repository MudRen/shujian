// /u/beyond/hz/kedian3.c �͵�
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIC"�͵��¥"NOR);
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ�������ٿ�
�������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ����������
�����˹�ȥ��
LONG
	);

	set("sleep_room", 1);
	set("no_fight", 1);
        set("hotel",1);
	set("exits", ([
		"out" : __DIR__"kedian2",
	]));

	set("coor/x",100);
  set("coor/y",-350);
   set("coor/z",20);
   setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}

