// shouwu.c ������
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
	set_name(GRN"������"NOR, ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ó������εĺ����ڡ�\n");
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
        me->add("max_neili", -5);
		message_vision(
			HIR "$N����һ������ڣ�ֻ�������ǣ���Ѫ��ӿ��\n"
			"ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, this_player());
	} else {
	     me->add("max_neili", 1);
               
		message_vision(
			HIG "$N����һ�ú����ڣ���ʱ�����ȫ������˻��� !\n" NOR, me);
		me->apply_condition("medicine", 30);
	}
	destruct(this_object());
	return 1;
}
