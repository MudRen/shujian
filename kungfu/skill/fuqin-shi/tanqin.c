// tanqin.c �ɼ�����
// Created by snowman@SJ 08/03/2001

#include <ansi.h>

inherit F_SSERVER;

int is_pfm() { return 1;}
void check_fight(object me, int i);

#define PFM_NAME 	"�ɼ�����"

string perform_name(){ return HIG+PFM_NAME+NOR; }

void check_fight(object me, int i);

int perform(object me, object target)
{
	object weapon;
	int i;
	
      	if( !me->is_fighting() )
      		return notify_fail("��"PFM_NAME + "��ֻ����ս���жԶ���ʹ�á�\n");      
     		
     	i = (int)me->query_skill("fuqin-shi", 1);
      	if( i < 300 )
      		return notify_fail("��ĸ���ʽ������죬����ʹ�á�" + PFM_NAME + "����\n");
      
      	if( (int)me->query_skill("whip",1) < 300 )
      		return notify_fail("��Ļ����޷��ȼ�����������ʹ�á�" + PFM_NAME + "����\n");  
      
      	if( (int)me->query_skill("sancheng-gong", 1) < 300 )
      		return notify_fail("������˹����ȼ�����������ʹ�á�" + PFM_NAME + "����\n");

      	if( (int)me->query("max_neili") < 6500 )
      		return notify_fail("�������̫��������ʹ�á�" + PFM_NAME + "����\n");
      
      	if( (int)me->query("neili") < 3000 )
      		return notify_fail("�������̫���ˣ��޷�ʹ�ó���" + PFM_NAME + "����\n");   
        
	if( me->query("jiali") > me->query_dex() )
      		return notify_fail("�������������ͣ��޷�֧��ʹ�á�" + PFM_NAME + "����\n");
      								      
      	if( me->query_skill_mapped("force") != "sancheng-gong")
      		return notify_fail("�����ڵ��ڹ��޷�֧��ʹ�á�" + PFM_NAME + "����\n");
      	
      	if( (int)me->query_int() < 45 )
      		return notify_fail("������ϵ���⻹����͸�����޷����ӡ�" + PFM_NAME + "����������\n");
      		
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "whip"
       	|| me->query_skill_mapped("whip") != "fuqin-shi")
      		return notify_fail("������û�бޣ��޷�ʹ�á�" + PFM_NAME + "����\n");   
      		
      	if( me->query_temp("pfm/tanqin") )
      		return notify_fail("������ʹ�á�" + PFM_NAME + "���У�\n");   
      		
      	message_vision(HIG"\n$N��$n"HIG"������ĬĬ���������������Ҹ�����һ�������Ž�$n"HIG"һ˦����ͷ����������԰Ȧ��$n"HIG"��$P���в��ϲ�����������һ������������������$P΢����Х���ศ��ã������ö�������һ�㣡\n"NOR, me,weapon);
      	me->set_temp("pfm/tanqin", i);
      	me->add_temp("apply/attack", i/5);
	me->add("neili", -400);
	check_fight(me, i/2);
      	me->start_perform(6 , PFM_NAME);
      	return 1;
}


void remove_setting(object me)
{
	int j;
	
	if( !me ) return; 
        if( !intp(j = me->query_temp("pfm/tanqin")) ) return;
        
	me->add_temp("apply/attack", -j/5);
        me->delete_temp("pfm/tanqin");
        me->start_perform(2, PFM_NAME);	
}


string *pfm_chat = ({
HIG"\n$N��$n"HIG"Ϊ��ʹ���ġ�" + PFM_NAME + "�������ö������ƹ㿡���������˶��鲻�Խ���\n"NOR,
HIG"\n$n"HIG"��س�������ͬС�ܱ�ˮ������ǡ�����ϣ���������$N"HIG"��������������˷���·�������ڡ�" + PFM_NAME + "��֮�£�\n"NOR,
HIG"\n$N���޳��У�������" + PFM_NAME + "�������紦�Ӷ������ٰ㣬��ָ�����ɣ����ƹ㿡�������˶���������������\n"NOR,
HIG"\n��ˮ���ö�����������$N"HIG"���У��ټ���$n"HIG"�����ɳɳ������֯��һƪ���������£��������ܣ�\n"NOR,
HIG"\n$n"HIG"����ķ�������$N"HIG"����Х�����������ö������������˶�Ϊ֮һ㶣�����Ƕ��Ҿ��С�" + PFM_NAME + "����\n"NOR,
HIG"\nһ������������������$N���кͻӶ��е�"HIG"$n����Բ���ܶ������������⡸" + PFM_NAME + "���������У�\n"NOR,
});

int family_check(object obj)
{
	if( !obj->is_character() ) return 0;
  	if( obj->query("family/family_name") == "������" )
    		return 0;
  	return 1;
}
void check_fight(object me, int i)
{       
        object weapon, *ob;
        int j;
        
        if( !me ) return; 
 
 	weapon = me->query_temp("weapon");
        i--;
        if( !me->is_fighting() 
	|| !living(me)
        ||  i < 1
        ||  !weapon
        ||  weapon->query("skill_type") != "whip"
       	||  me->query_skill_mapped("whip") != "fuqin-shi"
        ||  me->query("neili") < 500
        ||  me->query_skill_mapped("force") != "sancheng-gong"
        ||  me->query_skill_mapped("whip") != "fuqin-shi"
        ||  me->query_skill_mapped("parry") != "fuqin-shi") {
        	me->add_temp("apply/attack", -j/5);
        	me->delete_temp("pfm/tanqin");
        	me->add("neili", -j );
        	me->start_perform(2, PFM_NAME);
        	if( living(me) )
			message_vision(YEL "\n$N����������ֹͣ�ˡ�" + PFM_NAME + "����\n" NOR, me);   
        	return;
        }
        me->add("neili", -10 );
        ob = filter_array(all_inventory(environment(me)), (:  family_check :));
	ob->start_perform(2, PFM_NAME);

	if( i % 10 == 0 )
		message_vision(pfm_chat[random(sizeof(pfm_chat))], me,weapon);

        call_out("check_fight", 1, me, i);
}

int help(object me)
{
	write(HIG"\n����ʽ��" + PFM_NAME + "����"NOR"\n");
	write(@HELP
	��˵��ʫ����������������㿡���е���ʱ���������¹���ǰȥ��������
	�����ȥ���㿡԰�š�����ÿ�����裬��ˮ�ر߾ͻ�����������˸���
	���Ӽ�һ���¹���������٣�ָ�����ɣ����ƹ㿡��������������������
	���𼱱ܣ�Ծ����С�ǰ��̽�ӣ�ȴ��һС���ܱ�ˮ����������ǡ�����ϡ�
	��Ϊ���ɼ����١��������ܶ�������������ǰ�����˶�����ʹ�þ��У�
	
	Ҫ��	
		����ʽ�ȼ� 300 ���ϣ�
		�����޷��ȼ� 300 ���ϣ�
		���˹����ȼ� 300 ���ϣ�
		������� 6500 ���ϣ� 
		���� 3000 ���ϣ�      
		���� 45 ���ϡ�
HELP
	);
	return 1;
}

