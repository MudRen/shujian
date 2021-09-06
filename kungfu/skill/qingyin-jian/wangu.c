// wangu.c ���һţ��
// Created by snowman@SJ 18/03/2001

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

int is_pfm() { return 1;}

#define PFM_NAME 	"���һţ��"
string perform_name(){ return HIM+PFM_NAME+NOR; }

int perform(object me)
{     
      	if( (int)me->query_skill("qingyin-jian",1) < 180 )
           	return notify_fail("�����������������죬����ʹ��" + PFM_NAME + "��\n");
      
      	if( (int)me->query_skill("sword",1) < 180 )
           	return notify_fail("��Ļ��������ȼ�����������ʹ��" + PFM_NAME + "��\n");  
      
      	if( (int)me->query_skill("sancheng-gong", 1) < 180 )
           	return notify_fail("������˹����ȼ�����������ʹ��" + PFM_NAME + "��\n");

      	if (me->query_skill_mapped("force") != "sancheng-gong")
           	return notify_fail("����ʹ�õ��ڹ��������˹�����\n");

      	if( (int)me->query("max_neili") < 2500 )
           	return notify_fail("�������̫��������ʹ��" + PFM_NAME + "��\n");
      
      	if( (int)me->query("neili") < 800 )
           	return notify_fail("�������̫���ˣ��޷�ʹ�ó�" + PFM_NAME + "��\n"); 
        
        return (int)call_other( this_object(), "main", me);
}

int main(object me)
{
	object weapon;
	int i;

      	if( me->query("neili") < 800 || me->query("jingli") < 100  )
                return notify_fail("��Ŀǰ�޷�ʹ�á�" + PFM_NAME + "����\n");   
                	
	weapon = me->query_temp("weapon");
      	if (!weapon
       	|| weapon->query("skill_type") != "sword"
       	|| me->query_skill_mapped("sword") != "qingyin-jian" )
       		return notify_fail("�������޷�ʹ��" + PFM_NAME + "��\n");      
       		
       	i = me->query_skill("qingyin-jian", 1) + me->query_skill("sancheng-gong", 1);
       	i = i/2 + random(i/2);
       	i /= 2;
       	
	me->add("neili", -i);
        me->add("jingli", -50);
        message_vision(YEL "\n$N���������˫����$n"YEL"�����紦�ӣ�����$P�������Է紵��Х����ΡȻ������һ�ɺ���֮�����ض�����\n\n" NOR, me, weapon);
        me->start_perform(4, PFM_NAME);
        me->set_temp("pfm/wangu", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/sword", i);
        me->add_temp("apply/damage", i/6);
        call_out("check_fight", 1 , me, i/10);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void check_fight(object me, int i)
{       
        int j;
        
        if( !me ) return; 
        if( !intp(j = me->query_temp("pfm/wangu")) ) return;
        
        i--;
        if( !me->is_fighting() 
	|| !me->is_living()
        ||  i < 1
        ||  !me->query_temp("weapon")
        ||  me->query_skill_mapped("sword") != "qingyin-jian"
        ||  me->query_skill_mapped("force") != "sancheng-gong") {
        	me->add_temp("apply/attack", -j);
        	me->add_temp("apply/sword", -j);
        	me->add_temp("apply/damage", -j/6);
        	me->delete_temp("pfm/wangu");
        	me->add("neili", -j );
        	me->start_perform(2, PFM_NAME);
        	if( living(me) )
			message_vision(YEL "\n$N�������һ�����������񻺻��ɳ���������\n" NOR, me);   
        	return;
        }
	me->start_perform(1, PFM_NAME);
        call_out("check_fight", 1, me, i);
}


int help(object me)
{
	write(HIG"\n����������" + perform_name() + HIG"����"NOR"\n");
	write(@HELP
			˫������Ӱ�����һţ��
			
	��������������֮һ������ڵ�����ô���֮��������˫����������
	���ϡ�������ڰ׶�ˮ��ţ��ʯ���Ƕ�üɽʮ��֮һ���侪����ʯ������
	�ɻ�����������ѩ��ˮ����һ����������ˮ�飬�����ڿ��У�������
	ˮ�����ʯ��ڹ��������������ڶ������ʷ������������ڰ׶�ˮ��
	ӿ�Ļ�����ΡȻ�������˽���Ҫ�����ھ��������ϵ����ȣ����ܰ�������
	���Դ�ʽ����ˮ�о�ʯһ�����������������˵У�
	
	Ҫ��	
		���������ȼ� 180 ���ϣ�
		���������ȼ� 180 ���ϣ�
		���˹����ȼ� 180 ���ϣ�
		������� 2500 ���ϣ� 
		���� 800 ���ϡ�
HELP
	);
	return 1;
}

