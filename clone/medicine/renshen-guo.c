// rsg.c

#include <ansi.h>

inherit ITEM;

void init()
{
	if (environment() == this_player()) {
		add_action("do_eat", "eat");
		add_action("do_eat", "chi");
	}
}

void create()
{
	set_name(HIG "�˲ι�" NOR, ({"renshen guo","guo"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"��˽������Թ��Ķ�������������һ���װ����ֵ�С�к���\n"
		"�лָ����������ӹ���������Ч����\n");
		set("value", 5000000);
		set("unit", "ö");
		set("no_drop", 1);
                set("unique", 2);
        	set("treasure", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg)) return 0;
	message_vision(HIG "$N����һö"
	+name()+
	HIG "����ʱ���þ�����ʢ���������ٸе��ɿʼ�����\n"
	NOR,me);
	"/adm/daemons/emoted"->do_emote(me,"taste");
	me->reincarnate();
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", me->query("max_jing"));
	if (me->query("jingli") < me->query("eff_jingli"))
		me->set("jingli", me->query("eff_jingli"));
 
	destruct(this_object());
	return 1;
}
