// jinchuang.c ��ҩ
inherit COMBINED_ITEM;

void init()
{
	add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
	set_name("����ɢ", ({"yuzhen san", "yuzhen","san"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Щ");
      set("value", 5000);
                set("heal_up", 1);
                set("base_unit", "��");
                set("base_weight", 100);
 		set("long","����һ�ݻ�ɽ�ɵ�����ɢ�������˵�ҩ�\n");
		set("base_value", 5000);
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
		return notify_fail("�����ڲ���Ҫ������ɢ��\n");
	else {
		this_player()->receive_curing("qi", 90);
		message_vision("$N����ɫ������ʼ��ת�ˡ�\n", this_player());
		destruct(this_object());
                        this_player()->start_busy(1);
		return 1;
	}
}

