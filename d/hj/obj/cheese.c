#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_drink", "drink");
}

void create()
{
	set_name(HIW "����" NOR, ({ "ru lao", "cheese"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������������ң��������ҾͲ����������ԭ��\n");
		set("unit", "��");
		set("value",5000);
             }
}

int do_drink(string arg)
{
	object me = this_player();
	object ob = this_object();

	if (!arg || !id(arg))
		return notify_fail("�����ʲô��\n");
	if( me->query("water") < me->max_water_capacity()
	 && me->query("food") < me->max_food_capacity()){
		message_vision(HIG "$N��µ��µ�غ���һ��" + ob->name()+ HIG "��Ĩ��Ĩ�졣\n"NOR,me);
		me->add("food", 100);
		me->add("water", 100);
		destruct(ob);
		return 1;
	}
}
