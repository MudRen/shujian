// Room: /d/mr/jushi.c
// this is made by beyond
// update 1997.6.20
// rebuild by Lklv 2001.9.20

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"����"NOR);
	set ("long",@long
���Ǵ��ƽʱ������ӵĵط����������һ�߹��ݣ�һ���������������
��(qiju)���۸��ӣ����˰�˼������⡣���ҵĶ����Ǵ�����������һ�����ȣ�
������һ���᷿��
long);
	set("item_desc",([
		"qiju" : "һ��ɱ���ѽ��ѷ׵��壬��֪���Ƿ����о�һ�£�\n",
	]));

	set("exits",([
		"east" : __DIR__"dating",
		"west" : __DIR__"cl6-0",
		"south" : __DIR__"xiangfang3",
	]));

	setup();
}

void init()
{
	add_action("do_yanjiu", "kan");
	add_action("do_yanjiu", "yanjiu");
}

int do_yanjiu(string arg)
{
	object me;

	me = this_player();
	if ( !living(this_player()) || !arg || arg != "qiju" )
		return 0;
	if ( me->is_busy() && !wizardp(me) ) return notify_fail(HIG"��������˼���С�\n"NOR);
	if ((int)me->query_int() < 50 || me->query_temp("qiju_over")){
		me->start_busy(1);
		return notify_fail("��Ͼ���˼�۲���֣���һ��о�ͷ�����ǡ�\n");
	}
	if ((int)me->query("jing") < 60 ) {
		write("��̫���ˣ��Ѿ�û���������ж�����ˣ�\n");
		me->set_temp("qiju_over",1);
		return 1;
	}
	me->receive_damage("jing", 50);
	me->receive_wound("jing", 20);
	message_vision("$N��ר���о����ϵġ���֡���\n", me);

	if ((int)me->query_skill("art", 1) < 31){
		if ( random(4) == 0 )
		me->improve_skill("art", me->query("int"));
		if ( random(2) == 0 )
		write("����������ϵġ���֡���ĥ��һ�ض����ƺ��������á�\n");
		me->start_busy(1);
		return 1;
	}
	write("���������о���һ�ᣬ�������Ѿ��о�͸����������˵�Ѻ��������ˡ�\n");
	return 1;
}
