//  gaibang-bcd by hunthu

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_fu", "fu");
}

void create()
{
        set_name("�ٲݵ�", ({"bai caodan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Űٲݵ�����˵��ؤ����������߳��භ�����ƵĽⶾҩƷ��\n");
                set("value", 100);
                set("no_drop", 1);
                set("no_give",1);
                set("no_put",1);
        }
        setup();
}

int do_fu(string arg)
{
        object me;
        me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if( me->is_fighting() )
                return notify_fail("ս���в��ܳ�ҩ���ˣ�\n");
        if ((int)this_player()->query("eff_jing") ==
            (int)this_player()->query("max_jing"))
                return notify_fail("������û�ˣ�Ϲ��ʲ��ҩ��\n");
        
        else {
if ((int)me->query_condition("snake_poison") > 0||(int)me->query_condition("scorpion_poison ")>0) 
       {
           me->apply_condition("snake_poison",0);
           me->apply_condition("scorpion_poison", 0);
         }
        me->receive_curing("jing", 500);
       message_vision("$N����һ�Űٲݵ���\n", this_player());
        me->start_busy(2);
                destruct(this_object());
                return 1;
        }
}
