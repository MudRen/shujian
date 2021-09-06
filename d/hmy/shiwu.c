// /d/hmy/houhuayen.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "Сʯ��");
	set("long", @LONG
һ�䲢�����۵�Сʯ�ݣ�������ʰ�ĸɸɾ���������һֱ���Ǿ���������
��ɨ�ģ�����ϸһ�����������׵�ǽ����Щ���ڲ�ͬ��
LONG
	);
	set("exits", ([
		"east" :__DIR__"houhuayen",
	]));

	setup();
}

void init()
{
	add_action("do_move", "tui");
	add_action("do_open", "open");
}

int do_move(string arg)
{
	object ob, me = this_player();
	ob = present("hei yaoshi", me);

	if ( ! ob) return 0;

	if ( ! arg || arg != "qiang")
		return notify_fail("��Ҫ��ʲô����\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	message_vision(HIY"\n$N����һ�ƣ���ǽԭ���ǻ�ģ�¶��һ����������������һ�����š�\n\n"NOR, me);
	me->set_temp("shiwu/tui", 1);
	return 1;
}

int do_open(string arg)
{
	object ob, me = this_player();
	ob = present("hei yaoshi", me);

	if ( !me->query_temp("shiwu/tui")) return 0;

	if ( ! ob) 
		return notify_fail("����û��Կ�ף���ʲô����\n");

	if ( ! arg || arg != "men")
		return notify_fail("��Ҫ��ʲô����\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	message_vision(HIY"\n$N�ó���Կ�ף�ֻ�������۵���һ��������������Ӧ�������ˡ�\n\n"NOR, me );
	destruct(ob);
	set("exits/down", __DIR__"dedao");
	me->delete_temp("shiwu");
	remove_call_out("close_passage");
	call_out("close_passage", 10);
	return 1;
}

void close_passage()
{
	if( !query("exits/down") ) return;
	message("vision", "���š����ǡ��������Զ������ˡ�\n", this_object() );
	delete("exits/down");
}
