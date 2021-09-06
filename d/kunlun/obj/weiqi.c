// weiqi.c Χ��

inherit ITEM;

void create()
{
	set_name("Χ��", ({ "wei qi", "weiqi", "qi", "go" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"����һ��Χ�壬�����ô������ƣ������������ɡ�\n");
		set("value", 5000);
		set("no_sell", 1);
		set("material", "steel");
	}
}

void init()
{
	if (environment() == this_player())
		add_action("do_play", "play");
}

int do_play(string arg)
{
	object me = this_player();
	object env;

	if (!arg || !id(arg))
		return notify_fail("������ʲô��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	env = environment(me);
	if (env->query("sleep_room"))
		return notify_fail("���Ҳ�����������Ӱ�������Ϣ��\n");

	if (env->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (env->query("pending"))
		return notify_fail("�˵ز���������\n");

	if (env->query("no_fight"))
		return notify_fail("���ﲻ׼ս����Ҳ��׼������\n");

	if (me->query("qi") < 20 || me->query("jing") < 30)
		return notify_fail("��̫���ˣ���������Ϣ��ѡ�\n");
	if (random(10) > 7) {
		message_vision("$N�ڳ�һ�����̣����о�Χ�壬ȴ�ܾ����ķ����ң�������������\n", me);
		me->receive_damage("jing", random(10));
		me->receive_damage("qi", random(10));
		return 1;
	}
	me->receive_damage("jing", 20);
	me->receive_damage("qi", 5);
//        me->add_busy(!random(3));
	if (me->query_skill("art",1) < 120)
		me->improve_skill("art", me->query_int()/4 + me->query_skill("art", 1)/10);
	write("��ڳ�һ�����̣��о���Χ������ֻ������ƽ���ͣ��ܿ�ͷ·��붨�ˡ�\n");
	tell_room(env,
		"ֻ��" + me->name() +"���˴󷢣��������������������·��Ų��ʣ�һ��Ī������ģ����\n", me
	);
	return 1;
}
