#include <ansi.h>

inherit ITEM;

int do_eat(string);


void init()
{                                  
  add_action("do_eat", "eat");

}

void create()
{
        set_name(HIR"��"HIY"��"HIB"��"HIW"'"HIG"��"NOR, ({"mms"}));
	set_weight(20);
	if (clonep())
	    set_default_object(__FILE__);
	else {
	set("unit", "��");
	set("long", "һ��������ɫ��"+this_object()->name()+"�ɿ���������������𡫡� ����һ�����֣�����Է����\n");
	
	set("value", 300000);
	set("food_supply", 150);
	set("food_remaining",1);

        set("no_put",1);
        set("no_sell",1);
        
        set("remaining", 4);
	}


	setup();
}

int do_eat(string arg)
{       
        object me = this_player();
        if (!living(me)) return notify_fail("�뵱����\n");
        if (!id(arg)) return 0;
        if( me->query("food") > me->max_food_capacity())
             return notify_fail("���Ѿ��Ա��ˣ�ʲôҲ�Բ����ˡ�\n");
        set("value", 0);
        me->add("food", (int)query("food_supply"));
        add("remaining", -1);

        if ( this_object()->query("remaining")){
            message_vision("$N����΢Ц�����۵�ҧ��һ��"+this_object()->query("name")+"��ֻ�����㻬���ˡ�\n",me);
        }
        else{ 
            message_vision("$Nҧ�������һ��"+this_object()->query("name")+"�����ϸ��ֳ������΢Ц��\n",me);
            destruct(this_object());
        }
        return 1;
}
