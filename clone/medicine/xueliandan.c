// xueliandan.c ѩ����

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "fu");
}

void create()
{
	set_name("ѩ����", ({"xuelian dan", "xueliandan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����Ƶ�ѩ������ɢ����һ�ɵ��������㣬���Ǵ�����ѩ����������ȡ������\n");
		set("value", 2000);
		set("no_drop", "�������������뿪�㡣\n");
	}

	set("xueshan",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query_skill_mapped("force") != "longxiang-boruo" )
	{
		me->add("max_jingli", -10);
		message_vision(HIR "$N����һ��ѩ������ֻ���������ɬ����ͷ�������������̣�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("neili_drug" ) > 0 )
	{
		me->add("eff_jingli", -1);
		message_vision(HIR "$N����һ��ѩ������ֻ����ζ����������񷴶�������ǰ��ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		me->add("eff_jingli", 1);
		message_vision(HIG "$N����һ��ѩ������ֻ������������һ������������Ƣ������Ϊ֮һ��!\n" NOR, me);
	}

	me->apply_condition("neili_drug", 15);
	
	destruct(this_object());
	return 1;
}

