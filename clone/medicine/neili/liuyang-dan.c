//wuchangdan.c
#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"����������"NOR, ({"zhengqi dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIR"����һ�������Ѫ����������������ҩ��Ժ��ɮ�������ƣ�\n"+
			       "�⺮�����ƾ�֢����������֮����\n"NOR);
		set("no_get",1);
		set("no_give",1);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit,improve;
	object me = this_player();
	force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
	neili_limit = me->query("max_neili");

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if (query("owner") != me->query("id"))       
		return notify_fail("���������������������õ��İɣ�\n");

	if (me->query_condition("medicine") > 0 ){
		message_vision(HIR "$N����һ��������������ֻ��������ֱ��ͷ����ԭ����$P��ǰ������ҩҩ������\n" NOR, me);
		me->set("jing",me->query("max_jing")/10);
		me->set("eff_jing",me->query("max_jing")/10);
		me->set("qi",me->query("max_qi")/10);
		me->set("eff_qi",me->query("max_qi")/10);
		me->add("max_neili",-10);
		log_file("quest/neili",sprintf("%-18s��ʳ%s��ȥ����ʮ�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")", this_object()->name()), me);
	}
	else {  
		if( neili_limit < force_limit) {
			message_vision(HIR"$N����һ����������������ʱһ������ֱ͸�ĵף�\n"NOR,me);
			improve = random(2);
			me->apply_condition("medicine", 30 * improve);
			me->add("max_neili", improve);
			log_file("quest/neili",sprintf("%-18s����%s��������%s�㡣\n",
				me->name(1)+"("+capitalize(me->query("id"))+")",name(),chinese_number(improve)), me);
		}
		else {
			me->set("jing",me->query("max_jing"));
			me->set("eff_jing",me->query("max_jing"));
			me->set("qi",me->query("max_qi"));
			me->set("eff_qi",me->query("max_qi"));
			me->set("neili", me->query("max_neili") * 2);
			me->clear_conditions_by_type("poison");
		  	me->apply_condition("medicine", 60);
		}
	}
	destruct(this_object());
	return 1;
}
