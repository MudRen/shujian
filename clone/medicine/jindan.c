
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("��", ({"jindan", "jin"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����½�ͽ�ر������˵���\n");
		set("value", 20000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�ý𵤡�\n");
	else {
		this_player()->receive_curing("qi", 200);
		message_vision("$N����һ���𵤣���ɫ�������ö��ˡ�\n", this_player());
		destruct(this_object());
		return 1;
	}
}

