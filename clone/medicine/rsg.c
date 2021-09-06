// hhd.c

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "chi");
	add_action("do_eat", "yan");
	add_action("do_eat", "tun");
}

void create()
{
	set_name(HIG "������" NOR, ({"changsheng guo","guo"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�䵱ɽ���ز�, ��ʿ��������Ʒ��\n");
		set("unit", "ö");
		set("no_get", 1);
		set("treasure", 1);
		set("unique", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg)) return 0;
	if ( me->is_busy() || me->is_fighting()) return 0;

	message_vision(HIG "$N����һö"	+this_object()->query("name")+HIG "����ʱ���þ�����ʢ���������ٸе��ɿʼ�����\n"NOR,me);
	"/adm/daemons/emoted"->do_emote(me,"taste");
	me->set("qi", me->query("max_qi"));
	me->set("jing", me->query("max_jing"));
	me->set("jingli", me->query("eff_jingli"));
	me->set("food", me->max_food_capacity());
	me->set("water", me->max_water_capacity());
	destruct(this_object());
	return 1;
}
