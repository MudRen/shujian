// Room: /u/qingyun/jyzj/xiepo1.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"ѩɽб��"NOR);
	set("long", @LONG
���ֽ��ŵأ�����ѩɽб�£�һ��һ������������֮����ȥ�������ͱڱ�
�ͼ��������϶����ѩ�����ǻ����ޱȣ�һ��С�ľͻỬ����
LONG	);

	set("outdoors", "����ɽ");
	set("no_clean_up", 0);
	
	setup();
}

void init()
{
	add_action("do_climb", ({"climb", "pa"}));
}

int do_climb(string arg)
{
	object me = this_player();
        if(me->is_busy() || me->is_fighting())
              return notify_fail("����æ���أ�\n");
	if (arg == "east") {
		message("vision", me->name() + "����̫������ĵط���ȥ��\n", environment(me), ({me}));
		write("�������ѩɽб����ȥ��\n");
		me->move(__DIR__"xiepo2");
                me->start_busy(1);
		message("vision", me->name() + "���˹�����\n", environment(me), ({me}));
		return 1;
	}
	if (arg == "west") {
		message_vision("$N�����ߵ�������ȥ��\n", me);
		me->move(__DIR__"songshu");
                me->start_busy(1);
		message("vision", me->name() + "��ѩɽб�����˹�����С�������������������\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}
