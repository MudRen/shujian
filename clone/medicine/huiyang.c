#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("����������", ({"wulong gao", "huiyang", "wulong", "gao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Щ");
		set("heal_up", 1);
		set("long","����һ���ɲ����Ƴɵ��������ҩ��\n");
		set("value", 3000);
		set("base_value", 3000);
		set("base_unit", "��");
		set("base_weight", 500);
	}
	set_amount(1);
}

void init()
{
	add_action("do_eat", "fu");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (me->query("eff_qi") >= me->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�����������ࡣ\n");
	me->receive_curing("qi", 100+random(100));
	message_vision("$N����һ�ݻ��������࣬��ɫ�������ö��ˡ�\n", me);
	me->start_busy(1);
	add_amount(-1);
	return 1;
}
