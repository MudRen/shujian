// qiufeng.c ��ˮ���ʽ
// Created by snowman@SJ 08/03/2001

#include <ansi.h>

inherit F_SSERVER;

int is_pfm() { return 1;}

#define PFM_NAME 	"��ˮ���ʽ"

string perform_name(){ return WHT+PFM_NAME+NOR; }

int perform(object me, object target)
{
      	if( !me->is_fighting() )
      		return notify_fail(PFM_NAME + "ֻ����ս���жԶ���ʹ�á�\n");      

	tell_object(me, HIG"\n�������������ͼʩչ���Ҿ�����" + PFM_NAME + "����\n"NOR);
	call_out("main", 1 + random(3), me, target);
	me->start_perform(4 , PFM_NAME);
	return 1;
}

int main(object me, object target)
{
	object weapon;
	
	if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || environment(target) != environment(me) )
                return notify_fail("��Ŀǰ�޷�ʹ�á�" + PFM_NAME + "����\n");   
      		
      	if( (int)me->query_skill("fuqin-shi",1) < 200 )
      		return notify_fail("��ĸ���ʽ������죬����ʹ�á�" + PFM_NAME + "����\n");
      
      	if( (int)me->query_skill("whip",1) < 200 )
      		return notify_fail("��Ļ����޷��ȼ�����������ʹ�á�" + PFM_NAME + "����\n");  
      
      	if( (int)me->query_skill("sancheng-gong", 1) < 180 )
      		return notify_fail("������˹����ȼ�����������ʹ�á�" + PFM_NAME + "����\n");

      	if( (int)me->query("max_neili") < 3500 )
      		return notify_fail("�������̫��������ʹ�á�" + PFM_NAME + "����\n");
      
      	if( (int)me->query("neili") < 1000 )
      		return notify_fail("�������̫���ˣ��޷�ʹ�ó���" + PFM_NAME + "����\n");   
                                                                                 
      	if( me->query_skill_mapped("force") != "sancheng-gong")
      		return notify_fail("�����ڵ��ڹ��޷�֧��ʹ�á�" + PFM_NAME + "�����й�����\n");
      		
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "whip"
       	|| me->query_skill_mapped("whip") != "fuqin-shi")
      		return notify_fail("������û�бޣ��޷�ʹ�á�" + PFM_NAME + "����\n");   
      		
      	tell_object(me, HIG"��о���������һ�𣬺��ˣ�\n"NOR);
      	me->set_temp("pfm/qiushui", 1);
	call_other( __DIR__"baishui", "main", me, target);
	if( me->query("neili") > 500 )
		call_other( __DIR__"qiufeng", "main", me, target);
		
	else tell_object(me, HIG"��������ų���縧��ʽ���ɷ����Լ��������������ˣ�\n"NOR);
	me->delete_temp("pfm/qiushui");
      	me->start_perform(6 , PFM_NAME);
      	return 1;
}

int help(object me)
{
	write(WHT"\n����ʽ��" + PFM_NAME + "����"NOR"\n");
	write(@HELP
	���������µ�ɽ���ļ����ˣ����������죬ÿ������üɽ�������д棬
	�������ѳ�Ʈ��ѩ����λ����ɽ�����������ɲ��������һ���еĻƽ�
	���ڡ�����һ�أ�����ˮ�أ���Ϊ�����������ɮ�����ٴ������˵���ɫ
	�������飬����Т���С��ַŵ����£��紵�뻧�ơ���ʫ�䣬�Ƕ���ʮ��
	֮һ����Ϊ����ˮ��硹���������Ů����ɽ���ˣ��۾����򣬴����˼�
	��������Ϊһ��ġ���ˮ���ʽ�����С��ȿɷ�ʹ��Ҳ�ɺ��á�
	
	Ҫ��	
		����縧��ʽ����
			����ʽ�ȼ� 100 ���ϣ�
			�����޷��ȼ� 100 ���ϣ�
			���˹����ȼ� 80 ���ϣ�
			������� 800 ���ϣ� 
			���� 300 ���ϣ�    
		����ˮ����ʽ����
			����ʽ�ȼ� 120 ���ϣ�
			�����޷��ȼ� 120 ���ϣ�
			���˹����ȼ� 100 ���ϣ�
			������� 1200 ���ϣ� 
			���� 500 ���ϣ�    
		����ˮ���ʽ����
			����ʽ�ȼ� 200 ���ϣ�
			�����޷��ȼ� 200 ���ϣ�
			���˹����ȼ� 180 ���ϣ�
			������� 3500 ���ϣ� 
			���� 1000 ���ϣ�    
HELP
	);
	return 1;
}

