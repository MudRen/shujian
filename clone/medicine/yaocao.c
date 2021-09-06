// yaocao.c
// By jpei
// Modify By River@SJ

inherit COMBINED_ITEM;

void create()
{
        set_name("ҩ��", ({ "yao cao", "yao", "cao" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("long", "����һЩҩ�ݣ���������˵����ðɡ�\n");
                set("value", 30);
                set("material", "grass");
                set("base_value", 30);
                set("base_unit", "��");
                set("base_weight", 100);
        }
        set_amount(1);
}

void init()
{
        add_action("do_eat", ({"eat", "chi"}));
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("�����ʲô��\n");

        if (me->query("eff_qi") ==  me->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ��ҩ�ݡ�\n");
        else {
                me->receive_curing("qi", 20);
                message_vision("$N����һ��ҩ�ݣ���ɫ����������һЩ��\n", me);
                add_amount(-1);
              if(random(9)==1) me->start_busy(1);
                return 1;
        }
}

