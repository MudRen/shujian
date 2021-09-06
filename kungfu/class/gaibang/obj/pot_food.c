// item: fire.c
 
inherit ITEM;

void create()
{
	set_name("ʳ��", ({ "food" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("no_get", 1);
		set("no_give", 1);
		set("no_steal", 1);
		set("no_drop", 1);
	}
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	if (!id(arg))
		return 0;

	write("����������Ϊ�˺��߹�������Ū�ģ��������ˣ������ˡ�\n");
	return 1;
}
