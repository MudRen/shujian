// sl_dan.c

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
        set_name(HIG "������" NOR, ({"shenglong dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "����������ڵ������˿��ܻ��ж���\n");
		set("unit", "��");
		set("medicine", "drug");
		//set("no_get", 1);
//                set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();
	if (!living(me)) return notify_fail("�뵱����\n");
	if (!id(arg)) return 0;
	message_vision(HIG "$N����һ��"
	+this_object()->query("name")+
	HIG "����ʱ����ȫ���ȣ�һ������ֱ��ͷ���������嶥������\n"
	NOR,me);
	//"/adm/daemons/emoted"->do_emote(me,"taste");
        if(random(10)>4)
            me->set("eff_jingli", me->query("eff_jingli")+100);
        else
                     me->set("eff_jingli", me->query("eff_jingli")-200); 
             if(!random(3))
                     me->apply_condition("sl_poison", random(5)*5+5);        
       destruct(this_object());
	return 1;
}
