// play.c

#include <ansi.h>;

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env;

	if (!objectp(present("wei qi", me))
	&& !objectp(present("gu zheng", me)))
		return 0;

	if (!arg ) return notify_fail("��Ҫ��ʲô��\n");

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

	if (arg == "gu zheng" && present("gu zheng", me)) {
		if (me->query("qi") < 20 || me->query("jing") < 30)
			return notify_fail("��̫���ˣ���������Ϣ��ɡ�\n");
		if (random(10) > 5) {
			message_vision("$N�ڳ�һ�Ź��ݣ����������˼���ֻ���������������£��������Ǻš�\n", me);
			me->receive_damage("jing", random(10));
			me->receive_damage("qi", random(10));
			return 1;
		}
		me->receive_damage("jing", 20);
		me->receive_damage("qi", 5);
		me->add_busy(random(2));
		if (me->query_skill("art", 1) < 120)
			me->improve_skill("art", me->query_int()/4 + me->query_skill("art", 1)/10);
		write("��ڳ�һ�Ź��ݣ����˵��ң�������������ֻ������������������������ࡣ\n");
		tell_room(env, "ֻ��" + me->name() + "���˴󷢣�����������������ֻ����ʱ�����������Įƽɳ����\n"
				"ʱ��С����ˮ�������˼ҡ�����������������ʱ��������ࡣ\n", me);
		return 1;
	}
	if (present("wei qi", me) && arg == "wei qi") {
		if (me->query("qi") < 20 || me->query("jing") < 30)
			return notify_fail("��̫���ˣ���������Ϣ��ѡ�\n");
		if (random(10) > 5) {
			message_vision("$N�ڳ�һ�����̣����о�Χ�壬ȴ�ܾ����ķ����ң�������������\n", me);
			me->receive_damage("jing", random(10));
			me->receive_damage("qi", random(10));
			return 1;
		}
		me->receive_damage("jing", 20);
		me->receive_damage("qi", 5);
		me->add_busy(random(2));
		if (me->query_skill("art",1) < 120)
			me->improve_skill("art", me->query_int()/4 + me->query_skill("art", 1)/10);
		write("��ڳ�һ�����̣��о���Χ������ֻ������ƽ���ͣ��ܿ�ͷ·��붨�ˡ�\n");
		tell_room(env, "ֻ��" + me->name() +"���˴󷢣��������������������·��Ų��ʣ�һ��Ī������ģ����\n", me);
		return 1;
	}
	return notify_fail("������ʲô��\n");
}
