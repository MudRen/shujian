// guzheng.c ����

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIG"����"NOR, ({ "gu zheng", "zheng", "qin" }));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIG"����һ������ʮ�ֿ����Ĺ��ݣ������ɫ�����ʼ��á�\n"NOR);
		set("value", 5000);
		set("no_sell", 1);
		set("material", "wood");
	}
	init_sword(30);
	setup();
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
		message_vision("$N�ڳ�һ�Ź��ݣ����������˼���ֻ���������������£��������Ǻš�\n", me);
		me->receive_damage("jing", random(10));
		me->receive_damage("qi", random(10));
		return 1;
	}
	me->receive_damage("jing", 20);
	me->receive_damage("qi", 5);
//        me->add_busy(!random(3));^M
	if (me->query_skill("art",1) < 120)
		me->improve_skill("art", me->query_int()/4 + me->query_skill("art", 1)/10);
	write("��ڳ�һ�Ź��ݣ����˵��ң�������������ֻ������������������������ࡣ\n");
	tell_room(env, "ֻ��" + me->name() + "���˴󷢣�����������������ֻ����ʱ�����������Įƽɳ����\n"
		"ʱ��С����ˮ�������˼ҡ�����������������ʱ��������ࡣ\n", me
	);
	return 1;
}
