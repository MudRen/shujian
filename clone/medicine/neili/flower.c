// flower.c �黨
// By River 99/05/20
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIM"�黨" NOR, ({"qing hua", "flower", "hua"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�伫Ϊ���޵��黨��\n"+
			"�������ɫ�����ޱȣ���ܽ�ض����㣬��ɽ������ޡ�\n");
		set("unit", "��");
		set("no_drop", 1);
		set("no_get", 1);
		set("no_give",1);    
		set("drug", 1);
		set("material", "plant");
		set("wear_msg", "$N��$n���ڷ����ϡ�\n");
		set("remove_msg", "$N�ӷ�����ժ����$n��\n");
		set("armor_prop/armor", 1);
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
        
        force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
        neili_limit = me->query("max_neili");

        if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIY"$N��"HIM"�黨"HIY"һ����ժ��������У�������𣬷������ۣ���΢������Ȼ�ľ�����\n"NOR,me);

        if(me->query_condition("medicine")){
		me->add("max_neili", -10);
		tell_object(me,HIY"����������㳩�������˼��£�ȴ��һ�ɿ�ɬ��ζ��ֱ����ͷ��\n"NOR);
		log_file("quest/neili",sprintf("%-18s��ʳ%s��ȥ����ʮ�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")", this_object()->name()), me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	if( random(3)!= 0 ) {
		tell_object(me,HIY"����������㳩��ȴ��Ȼ���������ѹ��ޱȣ���ҪŻ�£�ȴ���²�������\n"NOR);
		me->apply_condition("qinghua_poison",60);
		me->apply_condition("medicine",60);
		log_file("quest/neili",sprintf("%-18s���黨�ж���\n",
			me->name(1)+"("+capitalize(me->query("id"))+")" ), me);
		destruct(this_object());
		return 1;
	}
	message_vision(HIY"���Ըп�ζ��Ҫ���³����ƾ����ᣬҪ������ڣ����е��������ʡ�\n"NOR,me);
	improve = 1 + random(2);
	if(!me->query("marry") || neili_limit > force_limit)
		me->set("food",me->max_food_capacity());
	else {
		me->add("max_neili",improve);
		me->set("food",me->max_food_capacity());
		log_file("quest/neili",sprintf("%-18s����%s��������%s�㡣\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",this_object()->name(),chinese_number(improve)), me);
		me->apply_condition("medicine", 60);
	}
	destruct(this_object());
	return 1;
}
