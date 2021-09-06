// tea1.c

#include <ansi.h>

inherit ITEM;

void init()
{
     add_action("do_drink", "drink");
}


void create()
{
	set_name(HIW "��ë��" NOR, ({"mao feng", "cha", "tea"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ǻ�����ɽ��֮�����������Ƶļ�Ʒ�衣\n");
		set("unit", "��");
		set("value", 10000);
	}
}

int do_drink(string arg)
{
	object me = this_player();
	if (!living(me)) return notify_fail("�뵱����\n");
	if (!id(arg)) return 0;
	message_vision(HIG "$NƷ��һ��"
	+this_object()->query("name")+
	HIG "����ʱ���þ���Ϊ֮һ��\n"
	NOR,me);
        me->set("jing", me->query("max_jing"));
        me->set("water", me->max_water_capacity());
       	destruct(this_object());
	return 1;
}
