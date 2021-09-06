// sheyao.c

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
        set_name(HIG "��ҩ" NOR, ({"sheyao","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "����һ���������߶�����ҩ��\n");
		set("unit", "��");
		set("medicine", "drug");
		//set("no_get", 1);
//                set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();
       int cs;

	if (!living(me)) return notify_fail("�뵱����\n");
	if (!id(arg)) return 0;
	message_vision(HIG "$N����һ��"
	+this_object()->query("name")+
	HIG "����ʱ����ȫ���ȡ�\n"
	NOR,me);
       cs=me->query_condition("snake_poison",1);
       if(cs<10)
                cs=0;
            else
                cs-=100;
       me->apply_condition("snake_poison",cs);
       destruct(this_object());
	return 1;
}
