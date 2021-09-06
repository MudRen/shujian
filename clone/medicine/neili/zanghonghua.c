//  zanghonghua

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
        set_name(HIR"�غ컨"NOR, ({"zanghong hua","zanghong","hua"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("drug", 1);
                set("long", "����һ�����������ظ�ԭ�ϼ��亱���Ĳغ컨��\n"
                           "��˵�غ컨����һ�������仨������������Ч������\n");
                set("no_sell", 1);
                set("value", 1000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        int force_limit, neili_limit,improve;
        force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
        neili_limit = me->query("max_neili");

        if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
 
        if(this_object()->query("owner") != me->query("id"))
		return notify_fail("���غ컨��������õ��İɣ�\n");

        if ((int)me->query("eff_qi")==(int)me->query("max_qi"))
		return notify_fail("�����ھ���������Ѫ��ӯ������Ҫ��ҩ�\n");

        if(me->query_condition("medicine")){
		improve = 10 + random(5);
		message_vision(HIR "$N���²غ컨��ֻ��������ת��ԭ����ҩ��Ƶ�����Ʒ������ء�\n" NOR, me);
		me->set("eff_qi", 1);
		me->add("max_neili",- improve);
		log_file("quest/neili",sprintf("%-18s��ʳ%s��ȥ����%s�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",this_object()->name(),chinese_number(improve)), me);
		me->add_busy(2);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	if ( neili_limit <= force_limit ) {
		improve = random(2);
		me->add("max_neili", improve);
		log_file("quest/neili",sprintf("%-18s����%s��������%s�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",this_object()->name(),chinese_number(improve)), me);
	}
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	message_vision(HIW"$N���²غ컨��ֻ������������������ˬ���������ƴ�Ϊ��ת��\n"+
			"�����ƺ�Ҳ����ǰǿ����ࡣ\n"NOR, this_player());
	me->apply_condition("medicine", 60);
	me->add_busy(1);
	destruct(this_object());
	return 1;
}
