// By River 2002.6.3

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

void create()
{
	set("short", HIG"é��"NOR);
	set("long", @LONG
������һ�������Ӵ�ɵ�é�ݣ����ڰ�����ӣ�������������Ϣ��Сé�ݣ�
��ǽ�Ƿ���һ��С���ۺ�һ��������
LONG
	);

	set("exits", ([
		"east" : __DIR__"pubu",
	]));

	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "tongdao" ) return 0;

	if ( me->query("family/master_name") != "һ�ƴ�ʦ") return 0;

	if ( is_wanted(me)) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	message_vision("$Nһë�������һ��ֱ��ɽ�ϵĿ��ͨ����\n", me);
	me->move(__DIR__"hetang");
	tell_room(environment(me), me->name() + "��ͨ�������˹�����\n", ({ me }));
	return 1;
}
