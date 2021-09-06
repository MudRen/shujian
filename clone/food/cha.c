// xiangcha.c ���
// By Marz 03/29/96
// LKLV@SJ 2001.9.28

inherit ITEM;

void create()
{
	set_name("���",({"xiang cha", "tea", "cha", "xiangcha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ȳ裬���Ƶ�ð������������\n");
		set("unit", "��");
		set("remaining", 2);
		set("drink_supply", 25);
	}

	setup();
}

void init()
{
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
}

int do_drink(string arg)
{

        object ob, me;
        int recover, jing, e_jing, m_jing;

        me = this_player();
        ob = this_object();
	recover = 5;

	if( !ob->id(arg) ) return 0;
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( me->query("water") >= me->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
	me->add("water", (int)query("drink_supply"));
	jing = (int)me->query("jing");
	e_jing = (int)me->query("eff_jing");
	m_jing = (int)me->query("max_jing");

	if (jing < e_jing ){
		if ( (jing + recover) >= e_jing ){
			me->set("jing", e_jing);
		} else {
			me->set("jing", jing+recover);
		}
	}

	if( me->is_fighting() ) me->start_busy(2);

	add("remaining", -1);
	if ( query("remaining") ){
		message_vision("$N������裬������ζ��Ʒ�˼��ڡ�\n"+
		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", me);
	} else {
		message_vision("$N�����С������ʣ�µ����һ��������\n"+
		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", me);
		destruct(ob);
	}
	return 1;
}
