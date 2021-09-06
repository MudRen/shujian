// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ֻ���˴�������Լ�����ʯ�������������ɽ��֮�䣬�������֣�������
������������ƽ��֮�ϣ�����С�����������ô��������ʯ��������ȣ���˵
���ߣ�ֻ��һ��Ҳ���⵨ս�ľ���ʯ����Ȼ�жϣ�ǰ(front)��(back) ����Լ
���߰˳߳���һ��ȱ�ڡ�
LONG
	);
	set("outdoors", "��Դ��");

	setup();
}

void init()
{
	add_action("do_jump", ({ "yue", "jump", "tiao" }));
}

int do_jump(string arg)
{
	object me = this_player();

	if ( ! arg || ( arg != "front" && arg != "back") ) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");

	if ( me->query("neili") < 1000)
		return notify_fail("���������������������Ծ���¿��ܻ���Σ�ա�\n");

	if ( arg == "front") {
		message_vision(HIW"\n$N�����첽���У������߰��ɣ�����һ�ɳ�������Ծ����Խ���˶��¡�\n\n"NOR, me);
		me->move(__DIR__"liang");
		me->add("neili", -1000);
		tell_room(environment(me), me->name() + "�����ʯ����Ծ�˹�����\n", ({ me }));
 		return 1;
 	}
	if ( arg == "back") {
		message_vision(HIW"\n$N�����첽���У������߰��ɣ�����һ�ɳ�������Ծ����Խ���˶��¡�\n\n"NOR, me);
		me->move(__DIR__"liang5");
		me->add("neili", -1000);
		tell_room(environment(me), me->name() + "�����ʯ����Ծ�˹�����\n", ({ me }));
 		return 1;
 	}
}
