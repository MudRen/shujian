// /d/dzd/obj/hulu.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��«",({"hulu"}));
	set_weight(100);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ��װ�ű��ϵĺ�«����«������һ���˪,���������ǲ��ϴӺ�«��ð������
��˵��ߵĲϱ������Է�(putout),Ҳ������(putin)Ŷ��\n");
		set("value",200000);
		set("unit","��");
             set("dzd",1);
	}
	setup();		
}

void init()
{
	add_action("do_putout","putout");
	add_action("do_putin","putin");
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int do_putout(string arg)
{
	object target,ob;
	object me = this_player();
	
	if( environment(me)->query("no_fight"))
	 	return notify_fail("���ﲻ׼ս����\n");
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	
	//if(!arg || arg!= "bingcan")
		//return notify_fail("�����ʲô��\n");
	
	if( !arg ) 
		target = offensive_target(me);
	else  target = present(arg, environment(me));
	
	if(!target)
		return notify_fail("�����˭ʹ�ñ��ϣ�\n");	
	if(!target->is_character()) return notify_fail("���ϸ�Ц����\n");
	//if( !target ) target = offensive_target(me);
	//if(!target || !target->is_character() || !me->is_fighting(target))
		//return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�ã�\n");
	if(!living(target))
		return notify_fail("���ǻ���ô��\n");	
	if(me->query_temp("dzd_quest/bingcan_used"))
		return notify_fail("������ʹ�ñ��ϣ�\n");
	message_vision(HIW"$N��������º�«������«һ�����Ѱѱ��Ϸ��˳�����\n"NOR,me,target);
	me->set_temp("dzd_quest/bingcan_used",1);
	ob = new(__DIR__"bingcan");
	ob->move(environment(me));
	ob->set_leader(me);
	ob->kill_ob(target);
	return 1;
}

int do_putin(string arg)
{
	object me = this_player();
	object ob;
	//if(!arg || arg != "bingcan")
		//return notify_fail("������ʲô������\n");
	ob = present("bingcan",environment(me));
	if(!ob) ob = find_object("bingcan");
	if(!ob && !me->query_temp("dzd_quest/bingcan_used")) 
		return notify_fail("��Ź�����ô��\n");
	else if(!ob) 
		return notify_fail("��ı����Ѿ����ˣ�\n");	
	message_vision(HIW"$N�ڵ�����ҩ�ﻭ��һ����ɫ��ԲȦ������«����������ԲȦ����«��һ����Ȧ�ڣ��ǲ϶��͵�һ�����������«��\n"NOR,me);
	me->delete_temp("dzd_quest/bingcan_used");
	destruct(ob);
	return 1;
}