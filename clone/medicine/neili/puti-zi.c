// puti-zi.c ������

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"puti zi", "zi"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("unique", 1);
		set("drug", 1);
		set("treasure", 1);
		set("long", "����һ�ž�Ө����������ӣ�������ɽ������ǰ����ϡ�ޱȣ�\n"+
			    "������������֮ʵ�����ܻ��ٽ٣���ǧ�֣������ͬ�١�\n");
		set("value", 5000);
	}
}

int do_eat(string arg)
{
	int force_limit, neili_limit, improve;
	object me = this_player();

	force_limit = me->query_skill("force")* 10 + 20* me->query("age") + me->query("combat_exp") /1000;
	neili_limit = me->query("max_neili");

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if(query("owner") != me->query("id"))
		return notify_fail("��������Ӻ�������õ��İɣ�\n");

	if (me->query("neili") < me->query("max_neili"))
		return notify_fail("������̫�٣����³��ܲ��������ӵĹ�Ч��\n");

	if (me->query_condition("medicine" ) > 0) {
		me->add("max_neili", -20);
		message_vision(HIR"$N����һ�������ӣ�ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n"NOR, me);
		log_file("quest/neili",sprintf("%-18s��ʳ%s��ȥ������ʮ�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",name()), me);
	}
	else if (neili_limit < force_limit) {
		if (random(10) > 5) {
			improve = 10 + random(10);
			message_vision(HIY "$N����һ�������ӣ���Ȼ��ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥�š���\n" NOR, me);
			me->unconcious();
			me->apply_condition("medicine", 180);
		}
		else {
			improve = 1 + random(2);
			me->set("neili", 0);
			message_vision(HIY "$N����һ�������ӣ���Ȼ��ֻ��һ�ɺƵ�������ֱ�嶥�š���\n" NOR, me);
			me->apply_condition("medicine", 60);
		}
		me->add("max_neili", improve);
		log_file("quest/neili",sprintf("%-18s����%s��������%s�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",name(), chinese_number(improve)), me);
	} else {
		message_vision(HIY "$N����������Ϊ�Ѿ����˼��ޣ�����һ�������ӡ�\n" NOR, me);
		me->unconcious();
	}
	destruct(this_object());
	return 1;
}
