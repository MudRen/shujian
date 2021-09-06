// qiannianshouwu.c ǧ�������

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"ǧ������"NOR, ({"qiannian shouwu", "shouwu"}));
	set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ǧ�����ڣ���״�������壬��˵ǧ�귽��һ�á�\n");
                set("unique", 1);
                set("drug", 1);
                set("treasure", 1);
                set("value", 10000);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}
 
int do_eat(string arg)
{
        object me = this_player();
        int force_limit, neili_limit, improve;

        if (!id(arg))
      	    return notify_fail("��Ҫ��ʲô��\n");

       	force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
       	neili_limit = me->query("max_neili");

       	if(this_object()->query("owner") != me->query("id"))
            return notify_fail("���ǧ�����ں�������õ��İɣ�\n");

        if (me->query_condition("medicine")) {
        	me->add("max_neili", -20);
                message_vision(
                        HIR "$N����һ��ǧ�����ڣ�ֻ���ڸ������ǰ���ڡ�\n"
                        "ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, this_player());
                me->apply_condition("medicine", me->query_condition("medicine")+ 60);
                log_file("quest/neili",sprintf("%-18s��ʳ%s��ȥ������ʮ�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")", this_object()->name()), me);
        }
        else if ( neili_limit <= force_limit ){
        	if( random(10) > 5) {
              		improve = 10 + random(10);
              		me->add("max_neili", improve);
              		me->add("neili", improve);
             		message_vision(HIG "$N����һ��ǧ�����ڣ�һ�������Ե���ӿ���߾����磬��������!\n" NOR, me);
              		me->apply_condition("medicine", 180);
                        log_file("quest/neili",sprintf("%-18s����%s��������%s�㡣\n",
				me->name(1)+"("+capitalize(me->query("id"))+")", this_object()->name(),chinese_number(improve)), me);
		}
		else {
			message_vision(HIG "$N����һ��ǧ�����ڣ�һ�������Ե���ӿ���߾����磬��������!\n" NOR, me);
        		me->reincarnate();
        		me->set("qi", me->query("max_qi"));
        		me->set("jing", me->query("max_jing"));
        		me->set("jingli", me->query("eff_jingli"));
        		me->set("neili", me->query("max_neili"));
        		me->set("food", me->max_food_capacity());
        		me->set("water", me->max_water_capacity());
			improve = 1 + random(2);
			me->add("max_neili", improve);
			me->apply_condition("medicine", 60); 
			log_file("quest/neili",sprintf("%-18s����%s��������%s�㡣\n",
				me->name(1)+"("+capitalize(me->query("id"))+")" ,this_object()->name(),chinese_number(improve)), me);
        	}
        }
        else {
                message_vision(HIR"$N����������Ϊ�ѴＫ�ޣ�ǿ�г���һ��ǧ�����ڣ���ʱֻ���ڸ������ǰ���ڡ�\n"NOR, this_player());
       		me->unconcious();
       	}
        destruct(this_object());
        return 1;
}
