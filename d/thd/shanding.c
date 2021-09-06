// Room: /u/numa/thd/shanding.c
// Modified by Numa 19980903

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"�Խ��嶥"NOR);
        set("long",@LONG
��������Խ���ķ嶥��������ʯ����������֮����Ҫ���ȥ����
���Ѷ�֮����������������ȥ�������һ���һ�����ࡣ
LONG
        );
        set("no_clean_up", 0);
        set("outdoors","�һ���");

        setup();
}

void init()
{
	add_action("do_jump","jump");
	add_action("do_jump","yue");
}

int do_jump(string arg)
{
	object me = this_player();
	
	if (me->is_fighting() || me->is_busy())
		return notify_fail("����æ���أ�\n");
	if (arg!="ya") return 0;
	if(me->query_encumbrance() * 100 / me->query_max_encumbrance() > 20)
	        return notify_fail("�㸺�ع��࣬��������Ծ��ȥ��\n");
        if (me->query_skill("dodge") < 100)
                return notify_fail("�㳢��Ծ��԰��Ķ��£���ȴ�����Լ��޷�Ծ��ȥ��\n");
        tell_room(environment(me), HIC+me->name()+"���˽�������Ʒ���漴һ�С��沨������Ծ��԰����£����ȵ����ڶ��档\n" NOR, ({me}));
        write("����Ϣһ�ᣬ����Ծ�����¡�\n");
        me->move(__DIR__"shanya");
        return 1;
}

	