// xionghuangjiu.c
// Lklv modify

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "drink");
	add_action("do_eat", "he");
	add_action("do_eat", "yin");
}

void create()
{
	set_name(HIG "�ۻƾ�" NOR, ({"xionghuangjiu","jiu","skin"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"����һ���ۻƾƣ��������̵������ʱ�غ�(drink)�ģ���˵���Է���ҧ��\n");
		set("unit", "��");
		set("no_get", 1);
		set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();

	if (!living(me)) return notify_fail("�뵱����\n");
	if (!id(arg)) return 0;

	if (me->query("family/family_name") != "������"){
		message_vision(HIG "$N����һ���ۻƾƣ���ʱ���ø���ʹ�絶�ʡ�\n"NOR,me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	if (me->query("xionghuangjiu")){
		message_vision(HIG "$N����һ���ۻƾƣ���ʱ���ø���ʹ�絶�ʡ�\n"NOR,me);
		me->add("max_neili", -5);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	message_vision(HIG "$N����һ���ۻƾƣ���ʱ����ȫ���ȣ�һ�ɾ���ֱ��ͷ����\n"NOR,me);
	me->set("xionghuangjiu",1);
	me->add("max_neili", 1);
	me->start_busy(1);
	destruct(this_object());
	return 1;
}
