#include <ansi.h>
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name("��ҩ", ({"jie yao", "jieyao", }));   
	set("no_drop",1);
	set("no_get",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ҩ�衣\n");
		set("value", 10000);     
                        set("medicine", "drug");
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	me->set("jingli", 0);
	me->set("jing", 0);
	me->set("neili", 0);
	message_vision(HIR "$N����һ�Ų�֪���ֵ�ҩ�裬ֻ����ͷ�ؽ��ᣬҡҡ������\n" NOR, me);
	destruct(this_object());
	return 1;
}
