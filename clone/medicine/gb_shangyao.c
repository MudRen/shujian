//  gaibang-shangyao by dubei

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_fu", "fu");
}

void create()
{
        set_name("ؤ����ҩ", ({"gaibang shangyao", "shangyao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������۵�ؤ����ҩ������˵��Ч׿����\n");
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
        if ((int)this_player()->query("eff_qi") ==
            (int)this_player()->query("max_qi"))
                return notify_fail("������û�ˣ�Ϲ��ʲ��ҩ��\n");
        
        else {
                me->receive_curing("qi", 10000);
                message_vision("$N����һ����ҩ�����Ƽ�������ࡣ\n", this_player());
                me->start_busy(1);
                destruct(this_object());
                return 1;
        }
}

