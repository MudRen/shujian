// baishui.c ��ˮ����ʽ
// Created by snowman@SJ 08/03/2001

#include <ansi.h>

inherit F_SSERVER;

int is_pfm() { return 1;}

#define PFM_NAME 	"��ˮ����ʽ"

string perform_name(){ return HIW+PFM_NAME+NOR; }

int perform(object me, object target)
{
      	if( !target ) target = offensive_target(me);
     
      	if( !target 
      	|| !me->is_fighting(target) 
      	|| !living(target)
      	|| environment(target) != environment(me) )
      		return notify_fail("��"PFM_NAME + "��ֻ����ս���жԶ���ʹ�á�\n");      
      		
      	if( (int)me->query_skill("fuqin-shi",1) < 120 )
      		return notify_fail("��ĸ���ʽ������죬����ʹ�á�" + PFM_NAME + "����\n");
      
      	if( (int)me->query_skill("whip",1) < 120 )
      		return notify_fail("��Ļ����޷��ȼ�����������ʹ�á�" + PFM_NAME + "����\n");  
      
      	if( (int)me->query_skill("sancheng-gong", 1) < 100 )
      		return notify_fail("������˹����ȼ�����������ʹ�á�" + PFM_NAME + "����\n");

      	if( (int)me->query("max_neili") < 1200 )
      		return notify_fail("�������̫��������ʹ�á�" + PFM_NAME + "����\n");
      
      	if( (int)me->query("neili") < 500 )
      		return notify_fail("�������̫���ˣ��޷�ʹ�ó���" + PFM_NAME + "����\n");   
                                                                                 
      	if( me->query_skill_mapped("force") != "sancheng-gong")
      		return notify_fail("�����ڵ��ڹ��޷�֧��ʹ�á�" + PFM_NAME + "�����й�����\n");

	return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
	object weapon;
	int ap;
	
	if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || me->query("neili") < 400 || me->query("jingli") < 100 
        || environment(target) != environment(me) )
                return notify_fail("��Ŀǰ�޷�ʹ�á�" + PFM_NAME + "����\n");   
                
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "whip"
       	|| me->query_skill_mapped("whip") != "fuqin-shi")
      		return notify_fail("������û�бޣ��޷�ʹ�á�" + PFM_NAME + "����\n");   
      		
      	message_vision(WHT"\n����$N�������������ƽˮ��ʱ�İ�ˮ�أ�������ɽ��ɽ�����ƣ�������ˮ���ֲ���������ˮ���������ƣ�
			��ʱ��$P���������Σ����澰ɫ���ﻯ����\n\n"NOR, me,target);

      	me->add("neili", -(200+random(100))); 
      	me->add("jingli", -50);
      	ap = me->query_skill("fuqin-shi",1)/40 * me->query_int();
	
	if( me->query_temp("pfm/qiushui") )
		ap += me->query_str() + me->query_dex();
		
	me->set_temp("pfm/baishui", 1);
	me->add_temp("apply/attack", ap);
	me->add_temp("apply/damage", ap/10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       	me->add_temp("apply/attack", -ap);
	me->add_temp("apply/damage", -ap/10);
	
        me->start_busy(1);
      	me->start_perform(4 , PFM_NAME);
      	return 1;
}

int help(object me)
{
	return (int)call_other(__DIR__"qiushui", "help", me);
}

