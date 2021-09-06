// by snowman

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"�׶���"NOR, ({"heding hong", "hong", "heding"}));
	set_weight(2000);
	if (clonep()) {
		set_default_object(__FILE__);
    		call_out("dest", 600);
	} else {
		set("unit", "��");
		set("long", RED"����һ�����ʵĺ׶��죬��ɢ��������������\n"NOR);
		set("value", 50000);
	}
	setup();
}

int init()
{
	if (environment() == this_player())
   		add_action("do_eat", "fu"); 
}

int do_eat(string arg)
{
   	object me = this_player();
	int i;

   	if (!id(arg))
       		return notify_fail("��Ҫ��ʲô��\n");

   	message_vision("$N����һ��" + name() + "��\n", me);  
   	tell_object(me, MAG "��о�����һ�ɾ��۴�����˲��ȫ����ȹ��̣�\n" NOR);

	i = me->query("max_qi") + me->query_temp("apply/qi");
   	me->receive_wound("qi", i / 4 + random(i), "��ʳ�綾��");

   	if ((int)me->query_condition("hb_poison") > 1)
		me->apply_condition("hb_poison", 1);
	
   	else if ((int)me->query_condition("cold_poison") > 1)
		me->apply_condition("cold_poison", 1);

	else if( me->query_skill("hamagong", 1)) {
		if( me->query("max_neili") < me->query_skill("force") * 10 + me->query("age")*20 + me->query("combat_exp")/1000 + me->query("query_neili") )
			me->add("max_neili", 2);
		else {
			tell_object(me, "��о�θ�ںö��ˣ�\n");
			if( me->query("food") < me->max_food_capacity() )
				me->add("food", 50+random(100));
		}
	}
   	else me->add_condition("hot_poison", 70); 

   	destruct(this_object());
   	return 1;
}

void dest()
{
	message_vision(HIR "�׶��������ɢ���������ɿ��ˡ�\n"NOR, this_object());
	destruct(this_object());
}
