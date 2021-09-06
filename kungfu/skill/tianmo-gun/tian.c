// tian.c �����ת
// Modify by action

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIR"�����ת"NOR; }
int perform(object me,object target)
{
    object weapon;
    int i,j,lev,jiali;
    
    if( !target ) target = offensive_target(me);
     
    if( !userp(me) && userp(target) )
                return notify_fail("�������ת��ֻ�������ʹ�á�\n");

    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("�������ת��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing-dafa")
                return notify_fail("����ʹ�õ������ڹ����ԡ�\n"); 

        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 350)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�����������ת����\n");  

    if( (int)me->query_skill("tianmo-gun", 1) < 350 ) 
                return notify_fail("���������ħ����δ���ɣ��޷�ʹ�á������ת����\n");

    if((int)me->query_skill("club", 1) < 400 )
                return notify_fail("��Ļ�������������죬����ʹ�á������ת����\n");

    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "tianmo-gun")
                return notify_fail("�����ʹ�ù���������ʹ���������ת��!\n");
                
   if((int)me->query_str() < 40)
           return notify_fail("�������������ǿ����ʹ�����������ת��������\n");

   if(me->query_skill_mapped("parry") != "tianmo-gun")
           return notify_fail("�������ת����Ҫʹ����ħ���мܡ�\n"); 

   if((int)me->query("max_neili") < 10000 )
           return notify_fail("��������Ϊ��ǳ��ʹ�����������ת����\n");  

   if( (int)me->query("neili") < 6000 )
           return notify_fail("����������̫����ʹ�����������ת����\n");

	 message_vision(HIR"\n$N������"+weapon->name()+HIR+"������������$n�������ƶ�����ֻ��"+weapon->name()+HIR+"ɢ�����������¹⻷��\n"NOR, me, target);

    lev = (int)me->query_skill("tianmo-gun",1)/2;
if(lev>225 ) target->add_busy(2);
    if( me->query_temp("xxdf/powerup") ) {           
           lev *= 2;
       }

    me->start_perform(3,"�������ת��");
   
    me->set_temp("tmg/tian", 1);
        jiali = ((int)me->query("str",1)/2 + (int)me->query("con",1))/2 + random((int)me->query("jiali")/20 );
        me->add_temp("apply/damage",  lev/2);
        me->add_temp("apply/attack",  lev);
        me->add_temp("apply/strength", jiali);
        target->add_busy(1+random(2));
        for (i=0;i<5;i++){
          j = i;
          if (i<1) j = 1;
          if (i>1) j = 3;
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"),j);
          me->add("neili", -100);  
        }
   
        me->add("neili", -200);
        me->add_temp("apply/damage",  -lev/2);
        me->add_temp("apply/attack",  -lev);
        me->add_temp("apply/strength", -jiali);

    me->delete_temp("tmg/tian");
    target->add_busy(1);
    return 1;
}

int help(object me)
{
	write(WHT"\n�������ת����"NOR"\n");
	write(@HELP

	Ҫ��
		������� 10000 ���ϣ�
		��ǰ���� 6000 ���ϣ�
		������ħ���ȼ� 400 ���ϣ�
		���Ǵ󷨵ȼ� 400 ���ϣ�
		�����м�Ϊ������ħ����
HELP
	);
	return 1;
}
