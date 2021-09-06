// Room: /u/qingyun/jyzj/xiepo2.c
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
LONG);

	set("outdoors", "����ɽ");
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
	if (arg == "west") {
		message_vision("$N������ѩɽб����ȥ��\n", me);
		me->move(__DIR__"xiepo1");
                me->start_busy(1);
		message("vision",me->name() + "���˹�����\n", environment(me), me);
		return 1;
	}
	if (arg == "east") {
		message("vision", me->name() + "����̫������ĵط���ȥ��\n", environment(me), ({me}));
		write("������Ĵ�ʯ����ȥ��\n");
		me->move(__DIR__"dashibi");
                me->start_busy(1);
		message("vision", me->name() + "���˹�����\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}
