// train.c ѵ��
// by augx@sj  6/27/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object target;
	int lvl,exp;

	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");

	if( me->query_temp("train/busy") )
		return notify_fail("��ո���ͼѱ����Ұ�ޣ��о���Щƣ�͡�\n");

	if( !arg || !(target=present(arg,environment(me))) )
		return notify_fail("��Ҫѱ��ʲô���\n");

	if( !living(target) )
		return notify_fail("��ֻ��ѱ�����\n");

	if( target->query("race") != "Ұ��"
	 && target->query("race") != "����"
	)
		return notify_fail("��ֻ��ѱ�����\n");

	if( target->query("master") == me->query("id") )
		return notify_fail("���Ѿ�ѱ�����ˡ�\n");

	if( target->query("master") && present(target->query("master"),environment(me)) )
		return notify_fail("�������˾����Աߣ�����ô��������ʰɣ�\n");

	message_vision(CYN"$N��������$n��˫�۽���$n�����з�������Ľ���......\n" NOR, me,target);

	lvl = me->query_skill("training",1);
	lvl = lvl * lvl * lvl /10;
	if( lvl < 50 ) lvl = 50;

	if( target->query("train_lvl") )
		exp = target->query("train_lvl") * target->query("train_lvl") * target->query("train_lvl") / 10;
	else
		exp = target->query("combat_exp");

	if( lvl > (exp/2) ) lvl = exp / 2;

	if( lvl > random(exp) ) {
		message_vision(HIW"$nѱ���Ŀ���$N������������$N���֡�\n" NOR, me,target);
		if( lvl < (exp/3) ) {
			lvl = me->query_skill("training",1);
			if( lvl > 300 ) lvl = 300 + (lvl-300)/2;
			if( lvl > 200 ) lvl = 200 + (lvl-200)/2;
			if( lvl > 100 ) lvl = 100 + (lvl-100)/2;
			me->improve_skill("training",random(lvl+me->query_int(1)));
		}
		target->set("master",me->query("id"));
	}
	else {
		if( random(3) != 1 )
			message_vision(HIW"$n���������$N�Ķ����ͺ���֮����\n" NOR, me,target);
		else {
			message_vision(RED"$nͻȻ��ݺݵĵ���$Nһ�ۣ�����$N��\n" NOR, me,target);
			target->fight_ob(me);
		}
	}

	me->set_temp("train/busy",1);
	if( me->is_fighting() ) me->start_busy(1);
	call_out("delete_busy",6+random(13),me);

	return 1;
}

void delete_busy(object me)
{
	if( me ) me->delete_temp("train/busy");
}

int help(object me)
{
write(@HELP
ָ���ʽ : train <����id>

�����������ѱ�����
HELP
);
	return 1;
}
