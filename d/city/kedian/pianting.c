#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG "ƫ��" NOR);
	set("long","���ǿ͵��ƫ����ֻ��һ���ɹ�Ů�Ӻ�һЩ�ɹ�ʿ���ڴˡ�\n");

	set("objects", ([
		__DIR__"hebw": 1,
		__DIR__"luzk": 1,
		__DIR__"zhao": 1,
	]));

	set("exits", ([
		"west" : "/d/city/kedian",
//		"east":	__DIR__"bonus_room",
	]));

	setup();
	"/clone/board/skill_b"->foo();
}

void init()
{
	object me = this_player();
	if (me->query("zhao_job")){
		me->add("job_time/����", me->query("zhao_job"));
		me->delete("zhao_job");
	}
}

int valid_leave(object me, string dir)
{
	object *inv;

	inv = filter_array(deep_inventory(me), (: userp :));
	if ( dir != "west")
	if( me->query("bxsj_bonus/exp") || me->query("bxsj_bonus/oldsj") || sizeof(inv) || me->query("registered") != 3 )
		return notify_fail(HIR"�����ڵ�״̬���޷�����÷��䡣\n"NOR);
	return ::valid_leave(me, dir);
}
