// update by Lklv for new nanyang city 2001.10.11

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ǰ����һ��ʮ�ֶ��͵Ķ��£��վ��쳣��������Խ(pa)��������ƺӲ�Զ��
�ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���������ȥ��ʹ������������
ˮʱ�Ŀ�����
LONG
	);
	set("outdoors", "�ƺ�");
	set("exits", ([
		"north" : __DIR__"yidao4",
	]));
	setup();
}

void init()
{
	add_action("do_pa", ({ "climb", "pa" }));
}

int do_pa(string arg)
{
	object me;
	object *inv;

	me = this_player();

	if ( !arg ) return 0;
	if (arg != "ya" && arg!="up")
		return notify_fail("��Ҫ����������\n");

	if (!living(me)) return 0;

	inv = filter_array(deep_inventory(me), (: userp :));
	if (sizeof(inv) || !me->query_temp("gb_job2")) {
		message_vision("$N�������꣬�е��޷�����ȥ��ˤ��������\n", me);
		me->set_temp("last_damage_from", "�Ӷ����ϵ�����ˤ");
		me->receive_wound("qi", 50+random(50));
		return 1;
	}
	if (me->query_skill("dodge",1) < 80){
		message_vision(HIR"$N��Ҫ����ɽ���������Ṧ������ˤ��������\n"NOR, me);
		me->set_temp("last_damage_from", "�Ӷ����ϵ�����ˤ");
		me->receive_wound("qi", 50+random(50));
		return 1;
	}
	message_vision("$N��סͻ������ʯ��ʩչ�Ṧ������ȥ��\n", me);
	me->move("/d/gb/yading");
	tell_room(environment(me), me->name() + "����������������\n", ({ me }));
	return 1;
}
