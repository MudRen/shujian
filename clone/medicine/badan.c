// /clone/drug/badan.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");

}

void create()
{
        set_name(RED"�����˵�"NOR, ({"ba dan", "badan", "dan"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}

int do_eat(string arg)
{
       
        object me = this_player();
        if (!living(me)) return notify_fail("�뵱����\n");
        if (!id(arg)) return 0;
        
	if( me->query_condition("medicine")>0 )	{
		message_vision(HIG"$N����һ�������˵�����Ϊ�Ե�̫Ƶ����û����ʲôЧ����\n", me);
		me->apply_condition("medicine",30);
		destruct(this_object());
		return 1;
	}
	
        message_vision(HIG"\n$N��������ĳ���һ�������˵������ڰ������˻�����\n\n"NOR,me);
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("eff_qi"));
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("eff_jing"));
	me->apply_condition("medicine",90);
        destruct(this_object());
        return 1;
}
