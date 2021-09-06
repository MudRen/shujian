// /u/jpei/thd/obj/liuren-wan.c ���ɼ����� 

#include <ansi.h>

inherit ITEM;

void setup() {}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("���ɼ�����", ({"liuren wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ŵ���ɫ����ҩ������͸�����㡣\n");
		set("value", 100);
                set("no_drop", 1);
                set("no_get", 1);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query("family/family_name") != "�һ���" )
	{
	/*	if (me->add("max_neili", -10) < 0)
			me->set("max_neili", 0);
		message_vision(HIR "$N����һ�����ɼ����裬ֻ���øγ���ϣ�ԭ������һ�ż�ҩ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
	*/
		message_vision(HIR "�����ڹ���������ҩ�㲻�����ԣ�\n" NOR, me);
		return 1;
	}
	if ( (int)me->query("max_neili" ) < 400) {
		message_vision(HIR "������������ҩ�����к����ˡ�\n" NOR, me);
		return 1;
	}
	

	if ( (int)me->query_condition("medicine" ) > 0 )
	{
		me->add("max_neili", -10);
			me->set("neili", 0);
		message_vision(HIR "$N����һ�����ɼ����裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ҩ��ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
            else if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
        { 
                message_vision(HIR "$N����һ�����ɼ����裬ֻ����ҩ��ƽƽ����������������Ϊ�ˣ�\n" NOR, me);
        }
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N����һ�����ɼ����裬ֻ�������������ĵ���������ΪС�н��棡\n" NOR, me);
		me->apply_condition("medicine", 60);
	}
	destruct(this_object());
	return 1;
}
