//Modify by Looklove@SJ 2000/10/06

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("�񶴺�ʯ��", ({"heishi dan", "dan","heishi"}));
   	if (clonep())
      		set_default_object(__FILE__);
   	else {
      	set("unit", "��");
      	set("long","����һ������ɵĽⶾ��ҩ��\n");
      	set("value", 5000);
   	}
   	setup();
}

int init()
{
   	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

   	if(!id(arg))
       		return notify_fail("��Ҫ��ʲô��\n");

   	message_vision("$N����һ��" + name() + "��\n", me);
   	if ((int)me->query_condition("hb_poison") < 5) {
      		me->apply_condition("hb_poison", 1);
   	}
	else {
		me->apply_condition("hb_poison", -5);
	}
   	destruct(this_object());
   	return 1;
}
