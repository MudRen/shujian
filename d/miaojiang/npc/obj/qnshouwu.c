// qiannianshouwu.c ǧ�������
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
	set_name(YEL"ǧ������"NOR, ({"qiannian shouwu", "shouwu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ǧ�����ڣ���״�������壬��˵ǧ�귽��һ�á�\n");
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
        me->add("max_neili", -20);
		message_vision(
			HIR "$N����һ��ǧ�����ڣ�ֻ���ڸ������ǰ���ڡ�\n"
			"ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, this_player());
	} else {
	     message_vision(
	   HIG "$N����һ��ǧ�����ڣ�һ�������Ե���ӿ���߾����磬��������!\n" NOR, me);
	me->apply_condition("medicine", 30);
        me->reincarnate();
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        me->set("jingli", me->query("eff_jingli"));
        me->set("neili", me->query("max_neili"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
        me->add("max_neili",10);
      
	}
	destruct(this_object());
	return 1;
}
