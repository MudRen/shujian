// tianyin.c ���ڴ���ӡ֮��ӡ
#include <ansi.h>

inherit F_SSERVER;

string perform_name(){ return HIY"��������ӡ��"NOR; }

int perform(object me, object target)
{
	int lvl;
	string msg;

	if( !target ) target = offensive_target(me);


         if( !target  
          || !me->is_fighting(target)
          || !objectp(target)
          || environment(target)!= environment(me))
           return notify_fail("��������ӡֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á���������ӡ������\n");		
	if((int)me->query_skill("longxiang-boruo",1)<80)
                return notify_fail("��������������Ϊ������\n");	
        if( (int)me->query_skill("dashou-yin", 1) < 80 )
		return notify_fail("������ڴ���ӡ��Ϊ����������ʹ�á���������ӡ������\n");
        if((int)me->query("max_neili",1)<1000)
                return notify_fail("���������Ϊ̫���޷�ʹ�ñ��ơ�\n");                        
        if( (int)me->query("neili", 1) < 500 )
		return notify_fail("����������̫��������ʹ�á���������ӡ������\n");
        if((int)me->query_skill("poison",1)<80)
            return notify_fail("��Ķ����������޷�����ͳ��ƶ���\n");			
	me->start_perform(5,"��������ӡ");
	msg = HIY "$NĬ���ŭ�䣬������������񹦣�ʮָ���ɣ�˫�ֶ�Ȼ��������������һ���Ϻ�֮������$n��\n"NOR;
	msg +=  "����һ�С�"HIG"�������������콵ħ��ӡ"NOR"����\n\n"NOR;
           	message_vision(msg, me, target);

        if( !target->is_killing(me) ) target->kill_ob(me);

        if( target->query_temp("fanzhen")){
             msg+=HIY"$n ������������$Nһ�ƻ����ؿ�֮�ϣ�ֻ�����һ����$N���ƶ�������������أ�\n"
                   +"$Nʧ�����У�����ղ������񹦣�����æ�������ܡ�\n"NOR;     	
                me->add("neili", -300);
                me->apply_condition("dsy_poison", random(me->query_skill("poison")/10) + 1 );
           	message_vision(msg, me, target);
                return 1;
                    }	      



        lvl =( (int)me->query_skill("poison",1) +  (int)me->query_skill("dashou-yin", 1)+ (int)me->query_skill("longxiang-boruo",1) ) /2 ;

	me->add_temp("apply/hand", lvl);
	me->add_temp("apply/attack", lvl /3);
	me->add_temp("apply/strength", lvl /3);
	me->add_temp("apply/damage", lvl );

	if( present(target,environment(me)) && me->is_fighting(target) )
                COMBAT_D->do_attack(me, target, 0, 3);

	if( present(target,environment(me)) && me->is_fighting(target) )
                COMBAT_D->do_attack(me, target, 0, 3);

	me->add_temp("apply/hand",- lvl);
	me->add_temp("apply/attack",- lvl /3);
	me->add_temp("apply/strength",- lvl /3);
	me->add_temp("apply/damage", -lvl );

	me->start_perform(3, "�������������콵ħ��ӡ");
	me->start_busy(random(2));

	return 1;



}


int help(object me)
{
        write(HIG"\n����ӡ���������������콵ħ��ӡ����"NOR"\n");
        write(@HELP
        ��������ӡ�������Ͻ�ħ��ӡ��������������߶�������Ѫɷ�綾�������ˡ�
        Ҫ��  �������  1000 ���ϣ�
                  ��ǰ����  700 ���ϣ�
                  ��ǰ����  500 ���ϣ�
                 ����ӡ���������񹦣����� ��80lvl����
HELP
        );
        return 1;
}
