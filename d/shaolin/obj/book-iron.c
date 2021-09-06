// book3.c

#include <armor.h>

//inherit ITEM;
inherit HANDS;

void create()
{
    set_name("���޺�", ({ "tie luohan", "luohan", "shu", "book" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�������޺�\n"
			"����һ�������������޺����������һ�׹��������ķ��š�\n");
		set("value", 500);
		set("material", "steel");
                set("treasure", 1);
		set("skill", ([
			"name":	"parry",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}

void init()
{
	if( this_player() == environment() )
		add_action("do_yanxi", "yanxi");
}

int do_yanxi(string arg)
{
	object me = this_player();

	if ( arg != "iron luohan" && arg != "luohan" )
	return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_fighting()&&(int)me->query_skill("parry",1)<30)
        message_vision("$N�������£������޺�ȫ�޶�����\n",me);
        if ( me->is_fighting() 
	&& (int)me->query_skill("parry", 1) >= 30 
	&& (int)me->query_skill("parry", 1) <= 100 )
	{
                if((int)me->query("jing")<20)
                  {
                    me->unconcious();
                    return 0;
                  }      
                me->receive_damage("jing", 20);
		me->improve_skill("parry", me->query("int"));
		message_vision("$Nշת��Ų�����������޺��Ļ������������̻���������\n", me);
		return 1;
	}
       	if( me->is_fighting() &&(int)me->query_skill("parry",1)>100)
      {   
         message_vision("$N����̫��̫�٣����޺������������ٶȣ�ֹͣ����ת��\n",me);
        return 1;
       }       
	return 0;
}
