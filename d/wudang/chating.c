// /d/wudang/chating.c ��ͤ

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
��������·���Ա߶����Ĳ�ͤ��������裬��������Զ���ķ羰��������
ν͵�ø��������У�û�б�����õ�Ъ�ŷ����ˡ�ͤ�������Ⱥ������Χ����
��(table)����������(chair)�ϣ��е����ģ��еĳ������ò���ң���ڡ�
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"wdroad8",
	]));

	set("resource/water", 1);
	set("drink_msg", "$N������裬������ζ��Ʒ�˼��ڡ�\n");

	set("item_desc", ([
		"table" : "һ�ŵ��ŵ���ľС�����������ˮ���̺��������ߡ�\n",
		"chair" : "һֻ������ƵĿ��Σ�����ȥҡҡ�λΣ������Ү��\n",
	]));

	set("outdoors", "�䵱ɽ");
	set("objects",([
		FOOD_D("mitao") : 1,
		FOOD_D("cha") : 1,
		__DIR__"npc/taohua" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_tap(string arg)
{
	object me;
	object cui;

	if (!arg || (arg != "desk" && arg != "table"))
		return notify_fail("��Ҫ��ʲô��\n");

	me = this_player();

	if( !objectp(cui = present("tao hua", environment(me)))) {
		write("�����������ӣ�ȴ����û�����㡣��ͻȻ�о�һ��ʧ�䡣\n");
		return 1;
	}

	if( !me->query_temp("marks/sit")) {
		write("�����������ӣ����е��˶���ͷ�Ȼ�ؿ����㣬��ͻȻ�о��Լ����޴���\n");
		return 1;
	}

	if( me->query_temp("marks/served")){
		message_vision("�һ����ͷ��ض�$N˵�����ո����Ϲ�������ž�Ҫ�����Ǹ���Ͱ���ǰ���\n", me);
		return 1;
	}

	if (present("mi tao", environment(me)) && present("dawan cha", environment(me))){
		write("���Ȱ������еĳ��˰ɣ�\n");
		return 1;
	}

	message_vision("$N��������ǰ��������������棬�һ�һ˦С�裬�����к���\n", me);

	cui->serve_tea(me) ;

	me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
	call_out("delete_served", 10, me);

	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}

int do_sit(string arg)
{
	if ( !arg || (arg != "chair") )
		return notify_fail("��Ҫ��ʲô���棿\n");

	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ����˸���λ�ˡ�\n");

        this_player()->set_temp("marks/sit", 1);
	return notify_fail("�����˸���λ���£������ϲ衣\n");
}

int valid_leave(object me, string dir)
{
        if((dir == "northwest")){
	 me->delete_temp("marks/sit");
	 me->delete_temp("tea_cup");
	 return ::valid_leave(me, dir);
}
}
