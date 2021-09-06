// Room: /d/huashan/jinshe/biding.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ڶ�");
	set("long", @LONG
�������ͱڵĶ��ˣ����ܹ�ʯ��ᾣ��Ա��м��ð���(shu)֦Ҷïʢ��һЩ
Ұ��(shuteng)���Ƶ����ɡ�����������Լ�и���Ѩ(dong)�����������վã���
ס���ڵ������Ѿ����䡣
LONG                           
        );
	set("teng_count", 3);
	set("teng_time",time());
	set("outdoors", "��ɽ");
	set("exits", ([
		"down" : "/d/huashan/husun",
	]));
	set("item_desc", ([
		"shu" : "һ��֦Ҷ��ï�Ĵ������ִֵ����ɣ�����ȥ���ι̡�\n",
		"shuteng": "һЩ��֪����Ұ�٣��������ƵĴ�����\n",
		"dong": "����ڳ����ģ�ʲ��Ҳ�����壬��֪�ж��\n",
	]));

	setup();
}

void init()
{
	add_action("do_zhe", ({"break","zhe"}));
	add_action("do_bo", ({"stick","bo"}));
	add_action("do_bian", ({"weave","bian"}));
	add_action("do_use", ({"dian","dian"}));
	add_action("do_pa", ({ "climb", "pa" }));
	add_action("do_bang", ({ "tie", "chan" }));
}

int do_zhe(string arg)
{
	object teng;
	object me; 
	me=this_player();

	if ( !arg || arg != "shuteng" )
		return notify_fail("��Ҫ��ʲ�᣿\n");

	if((time()-query("teng_time"))>900) {
		set("teng_count", 3);
		set("teng_time",time());
	}
	if (query("teng_count") > 0) {
		message_vision("$N�����������۶���һЩ���١�\n", me);
		add("teng_count", -1);
		teng=new(__DIR__"obj/shuteng");
		teng->move(me);
	}
	else
		message_vision("�����Ѿ���$N�۹��ˡ�\n", me);
	return 1;
}
 
int do_bian(string arg)  
{
	object kuang;
	object me;
	me = this_player();
	if (!( present("shuteng", this_player())))
		return notify_fail("��Ҫ��ʲ��ࣿ\n");
	if ( !arg || arg != "kuang" )
		return notify_fail("��Ҫ��ʲô��\n");
	 
	message_vision("$N�����µ����ٱ����һ������������һЩϸ��š��������\n", me);
	kuang=new(__DIR__"obj/kuang");
	kuang->move(me);
	return 1;
}

int do_use(string arg)
{ 
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if( arg=="fire" ) {
		write("\n���ȼ�˻��ۣ������붴��һ��Զ���ıڲ���ʮ��������׶(zhui)��\n"+
			"����һ��������һ���亹��\n");
		me->set_temp("mark/zhui", 1);
		return 1;
	}
}

int do_bo(string arg)
{
	object me;
	me = this_player();

	if ( !arg || arg != "zhui" )
		return notify_fail("��Ҫ��ʲ�᣿\n");

	if (!me->query_temp("mark/zhui"))
		return notify_fail("��Ҫ��ʲ�᣿\n");

	if (!( present("xiao shuzhi", this_player())))
		return notify_fail("���������֣���Ȼ�޷�������\n");

	message_vision("$NС����������֦�Ѷ��ڵĽ���׶�������ˡ�\n", me);
	me->delete_temp("mark/zhui"); 
	me->set_temp("mark/bo",1);
	return 1;
}

int do_pa(string arg)
{
	object me;
	me=this_player();

	if ( !arg || arg != "down" )
		return notify_fail("��Ҫȥ���ģ�\n");

	if (!( present("kuang", this_player())))
		return notify_fail("�������������ȥ��\n");

	if (!me->query_temp("mark/bang"))
		return notify_fail("�������������ȥ������\n");

	message_vision("$N�����������棬սս������ʧ�ڶ��ڡ�\n", me);

	if (!(int)me->query_temp("mark/bo")) {
		message_vision(RED"�ڰ�֮�У�$NͻȻ�о�����һ���ʹ����ǰһ�ڣ�������ȥ��\n"NOR, me);
		message_vision(HIR"$N���һ�����Ӷ��ڵ�����ȥ��\n"NOR, me);
		me->set_temp("last_damage_from", "��ײ����ˤ");
		me->die();
		return 1;
	}
	me->move(__DIR__"dxue");
	tell_room(environment(me), me->name() + "������������������\n", ({ me }));
	me->delete_temp("mark/bo");
	return 1;
}

int do_bang(string arg)
{      
	object me;
	me = this_player();

	if (!( present("kuang", this_player())))
		return notify_fail("��Ҫ��ʲô��\n");

	if ( !arg || arg != "shu" )
		return notify_fail("�����ʲô��\n");

	if (me->query_temp("mark/bang"))
		return notify_fail("���Ѿ������ˡ�\n");

	message_vision("$N�����ٽ������������ϡ�\n", me);
	me->set_temp("mark/bang",1);
	return 1;
}
