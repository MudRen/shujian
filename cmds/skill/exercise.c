// exercise.c
// snowman@SJ 15/12/1998
// modify by snowman@SJ 01/03/2000
// By Spiderii@ty ����ת��Ч��
#include <skill.h>
#include <ansi.h>
int exercising(object me);
int halt_exercise(object me);

int main(object me, string arg)
{
	string force;
	mapping msg;
	int exercise_cost, max;
	object where;

	max = (int)me->query("max_neili");
	seteuid(getuid());
	where = environment(me);

	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (where->query("pending"))
		return notify_fail("�˵ز���������\n");

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if (me->is_exert())
		return notify_fail("���ʩ�ù��ڹ����������ϴ�����\n");

	if( me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");

	if (where->query("sleep_room"))
		return notify_fail("���Ҳ��ܴ�������Ӱ�������Ϣ��\n");

	if (where->query("no_fight"))
		return notify_fail("���ﲻ׼ս����Ҳ��׼������\n");

	if (me->query_condition("no_force"))
		return notify_fail("��е�������Ϣ�Ҵܣ��޷�����������\n");

	if (!(force = me->query_skill_mapped("force")))
		return notify_fail("��������� enable ѡ����Ҫ�õ������ڹ���\n");

	if (!arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("��Ҫ��������������\n");

	if ((me->query("max_qi")+me->query_temp("apply/qi")) > 1000
	&& exercise_cost < (me->query("max_qi")+me->query_temp("apply/qi"))/5)
		return notify_fail("��������Ҫ"+chinese_number((me->query("max_qi")+me->query_temp("apply/qi"))/5)+"�������������\n");

	if (exercise_cost < 10)
		return notify_fail("��������Ҫʮ�������������\n");

	if (me->query("qi") < exercise_cost )
		return notify_fail("��û����ô�������������Ϣ����ȫ������\n");

	if (me->query("jing") * 100 / (me->query("max_jing")+me->query_temp("apply/jing")) < 70 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");

	if (me->query("neili") > (me->query("max_neili")+me->query_temp("apply/neili"))*2)
		return notify_fail("������ȫ������������޷��ټ��������ˡ�\n");

	msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["start_my_msg"]))
		write("�������������ù���һ����Ϣ��ʼ������������\n");
	else
		write(msg["start_my_msg"]);

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
/*
	if (!msg || undefinedp(msg["start_other_msg"]))
		tell_room(environment(me),
			me->name() + "��ϥ���£���ʼ�˹�������\n", ({ me }));
	else
		tell_room(environment(me),
			msg["start_other_msg"], ({ me }));
*/
	me->start_busy((: exercising :), (:halt_exercise:));
	me->start_exert(1);
	return 1;
}

int exercising(object me)
{
	string force;
	mapping msg;
	int exercise_cost = me->query_temp("exercise_cost");
	int neili_gain = 1 + me->query_skill("force") / 15
		* (1 + (int)me->query_skill("force") / 60);
	int max;

//	if( me->query("age") > 20 )
//	neili_gain *= 20 / me->query("age");
	if (me->query("age") < 20)
		neili_gain += neili_gain * (20 - me->query("age")) / 10;
	// by spiderii@ty    ����ת�����޺����������ؿ��������������ٶ�Զʤ��ǰ��\n"NOR);   
	          
       if(me->query_condition("gifts") > 1 ){
		  neili_gain = neili_gain * (1+ me->query("gifts/��ӱ")+ me->query_temp("gifts/��ӱ"));
                   }
	
	neili_gain = neili_gain * 3;
	neili_gain = neili_gain / 2;//�ӿ�dazuo tuna�ٶ� by ciwei
	if (neili_gain > exercise_cost)
		neili_gain = exercise_cost;

	me->receive_damage("qi", neili_gain, "�߻���ħ");
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);

	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);
	if (exercise_cost > 0) {
		if (msg && !undefinedp(msg["exec_my_msg"]))
			tell_object(me, msg["exec_my_msg"]);
//		if (!random(3) && msg && !undefinedp(msg["exec_other_msg"]))
//			tell_room(environment(me), msg["exec_other_msg"], me);
		return 1;
	}

	me->delete_temp("pending/exercise");
	if (!msg || undefinedp(msg["end_my_msg"]))
		tell_object(me, "���˹���ϣ�վ��������\n");
	else
		tell_object(me, msg["end_my_msg"]);
/*
	if (!msg || undefinedp(msg["end_other_msg"]))
		tell_room(environment(me),
			me->name()+"�˹���ϣ�վ��������\n", ({me}));
	else
		tell_room(environment(me),
			msg["end_other_msg"], ({me}));
*/
	neili_gain = 0;
	max = (me->query_skill("force")-me->query_temp("apply/force")) * 8 + me->query("combat_exp") / 1000;
	while (me->query("neili") >= (me->query("max_neili")+me->query_temp("apply/neili")) * 2) {
		if (me->query("max_neili") >= max) {
			tell_object(me, "���������Ϊ�Ѿ��޷��������������ˡ�\n");
			me->set("neili", (me->query("max_neili")+me->query_temp("apply/neili")) * 2);
			break;
		}
		if(me->query("env/����"))
		{
			tell_object(me,"���������Ϊ�Ѿ��ﵽԲ��֮����\n");
			me->set("neili", (me->query("max_neili")+me->query_temp("apply/neili")) * 2);
			break;			
		}
		me->add("neili", 2-me->add("max_neili", 1)-me->query_temp("apply/neili"));
		neili_gain++;
	}
	if (neili_gain)
		tell_object(me, "���������Ϊ������"+chinese_number(neili_gain)+"�㣡\n");
	return 0;
}

int halt_exercise(object me)
{
	string force;
	mapping msg;

	if (me->query("neili") > (me->query("max_neili")+me->query_temp("apply/neili")) * 2)
		me->set("neili", (me->query("max_neili")+me->query_temp("apply/neili")) * 2);
	me->delete_temp("pending/exercise");
	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["halt_msg"]))
		message_vision(
			"$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
	else
		message_vision(msg["halt_msg"], me);

	if (me->is_fighting())
		me->add_busy(2);
	else
		me->add_busy(random(2));
	notify_fail("");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : exercise|dazuo [<�ķѡ���������> ���벻���� 10]

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������
HELP
	);
	return 1;
}
