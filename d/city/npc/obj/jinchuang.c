// jinchuang.c ��ҩ

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name("��ҩ", ({"jinchuang yao", "jin", "jinchuang", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 3000);
                set("unit", "Щ");
                set("long", "����������ʿ�ر��Ľ�ҩ��\n");
                set("base_value", 5000);
                set("base_unit", "��");
                set("base_weight", 30);
        }
        set_amount(1);
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
    if (this_player()->is_busy() || this_player()->is_fighting())
        return notify_fail("����æ���ء�\n");
        if ((int)this_player()->query("eff_qi") == 
            (int)this_player()->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
        else {
                this_player()->receive_curing("qi", 50);
                message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player());
                add_amount(-1);
        this_player()->start_busy(1);
                return 1;
        }
}
