// yujiwan.c ����
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
	set_name(HIW"����"NOR, ({"yuji wan", "yuji", "wan"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_give", 1);
		set("long", "����һ�ž�Ө���������裬�������Է���(eat)��\n");
		set("value", 10000);
		set("drug", 1);
		set("no_sell", 1);
		set("no_get",1);
		set("no_drop",1);
		set("medicine", "drug");
		set("make/drug", 1);
	}
	setup();
}
 
int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	if( query("owner") != me->query("id"))
		return notify_fail("������ô�õ��������ģ�\n");

	message_vision(HIY"$N����һ��"+query("name")+HIY+"����ʱ���þ���������������������ʮ�㡣\n"NOR,me);
	me->add("max_neili", 100);
	me->add("max_jingli", 100);
	me->setup();
	destruct(this_object());
	return 1;
}
