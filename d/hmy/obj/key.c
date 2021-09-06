// key.c ����Կ��
// Created by Numa 19991023

#include <ansi.h>
inherit ITEM;
#include "hmy_def.c"
#define JAIL_GATE "/d/hmy/jail_gate"

void create()
{
	set_name(HIB"��Կ��"NOR,({"hei yaoshi", "yaoshi", "key"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ����ͭ�Ƴɵĺ�ɫԿ�ס�\n");
		set("material", "steel");
		set("unit", "��");
		set("value", 2000);
		set("unique", 1);
		set("treasure", 1);
		set("no_give",1);
		set("no_get",1);
	}
	setup();
}

/*
void init()
{
	object ob = this_player();
	object me = this_object();
	
	if (present("yao shi",ob)
	&&  me->query_temp("owner") == ob->query("id"))
		add_action("do_unlock",({"unlock", "kai"}));
}

int do_unlock(string arg)
{
	object ob = this_player();
//	object me = this_object();
	object room,here,obj,another,npc1;

	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (arg != "men" && arg != "��")
		return notify_fail("��Ҫ��ʲô��\n");

	here = environment(ob);
	room = load_object(__HMY__"jail");
	if (base_name(here) != JAIL_GATE)
		return notify_fail("�������û����ѽ��\n");
	another = present(ob->query_temp("hostage/partner"),here);
	if (!another)
		return notify_fail("���ͬ�黹û��������һ�����ɡ�\n");
	if (!(ob->query_temp("hostage/ready_3")
	  || another->query_temp("hostage/ready_3")))
	  	return notify_fail("���ǵ��������û������أ�\n");
	message_vision(HIG"\n$N���ݵ��ó�Կ�ף�ֻ����ž����һ�����������ˡ�\n"NOR, ob);
	
	obj = present(ob->query_temp("hostage/hostage_i"),room);
	if (!obj)
		return notify_fail("�ף������أ�\n");
	if (userp(obj)) {
		tell_object(obj,HIB"\n������������γ�ȥʱ�����š�������һ�����ˡ�\n"NOR);
		obj->move(here);
		tell_room(here,obj->name() + "��"HIB"����"NOR"�����˳�����\n",({obj}));
		tell_object(obj,"�㼱æ���˳�ȥ���㷢��ԭ����"+ ob->name() +"��"+ another->name() +"һ���������ġ�\n");
		tell_object(obj,"�㱻"+ another->name() +"���˳�ȥ��\n");
		obj->move(obj->query_temp("hostage/where"));
		obj->delete_temp("hostage/where");
	}
	else {
		obj->move(here);
		tell_room(here,obj->name() + "��"HIB"����"NOR"�����˳�����\n",({obj}));
		message_vision("$nһ��������һ���������ܵĲ�����Ӱ����",obj);
		obj->move(obj->query_temp("hostage/where"));
		obj->delete_temp("hostage/where");
		obj->reincarnate();
	}
	tell_room(here,HIR"\n������ʱ����������ܹ�����ͤ���˹���������������֮��Ťͷ���ܣ�\n"NOR);
	message_vision(HIY"\n$N��ͷ˵��������ȥ׷�������ǿ�ջ�غϡ���˵��ʹҴ�ææ��ȥ׷�����ܵ�����ͤ��\n"NOR,ob);
	ob->delete_temp("hostage/ready_3");
	ob->set_temp("hostage/job_3",1);
	ob->apply_condition("hostage3",60 + random(20));
	npc1 = new(__HMY__"npc/yang");
	npc1->set_temp("target2",ob->query("id"));
	npc1->move(__HMY__"xiaohuayuan");
	ob->move(__HMY__"xiaohuayuan");
	message_vision(HIY"\n$N����$n��е�����"+ RANK_D->query_rude(npc1) +"�������ܣ�վס����\n"NOR, ob, npc1);
	message_vision(HIR"$n��æ�ղ�������$N��Ц��������Ȼ�㲻�ϷŹ��ң�Ҳ�ݹ������飡��\n"NOR, ob, npc1);
	message_vision(HIY"\n$N����׼�������뿪���������������ԶԶ�������˼����ˣ�\n"NOR, another);
	message_vision(HIR"ԭ����ħ�������ϸϵ��ˡ�\n"NOR, another);
	another->delete_temp("hostage/ready_3",);
	another->set_temp("hostage/job_3", 2);
	
    	another->apply_condition("hostage3",60 + random(20));
	npc1 = new(__HMY__"npc/killer5");
	npc1->set_temp("target",another->query("id"));
	npc1->move(here);
	npc1 = new(__HMY__"npc/killer6");
	npc1->set_temp("target",another->query("id"));
	npc1->move(here);
	npc1 = new(__HMY__"npc/killer7");
	npc1->set_temp("target",another->query("id"));
	npc1->move(here);
	return 1;
}
*/