// jiuhuawan.c ������
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"songyang dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ų������۵�СԲ��\n");
		set("value", 100);
		set("no_drop", 1);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if ((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ��ҩ�\n");
        
	if (this_player()->is_busy() || this_player()->is_fighting())
		return notify_fail("����æ���ء�\n");

	if (me->query_condition("medicine"))
		return notify_fail("��շ�����ҩ��������档\n");

	if (me->query_skill_mapped("force") != "hanbing-zhenqi") {
		me->add("max_neili", -10);
		message_vision(HIR "$N����һ����������ֻ���õ������絶�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	else {
		me->receive_curing("qi", me->query_skill("hanbing-zhenqi", 1));
		me->add_condition("medicine", 5);
		message_vision("$N����һ�������������ƴ�Ϊ��ת��\n", this_player());
	}
	destruct(this_object());
	return 1;
}
