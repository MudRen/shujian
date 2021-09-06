// Room: /d/huashan/shuitan.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�ٲ���");
	set("long",@LONG
��ֻ����ˮ����ڹ�¡�˵�......��ʲôҲ�����塣
LONG );
	set("cant_hubiao", 1);
	set("objects", ([
	__DIR__"npc/eyu" : 1,
	]));
	setup();
}

void init()
{
        add_action("do_qian",({"qian", "swim", "youyong", "you"}));
}

int do_qian(string arg)
{
	object me=this_player();

	if ( !arg || (arg != "down" && arg != "up" ))
		return notify_fail("�����������ˮ��������ȥ!\n");

	if (arg =="down") {
		return notify_fail("���뵱������������ѽ!\n");
	}
        else {
		message_vision("$Nһ���ȣ�������ȥ��\n", me);
		me->receive_damage("jingli", 50-(int)me->query_skill("dodge", 1)/20);
		me->move(__DIR__"pubu");
		tell_room(environment(me), me->name() + "��ˮ��ð��������\n", ({ me }));
		return 1;
	}
	return 1;
}
