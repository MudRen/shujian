// Room: /d/emei/yunvfeng.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "��Ů��" NOR);
	set("long", @LONG
���ǹ��Ƹ�ߵ���Ů�壬�嶥��һ���ĳ߼�����С�أ������ĳߣ��ļ���
�ݣ���Ϊ��Ů��ԡ֮������ʱ�ݴ�ʷ��鮣����ڴ˽�é���ӣ������ж�������
��������ʳ�˼��̻�������Ů�·���Ϊ������ʳ�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ 
	  "northdown" : __DIR__"guiyunge",
]));
	set("objects",([
		CLASS_D("emei") + "/fang-bilin" : 1,
]));
	setup();
}

void init()
{
	add_action("do_wash", "wash");
}

int do_wash(string arg)
{
	object me;
	int i;

	me = this_player();
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if( !arg || arg == "" || arg != "face" )
	return notify_fail("��Ҫ��ʲô��\n");

if( (int)me->query_skill("beauty", 1) < 41 )
	return notify_fail("���ڳ���ϴ��������������Ȫˮ�������͸����Ӱ���Լ�Խ��Ư���ˡ�\n");

	if( arg == "face" && (int)me->query_skill("beauty", 1) < 120 && (int)me->query_skill("beauty", 1) ) {
	message_vision("$N�ڳ���ϴ��������������Ȫˮ�������͸����Ӱ���Լ�Խ��Ư���ˡ�\n", me);
	i = me->query("kar");
	me->improve_skill("beauty", random(i) * 4);
	me->receive_damage("jingli", random(i) * 2);
	return 1; }
}
