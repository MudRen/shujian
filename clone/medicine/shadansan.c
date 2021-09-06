// /clone/drug/shadansan.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");

}

void create()
{
        set_name(HIY"�赨ɢ"NOR, ({"shadan san", "san"}));
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
        if( me->query_condition("medicine")>0 )
        	return notify_fail("����һ�η�ҩ��ҩ�Ի�û�й��أ�\n");
	message_vision(HIW"\n$N����һ���赨ɢ����ʱ���þ�����ʢ���˿��漣��������ˡ�\n\n"NOR,me);
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("eff_qi"));
        me->set("eff_jingli", me->query("max_jingli"));
        me->set("jingli", me->query("eff_jingli"));
        me->apply_condition("medicine",180);
        destruct(this_object());
        return 1;
}


