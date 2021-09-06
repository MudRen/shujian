#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int main(object me, string arg)
{
	object target1,target2;
	string str1,str2;

	if( !arg || sscanf(arg,"%s %s",str1,str2)!=2 )
		return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if( !me->is_fighting() )
		return notify_fail("��û��ս������!��\n");

	if( environment(me)->query("no_fight"))
		return notify_fail("���ﲻ��ս����\n");

	if( me->query_skill_mapped("parry")!="qiankun-danuoyi")
		return notify_fail("���ֲ���Ǭ����Ų�ơ�\n");

	if( !present(str1,environment(me)) )
		return notify_fail("����û��"+str1+"��\n");

	if( !present(str2,environment(me)) )
		return notify_fail("����û��"+str2+"��\n");

	target1=present(str1,environment(me));
	target2=present(str2,environment(me));

	if(target1 == target2 || me == target2)
		return notify_fail("���Ǳ�׷���������\n");

	if( !me->is_fighting(target1) )
		return notify_fail("�㲢û���ڸ�"+str1+"��ս��\n");

	if( !living(target2) )
		return notify_fail("�ǲ��Ǹ����\n");

	if( (int)me->query("max_neili") < 3000 )
		return notify_fail("��Ŭ��������ɣ�\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("�������������\n");

	if(me->query_skill("qiankun-danuoyi",1) < 210 )
		return notify_fail("�������Ǭ����Ų�Ƶ��߲��ʵ����\n");

	if ( me->query_skill("jiuyang-shengong", 1) < 210 
	&& me->query_skill("shenghuo-shengong", 1) < 210 )
		return notify_fail("����ڹ��ȼ�������\n");

	tell_object( me, HIG"�㰵��Ǭ����Ų�Ƶĵ��߲��ķ���\n"NOR );

	if (userp(target1))
		me->add_condition("killer", 10);

	if (userp(target2))
		me->add_condition("killer", 10);

	if( random(me->query_int()) > target1->query_int()/4 &&
	 random(me->query_int()) > target2->query_int()/4) {
		me->start_busy(1+random(3));
		message_vision(HIG"ͻȻ�䣬$N��$n����һ�У�\n",target1, target2);
		message_vision(HIG"$n�ݺݵĵ���$Nһ�ۣ�$NҲĪ�����\n"NOR,target1, target2);
		COMBAT_D->do_attack(target1, target2, target1->query_temp("weapon"), 0);
		target2->add_temp("qkdny/target",1);
		if( target2->query_temp("qkdny/target")*5 > random(target2->query_int())){
			message_vision(HIR"\n$n��Ȼ��ʼ��$N��������������ˣ�\n"NOR,target1,target2);
			message_vision(HIR"\n$NĪ�����Ҳ���˺���$nɱȥ��\n"NOR,target1, target2);
			message_vision(HIW"\n$N΢΢һЦ�����ֹ۶���\n"NOR,me);
			target2->delete_temp("qkdny/target");
			me->remove_all_enemy();
			target1->remove_all_enemy();
			target1->kill_ob(target2);
			target2->kill_ob(target1);
		}
	}
	else {
		tell_object( me, HIB"����ʧ���ˡ�\n"NOR );
		me->start_busy(1+random(3));
	}
	me->add("neili",-150-random(50));
	me->add("jingli",-50-random(50));
	me->add("jing",-50-random(50));
	return 1;
}
