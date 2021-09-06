// rice.c ���׷�
// cck 17/6/97

#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_drink", "eat");
}

void create()
{
        set_name(YEL"�ɿ���"NOR,({"chocolate" }));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",  HIG"�������˽ڵ�����--�ɿ�����\n"NOR);
                set("unit", "��");
                set("value", 150);
                set("food_supply", 50);
                set("remaining", 3);
        }
}

int do_drink(string arg)
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
