// heiyu.c
#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void init()
{
        add_action("do_eat", "fu");
}

void create()
{
        set_name(HIW "���������" NOR, ({"heiyu duanxugao", "gao", "heiyu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("unique", 3);
                set("heiyu", 3);
                set("long", "һ������ʥҩ��������࣬�������ʵ��ѩ�ס�\n");
                set("value", 100000);
        }
        setup();
}

int do_eat(string arg)
{
      object me, ob;
      
       me=this_player();
       ob=this_object();

      if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
     if (this_player()->is_busy() || this_player()->is_fighting())
        return notify_fail("����æ���ء�\n");
        if ((int)this_player()->query("eff_qi") == 
            (int)this_player()->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ�ú�������ࡣ\n");

      if( ob->query("heiyu") > 0){      
                me->receive_curing("qi", me->query("max_qi"));
                me->receive_curing("jing", me->query("max_jing")/2);
                me->add("neili",me->query("max_neili")/10);
                me->set("food", me->max_food_capacity());
                me->set("water", me->max_water_capacity());
                message_vision(HIW"$N�Ѻ��������Ϳ���˿��ϣ�ֻ�����ƴ�Ϊ��ת��\n"NOR, me);
                ob->add("heiyu", -1);   
                this_player()->start_busy(3);      
                return 1;
             }
        
       if(ob->query("heiyu") < 1){
           write("���еĺ���������Ѿ���ʣ�޼��ˡ�\n");
           ob->set("long", "һ������ʢ����ʥҩ����������ľ�С�\n");
           ob->set("value", 5000);
           return 1;
             }
}
