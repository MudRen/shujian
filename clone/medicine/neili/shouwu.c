// shouwu.c ������
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
        set_name(GRN"������"NOR, ({"heshou wu", "wu"}));
	set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ó������εĺ����ڡ�\n");
                set("value", 10000);
                set("drug", 1);
                set("no_sell", 1);
                set("medicine", "drug");
                set("make/drug", 1);
        }
        setup();
}
 
int do_eat(string arg)
{
        object me = this_player();
        int force_limit, neili_limit,improve;
        if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

        force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
        neili_limit = me->query("max_neili");
  
        if(this_object()->query("owner") != me->query("id"))
		return notify_fail("��ú����ں�������õ��İɣ�\n");

        if (me->query_condition("medicine")){
		me->add("max_neili", -10);
		message_vision(HIR"$N����һ������ڣ�ֻ�������ǣ���Ѫ��ӿ��\n"
				"ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, this_player());
		log_file("quest/neili",sprintf("%-18s��ʳ%s��ȥ����ʮ�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",this_object()->name()), me);
		me->unconcious();
        }
	else if ( neili_limit <= force_limit ){
		improve = random(2);
		me->add("max_neili", improve);
		message_vision(HIG"$N����һ�ú����ڣ���ʱ�����ȫ������˻��� !\n" NOR, me);
		me->apply_condition("medicine", me->query_condition("medicine")+ 60);
		log_file("quest/neili",sprintf("%-18s����%s��������%s�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",this_object()->name(),chinese_number(improve)), me);
        }
        else {
		message_vision(HIY "$N����������Ϊ�Ѿ����˼��ޣ�����һ�ź����ڡ�\n" NOR, me);
		me->unconcious();
	}
        destruct(this_object());
        return 1;
}
