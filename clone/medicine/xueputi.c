// xueputi.c Ѫ����

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
	set_name("Ѫ����", ({"xue puti", "xueputi", "puti"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ŵ�˵�е�Ѫ���ᣬ��Ѫ�������ϲ�ժ����û��á�\n");
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
		me->add("max_neili", -10);
		message_vision(HIR "$N����һ��Ѫ���ᣬֻ����������գ���Ѫ��ӿ��ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("neili_drug" ) > 0 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N����һ��Ѫ���ᣬֻ������ɴ��ѣ���Ѫ��ӿ��ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N����һ��Ѫ���ᣬֻ������Ѫ��ӯ�������ĵ���ȫ������Ȼ��� !\n" NOR, me);
	}

	me->apply_condition("neili_drug", 15);
	
	destruct(this_object());
	return 1;
}

