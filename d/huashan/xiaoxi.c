// Room: /d/huashan/xiaoxi.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",  HIW "СϪ" NOR );
	set("long", @LONG
�����Ƿ��µ�һ��СϪ��ÿ���꼾��ʱ�������ˮ���ͺܼ��������ʱ
��ֻ�ܿ�����ˮ��ˢ��һ���.
LONG
);
	set("exits", ([ /* sizeof() == 1 */
                "northeast" : __DIR__"shanlu2",
	]));

	set("no_clean_up", 0);

	set("outdoors", "��ɽ" );
	set("coor/x",70);
  set("coor/y",0);
   set("coor/z",60);
   setup();
}

void init()
{
//         add_action("do_tiao", "tiao");
}

int do_tiao(string arg)
{
        object me = this_player();
	if (arg != "xiaoxi")
                return notify_fail("��Ҫ����������\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
	if ((int)me->query("max_neili") < 401)
		return notify_fail("�㳢��������СϪ��ȴ�����Լ�������ȥ��\n");
	message_vision("$Nһ��������԰�����ȥ��\n", me);
	tell_object(me, "������СϪ�������Լ�������һ��ɽ���¡�\n");

        me->receive_damage("jing", 30);
	me->move(__DIR__"shanya");
	message_vision("$N��СϪ�Ǳ����˹�����\n", me);

        me->start_busy(random(2));
        return 1;
}

