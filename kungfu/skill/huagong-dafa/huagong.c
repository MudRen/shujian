// huagong.c ����
// by snowman@SJ
// modify by snowman@SJ 25/02/2000
// Modified by darken@SJ
// Modified by olives@SJ 5/17/2001
// for action.c changed,some bugs.
// Modified by olives@SJ 7/21/2001
// ����ʧ�ܵ�����

#include <ansi.h>

inherit F_SSERVER;

string exert_name(){ return HBRED"����"NOR; }
int check_fight(object me);
int halt_fight(object me);

int exert(object me, object target)
{
	object room, ob;

	if( !target) target = offensive_target(me);
	if( !target || !objectp(target) || !me->is_fighting(target) || !living(target))
		return notify_fail("����ֻ����ս���жԶ���ʹ�á�\n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("�û�����ձȽϿ졣\n");

	if( !userp(target) && !wizardp(me))
		return notify_fail("�㲻�ܶ���ʹ�û�����\n");

	if(!( room = find_object("/d/taishan/fengchan")) )
		room = load_object("/d/taishan/fengchan");
	if( objectp(ob = present("zhong shentong", room)) ) {
		if(target->query("id") == ob->query("winner"))
			return notify_fail("�󵨣����Ҷ�����ͨ���û����󷨣�\n");
	}

	if( !living(target) || ! target->query("can_speak"))
		return notify_fail("�����ǻ����û����ȡ������\n");

	if( me->query_temp("weapon"))
		return notify_fail("�����ʹ���������ץ������ץס���֡�\n");

	if( me->query_skill_mapped("claw") != "sanyin-zhua")
		return notify_fail("�����ʹ���������ץ������ץס���֡�\n");

	if( (int)me->query_skill("huagong-dafa",1) < 250 )
		return notify_fail("��Ĺ�������������ʩչ�����󷨣�\n");

	if( (int)me->query_skill("poison",1) < 200 )
		return notify_fail("�����ڵĶ��ز���������ʩչ�����󷨣�\n");

	if(environment(me)->query("no_death"))
		return notify_fail("�˵ز���ʩչ�����󷨣�\n");

	if((int)target->query("max_neili") <= 0
	|| target->query("combat_exp") < me->query("combat_exp")/2)
		return notify_fail( target->name() +"û�ж��������ɻ��ˡ�\n");

	message_vision(BLU"ͻȻ$N��������һ����Ц����������������������͵���$n��ȥ��\n\n" NOR, me, target );

	if( random(me->query_int()) > target->query_int()/2) {
	    message_vision(HBRED"$nҲ��һ����������˫��һ�ӣ�$n�ƺ�������ʲô������һ�����ã�\n\n" NOR, me, target );
	    me->start_busy((:check_fight:),(:halt_fight:));
	    me->set_temp("huagong/target",target);
	    target->start_busy(2);
	}
	else
		message_vision(YEL"\n����$n������$N����ͼ����������˿�ȥ��"NOR,me,target);

	if( !target->is_killing(me->query("id")) ){
		me->kill_ob(target);
		target->kill_ob(me);
	}

	me->start_exert(2+random(2),"�������󷨡�");
	return 1;
}

int check_fight(object me)
{
	object target,victim, *people;
	int i,dp,ap;
	if(!objectp(target = me->query_temp("huagong/target")) || !userp(target))
	{
		me->delete_temp("huagong");
		me->start_exert(2+random(2),"�������󷨡�");
		message_vision(HIC"\n$N����һ£����˫���������С�\n"NOR,me);
		return 0;
	}
	target->start_busy(2);
	dp = target->query_skill("douzhan-xingyi",1);
	if(target->query_skill("qiankun-danuoyi",1)>dp)
		dp = target->query_skill("qiankun-danuoyi",1);
	ap = me->query_skill("sanyin-zhuan",1);
	if(target->query("max_neili") < 1
	|| target->query_temp("huagong/count") > 10) {
	    message_vision(RED"$n��$N�����˵�Ԫ�������̯�ڵ��ϡ�\n"NOR, me, target);
	    message_vision(RED"$N����һЦ���ɿ����֡�\n"NOR, me, target);
	    target->add("max_neili",-50-random(30));
	    if(target->query("max_neili")<0)
		target->set("max_neili",0);
	    target->set("neili",0);
	    target->delete_temp("huagong/count");
//          me->remove_all_enemy();
//          target->remove_all_enemy();
	    me->start_exert(2+random(2),"�������󷨡�");
	    return 0;
	}

	if(random(ap+dp)<dp)
	{
	     people = all_inventory(environment(me));
	     i = random(sizeof(people));
	     victim = people[i];
	     if(victim != me
	     && victim != target
	     && victim->is_character()
	     && living(victim)
	     && !wizardp(victim)) {
		message_vision(HBRED"$N���һ����һǣһ������$nת����ǰ���ӹ��˶��ֵ�ħ�ƣ�\n"NOR, target, victim);
		target->remove_all_enemy();
		me->remove_all_enemy();
		me->set_temp("huagong/target",victim);
		victim->start_busy(2);
		return 1;
	     }
	}
	if (random(target->query("neili")) > me->query("neili")/2) {
	    message_vision(RED"$nƴ�������Ԫ����ȫ������������$Nһ�ͣ�������$N�����ա�\n"NOR, me, target);
	    target->add("max_neili",-5-random(5));
	    me->start_exert(2+random(2),"�������󷨡�");
	    return 0;
	}
	message_vision(RED"$nʹ�������������޷��ѳ�$N���գ�ֻ��������������ʧ��\n"NOR, me, target);
	me->add("combat_exp", random(me->query_skill("poison"))/10);
	target->add("max_neili", -20-random(11));
	target->add_temp("huagong/count", 1);
	return 1;
}

int halt_fight(object me)
{
	notify_fail("��˫��һ��������ƮƮ��˫���У�����δ��һ�㡣\n");
	me->start_busy(1+random(2));
	me->start_perform(2+random(2),"�������󷨡�");
	me->start_exert(2+random(2),"�������󷨡�");
	return 1;
}
