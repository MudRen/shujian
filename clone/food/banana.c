// �㽶

#include <ansi.h>
inherit ITEM;

void create()
{
	seteuid(getuid());
	set_name(HIY"�㽶"NOR, ({ "xiang jiao","jiao","banana" }) );
	set("long", "һֻ�ƳȳȵĴ��㽶��\n");
	set("value", 2000);
	set("unit", "ֻ");
	set_weight(10);
	setup();
}

void init()
{
	add_action("do_bo","bo");
	add_action("do_eat","chi");
	add_action("do_eat","eat");
}

int do_bo(string arg)
{
	object me = this_player();
	object ob = this_object();

	if( !arg || arg!="xiangjiao" && arg!="xiang jiao" && arg!="banana" )
		return notify_fail("��Ҫ��ʲô��\n");

	if( ob->query_temp("banana") ) return notify_fail("�㽶�Ѿ�������Ƥ�ˡ�\n");

	me->set_temp("banana", 1);
	ob->set_temp("banana", 1);

	me->set_temp("banana2", 1);
	new(__DIR__"banana2")->move(me);
	message_vision(HIW"$N������һֻ�㽶��\n"NOR, me);
	me->delete_temp("banana2");

        return 1;
}

int do_eat(string arg)
{
	object me = this_player();
	object ob = this_object();

	if( !arg || arg!="xiangjiao" && arg!="xiang jiao" && arg!="banana" )
		return notify_fail("��Ҫ��ʲô��\n");

	if( !ob->query_temp("banana") ) return notify_fail("������Ƥ����ô��\n");

	me->delete_temp("banana");
	me->add("food",40);
	message_vision(HIY"$N����һֻ�㽶��\n"NOR, me);
	destruct(this_object());

        return 1;
}
