// gshedan.c ������

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
        set_name(MAG"������"NOR, ({"dumang dan", "mangdan", "dan" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������ɫ�ȳ�Բ��\n");
                set("no_drop", 1);                
                set("no_give", 1);
                set("no_sell", 1);
                set("drug", 1);
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
	object me = this_player();
	int force_limit, neili_limit, i,improve;
	force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
	neili_limit = me->query("max_neili");
	i = (me->query("str") + 10) * 10; 

	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	if(this_object()->query("owner") != me->query("id"))       
		return notify_fail("��Ŷ�������������õ��İɣ�\n");

	if ( me->query("max_neili") < 400 
          && me->query("max_neili") > 2){
		me->add("max_neili", -3);
		message_vision(HIR "$N����ҧ��һ��Բ��ֻ��֭Һ�ȼ��༫���ѳ��ޱȣ�ԭ�������������Եֵ�ҩЧ��\n" NOR, me);
		log_file("quest/neili",sprintf("%-18s��ʳ%s��ȥ�������㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",this_object()->name()), me);
	}
	else if ((int)me->query_condition("medicine" )){
		me->add("max_neili", -10);
		message_vision(HIR "$N����ҧ��һ��Բ��ֻ��֭Һ�ȼ��༫���ѳ��ޱȣ�ԭ��Ƶ����ҩ�ݲ��ֵܵ�ҩЧ��\n" NOR, me);
		log_file("quest/neili",sprintf("%-18s��ʳ%s��ȥ����ʮ�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",this_object()->name()), me);
	}
	else {
		if( neili_limit <= force_limit) {
			improve = random(2);
			me->add("max_neili", improve);
			me->apply_condition("medicine", me->query_condition("medicine")+ 60);                
			message_vision(HIG"$N����ҧ��һ�£�Բ����Ƥ�㼴���ѣ���ʱ���ڿ�֭��\n"+
				"������һ�ᣬ�����������������˳���������������ʤƽʱ�� \n" NOR, me);
			log_file("quest/neili",sprintf("%-18s����%s��������%s�㡣\n",
				me->name(1)+"("+capitalize(me->query("id"))+")",this_object()->name(),chinese_number(improve)), me);
		}
		else {
			me->add("food", 200);
			if( me->query("food") >= i)
			me->set("food", i + 50);
			message_vision(HIG"$N����ҧ��һ�£�Բ����Ƥ�㼴���ѣ���ʱ���ڿ�֭��\n"NOR,me);
		}
	}
	destruct(this_object());
	return 1;
}
