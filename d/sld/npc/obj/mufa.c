//mufa.c
//wzfeng
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("ľ��",({"mufa"}));
	set_weight(50000);
	set("no_get",1);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",50);
		set("long","����һ����ľͷ��������������Сľ����������(zuo)����Ư����\n");
	}
	setup();
}

void init()
{
	add_action("do_zuo","zuo");
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
	if(arg=="mufa")
		return 1;
	else
		return 0;	
}

int do_zuo(string arg)
{
	object me,mf;

	if( !arg || arg=="" ) return 0;
	if(arg==("mufa")) {
		if(!objectp(mf=find_object(__DIR__"mu_fa1")))
			mf=load_object(__DIR__"mu_fa1");
		if(mf->query_temp("curstatus",1)=="run") {
			if(!objectp(mf=find_object(__DIR__"mu_fa2")))
				mf=load_object(__DIR__"mu_fa2");
			if(mf->query_temp("curstatus",1)=="run") {
				if(!objectp(mf=find_object(__DIR__"mu_fa3")))
					mf=load_object(__DIR__"mu_fa3");
				if(mf->query_temp("curstatus",1)=="run")
					return notify_fail("ľ����û����ʵ�����������ɡ�\n");
			}
		}
		me=this_player();
		message_vision("ֻ��$N����һԾ��������ľ���ϡ�\n" NOR,me);
		message_vision("ֻ��һ�󺣷紵����ľ���ѻ�����Ʈȥ��\n" NOR,me);
		tell_room(environment(me), me->name() + "����ľ������Ʈȥ��\n");
//		mf=new(__DIR__"mu_fa");
//		if(userp(me) && !wizardp(me)) me->set("invisibility",  1);
		me->move(mf);
		mf->set_temp("curstatus","run");
		destruct(this_object());
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}
