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
	set_name("������", ({"tianlong dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ž��ɫԲ�����ҩ�裬ɢ��һ�����㣬������ҩ��������\n");
		set("value", 100);
                set("no_drop", 1);
                        set("no_get", 1);
                        set("no_give", 1);
                set("tianlongsi",1);    
                }
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query_skill_mapped("force") != "qiantian-yiyang" )
      {
       if ( me->query_skill_mapped("force") != "kurong-changong" )

	{
	/*
		if (me->add("max_neili", -10) < 0)
			me->set("max_neili", 0);
		message_vision(HIR "$N����һ����������ֻ���øγ���ϣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
	*/
		write("�����ڹ���������ҩ�㻹�ǲ�Ҫ�Եĺã�\n");

		return 1;

	}
            }  

         if ( me->query("max_neili") < 450 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N����һ����������ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else if ( (int)me->query_condition("medicine" ) > 0 )
	{
		            me->add("max_neili", -10);
			me->set("neili", 0);
		message_vision(HIR "$N����һ����������ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}

	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N����һ����������ֻ������������ԴԴ�������鲼��������ȫ������Ȼ��ߣ�\n" NOR, me);
		me->apply_condition("medicine", 60);
	}
	destruct(this_object());
	return 1;
}
