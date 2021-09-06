// Room: /d/dzd/rukou.c

#include <ansi.h>
inherit __DIR__"dzd_room";

void create()
{
	set("short","ʯ�����");
	set("long",@LONG
���ٲ���Ծ��������һ���������ɽ�����,���µ�ʯͷ���ڳ��걻ˮ��ˢ��Ū��ʪ������
����������濴���ƺ����ɽ���ܴ�һ�����º������ļ�,ˮ�����������
LONG
	);
	set("exits",([
		"northwest" : __DIR__"shidong1",
		"northeast" : __DIR__"shidong3",
		"north" : __DIR__"shidong2",
	]));
	setup();
}

void init()
{
	::init();
	add_action("do_tiao","tiao");
	if(!this_player()->query_temp("dzd_quest/shidong") && interactive(this_player())) {
		
		message_vision(HIY"$NͻȻ�ɹ������ڰ����۾���Ȼ��Ӧ���ˣ�\n"NOR,this_player());
		this_player()->start_busy(3);
		this_player()->set_temp("dzd_quest/shidong","in");
	}
}

int do_tiao(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || arg == "" || arg!="out")
		return notify_fail("�������Ķ�����\n");

	message_vision(HIW"$N�ż��أ������������ȥ!\n"NOR,me);
	me->delete_temp("dzd_quest/shidong");	
	me->move(__DIR__"pubu");
	message_vision(HIW"$N˳�ƶ��£���������ڵ���!\n"NOR,me);
	return 1;
}
