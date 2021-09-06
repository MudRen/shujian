// qiufeng.c ��縧��ʽ
// Created by snowman@SJ 08/03/2001

#include <ansi.h>

inherit F_SSERVER;

int is_pfm() { return 1;}

#define PFM_NAME 	"��縧��ʽ"

string perform_name(){ return YEL+PFM_NAME+NOR; }

int perform(object me, object target)
{
      	if( !target ) target = offensive_target(me);
     
      	if( !target 
      	|| !me->is_fighting(target) 
      	|| !living(target)
      	|| environment(target) != environment(me) )
      		return notify_fail("��"PFM_NAME + "��ֻ����ս���жԶ���ʹ�á�\n");      

	if( target->is_busy() )
      		return notify_fail("�Է��Ѿ��Թ˲�Ͼ�ˣ�����ʹ�á�" + PFM_NAME + "���ɣ�\n");
      		
      	if( (int)me->query_skill("fuqin-shi",1) < 100 )
      		return notify_fail("��ĸ���ʽ������죬����ʹ�á�" + PFM_NAME + "����\n");
      
      	if( (int)me->query_skill("whip",1) < 100 )
      		return notify_fail("��Ļ����޷��ȼ�����������ʹ�á�" + PFM_NAME + "����\n");  
      
      	if( (int)me->query_skill("sancheng-gong", 1) < 80 )
      		return notify_fail("������˹����ȼ�����������ʹ�á�" + PFM_NAME + "����\n");

      	if( (int)me->query("max_neili") < 800 )
      		return notify_fail("�������̫��������ʹ�á�" + PFM_NAME + "����\n");
      
      	if( (int)me->query("neili") < 300 )
      		return notify_fail("�������̫���ˣ��޷�ʹ�ó���" + PFM_NAME + "����\n");   
                                                                                 
      	if( me->query_skill_mapped("force") != "sancheng-gong")
      		return notify_fail("�����ڵ��ڹ��޷�֧��ʹ�á�" + PFM_NAME + "�����й�����\n");

	return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
	object weapon;
	string msg, dodge_skill;
	int ap, dp;
	
	if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || me->query("neili") < 400 || me->query("jingli") < 100 
        || environment(target) != environment(me) )
                return notify_fail("��Ŀǰ�޷�ʹ�á�" + PFM_NAME + "��\n");   
                
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "whip"
       	|| me->query_skill_mapped("whip") != "fuqin-shi")
      		return notify_fail("������û�бޣ��޷�ʹ�á�" + PFM_NAME + "����\n");   
      		
      	msg = YEL"\n������紵���ŷ��ͣ�ҡ���Ŵ��֣�����������Х��ƬƬ�Ⱥ��"RED"��Ҷ"YEL"�ڿ��з��裬��ˮ����硢�����໥Ӧ���š���\n\n"HIC
      	"$Nӭ����������󶶱ޣ�"+weapon->name()+HIC"�ɴ�������ӭ�Ž����룬��" + PFM_NAME + "���·�ΪƮƮ��Ҷ���裬ֱϮ$n��\n"NOR;
      	
      	me->add("neili", -(200+random(100))); 
      	me->add("jingli", -50);
      	ap = me->query("combat_exp")/1000 * me->query_skill("fuqin-shi",1) * me->query_int();
       	dp = target->query("combat_exp")/1000 * target->query_skill("dodge",1) * target->query_int();
       	if (ap < 1) ap = 1;
       	if (dp < 1) dp = 1;
       	if( me->query_temp("pfm/qiushui") )
		ap += ap/2;
		
        if( random(ap + dp) > dp ){
        	target->start_busy(me->query_int()/8);
        	msg += YEL"���$nһ�����񣬱���������Ӱ�У���ʱ�з����ң�\n"NOR;
        }
       	else{
                me->start_busy(1+random(2));
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
       	}
       	
        message_vision(msg, me,target);
        me->start_busy(1);
      	me->start_perform(4 , PFM_NAME);
      	return 1;
}

int help(object me)
{
	return (int)call_other(__DIR__"qiushui", "help", me);
}
