// youcha.c  ���Ͳ�

inherit ITEM;

void init();

void create()
{
	set_name("���Ͳ�", ({"suyou cha","tea","cha"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ͣ����̺Ͳ�ש�����Ͳ裬�����ص������ز�ʳƷ��\n");
		set("unit", "��");
		set("value", 80);
	        set("drink_supply", 10);
		set("food_supply", 10);
	        set("remaining", 3);
	}
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me = this_player();

	if (!id(arg)) return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");
	if (me->query("water") >= me->max_water_capacity())
		return notify_fail("���Ѿ��ȵ�̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
	me->add("water", query("drink_supply"));
	if (me->query("food") < me->max_food_capacity())
		me->add("food", query("food_supply"));
	if (add("remaining", -1))
		message_vision("$N����һ�����Ͳ����һ��ڣ������˿���������ĵ��˵�ͷ��\n", me);
	else { 
		message_vision("$N������ʣ�µ����Ͳ�һ��������˳�������������Ĩ��Ĩ��\n", me);
		destruct(this_object());
	}
	return 1;
}
