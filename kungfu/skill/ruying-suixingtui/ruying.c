// ruying ��Ӱ����
// by snowman@SJ 
// Modify by snowman@SJ 22/02/2000

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	mapping pre;
	string *skill, a, b;
	int i;

	if( !target ) target = offensive_target(me);

    if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("����Ӱ���Ρ�ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("ʹ�á���Ӱ���Ρ�ʱ˫�ֱ�����ţ�\n");
	if( me->query_temp("fumo"))
		 return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
	if( (int)me->query_skill("ruying-suixingtui", 1) < 120 )
		return notify_fail("�����Ӱ�����Ȳ�����죬����ʹ�á���Ӱ���Ρ���\n");

	if( (int)me->query_skill("yijin-jing", 1) < 120 )
		return notify_fail("����׽�ȼ�����������ʹ�á���Ӱ���Ρ���\n");

	if (me->query_skill_mapped("force") != "yijin-jing")
		return notify_fail("��Ŀǰ���ڹ��޷�֧����ʹ�á���Ӱ���Ρ����й�����\n");  
			
	if( (int)me->query_dex() < 30 )
		return notify_fail("���������ǿ������ʹ�á���Ӱ���Ρ���\n");

	if (me->query_skill_prepared("leg") != "ruying-suixingtui"
	|| me->query_skill_mapped("leg") != "ruying-suixingtui")
		return notify_fail("�������޷�ʹ�á���Ӱ���Ρ����й�����\n");  
											       
	if( (int)me->query("max_neili") < 1800 )
		return notify_fail("������������Ϊ̫��������ʹ�á���Ӱ���Ρ���\n");
	if( (int)me->query("neili") < 1500 )
		return notify_fail("��Ŀǰ����̫�٣�����ʹ�á���Ӱ���Ρ���\n");

	if( (int)me->query("jingli") < 500 )
		return notify_fail("�����ھ���̫�٣�����ʹ�á���Ӱ���Ρ���\n");


	tell_object(me,YEL"\n������һ�����������ھ���˲ʱ������\n" NOR,me, target);
	pre = me->query_skill_prepare();
	skill = keys(pre);     
	for (i=0; i<sizeof(skill); i++){
		if(skill[i]=="leg") continue; 
		a = skill[i];
		b = pre[skill[i]];
		me->prepare_skill(a);
	}

	i = (int)me->query_skill("ruying-suixingtui", 1)+(int)me->query_skill("yijin-jing",1)/3;
 
        me->add_temp("apply/attack", i/2);
        me->add_temp("apply/strength", i/8);
        me->add_temp("apply/leg",i/3);
        me->add_temp("apply/damage", i/3);
        me->add_temp("apply/dodge", i);


	me->set_temp("sl_rysxt", 5);
if(!userp(target)) target->add_busy(2);
 	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	me->add("neili", -80);
	if(me->is_fighting(target)){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		me->add("neili", -80);
	}
	if(me->is_fighting(target) && me->query_skill("ruying-suixingtui", 1) >= 150){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		me->add("neili", -80);
	}
	if(me->is_fighting(target) && me->query_skill("ruying-suixingtui", 1) >= 180){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		me->add("neili", -100);
	}
	
	// 5th kick is type_super. cannot be done in normal fight.
	if(me->is_fighting(target) && me->is_killing(target->query("id"))
	   && random(me->query_skill("ruying-suixingtui", 1)) >= 100) {
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		me->add("neili", -150);
	}
	
	message_vision(YEL "\n$N��������ʹ�꣬ȫ��һת���������ڵ��ϡ�\n" NOR,me, target);
	me->prepare_skill(a,b);
	me->reset_action();

        me->add_temp("apply/attack",- i/2);
        me->add_temp("apply/strength",- i/8);
        me->add_temp("apply/leg",-i/3);
        me->add_temp("apply/damage",- i/3);
        me->add_temp("apply/dodge", -i);

	me->delete_temp("sl_rysxt");

	me->start_busy(2);           

   me->start_perform(4,"����Ӱ�����ȡ�");

	return 1;
}


string perform_name(){ return HIY"��Ӱ����"NOR; }
