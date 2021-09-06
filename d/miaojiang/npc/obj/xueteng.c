//  xueteng ѩ��

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(WHT"ѩ��"NOR, ({"xue teng", "teng"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ν�������ѩ�٣�ʮ�ֺ�����\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if (me->query_condition("medicine")) {
        	me->set("qi", 0);
        	me->set("jing", 0);

		message_vision(
			HIR "$N����һ��ѩ�٣�ֻ���û������������׹����ѡ�\n"
			"ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, this_player());
	} else {
	        me->set("eff_qi", me->query("max_qi"));
	        me->set("qi", me->query("max_qi"));
	        me->set("eff_jing", me->query("max_jing"));
	        me->set("jing", me->query("max_jing"));
	        me->set("neili", me->query("max_neili"));
  
		message_vision(
			WHT "$N����һ��ѩ�٣�ֻ�����߽����ͨ��������\n" NOR, me);
		me->apply_condition("medicine", 30);
	}
	destruct(this_object());
	return 1;
}
