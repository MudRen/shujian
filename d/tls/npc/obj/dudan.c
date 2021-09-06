// dan.c

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
	set_name("����", ({"du dan", "du", "dan"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ź�ɫ�ĵ��裬�����ж���\n");
		set("value", 100000);
		set("no_get", 1);
		set("no_drop", 1);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query_skill_mapped("force") == "qiantian-yiyang" )
		return notify_fail("�����������ڹ����ԣ����˷��������Ԫ����\n");
       
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
		return notify_fail("��ճԹ���ҩ�����ڲ��ܳԶ���! \n");

	if ( me->query_skill_mapped("force") == "kurong-changong"){
                me->set("eff_qi", me->query("max_qi"));
                me->add("combat_exp",me->query_skill("kurong-changong")+ random(me->query_skill("kurong-changong")) );
		me->set("food", me->max_food_capacity());
		me->set("water", me->max_water_capacity());
                message_vision(HIG "$N����һ�Ŷ��������þ���һ��������Ϊ�ƺ��������ǡ�\n" NOR,me);
		destruct(this_object());
		return 1;
	}
	else {
		me->add("qi", -200);
		me->add("jing", -100);
                me->set("eff_qi", me->query("max_qi"));
		message_vision(HIR "$N����һ�Ŷ�����ֻ���øγ���ϡ�\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	me->apply_condition("bonze_drug", 60);
	destruct(this_object());
	return 1;
}
