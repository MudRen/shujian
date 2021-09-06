// qingyin.c ˫������
// Created by snowman@SJ 18/03/2001

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

int is_pfm() { return 1;}

#define PFM_NAME 	"˫������"
string perform_name(){ return HIM+PFM_NAME+NOR; }

int perform(object me, object target)
{     
      	if( (int)me->query_skill("qingyin-jian",1) < 300 )
           	return notify_fail("�����������������죬����ʹ��" + PFM_NAME + "��\n");
      
      	if( (int)me->query_skill("sword",1) < 300 )
           	return notify_fail("��Ļ��������ȼ�����������ʹ��" + PFM_NAME + "��\n");  
      
      	if( (int)me->query_skill("sancheng-gong", 1) < 300 )
           	return notify_fail("������˹����ȼ�����������ʹ��" + PFM_NAME + "��\n");

      	if (me->query_skill_mapped("force") != "sancheng-gong")
           	return notify_fail("����ʹ�õ��ڹ��������˹�����\n");

      	if( (int)me->query("max_neili") < 6000 )
           	return notify_fail("�������̫��������ʹ��" + PFM_NAME + "��\n");
      
      	if( (int)me->query("neili") < 1000 )
           	return notify_fail("�������̫���ˣ��޷�ʹ�ó�" + PFM_NAME + "��\n"); 
        
        if( !target ) target = offensive_target(me);
        
       	if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || me->query("neili") < 500 || me->query("jingli") < 100 
        || environment(target) != environment(me) )
                return notify_fail("��Ŀǰ�޷�ʹ�á�" + PFM_NAME + "����\n");   
                
        return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
	object weapon, ob;
		
      	if( !me->is_fighting() 
        || me->query("neili") < 500 || me->query("jingli") < 100 )
                return notify_fail("��Ŀǰ�޷�ʹ�á�" + PFM_NAME + "����\n");   
                	
	weapon = me->query_temp("weapon");
      	if (!weapon
       	|| weapon->query("skill_type") != "sword"
       	|| me->query_skill_mapped("sword") != "qingyin-jian" )
       		return notify_fail("�������޷�ʹ��" + PFM_NAME + "��\n");      
       		
       	if( !me->query_temp("pfm/qingyin") ){
       		foreach (ob in all_inventory(environment(me))){
       			if( !ob || !ob->is_character() || !living(ob) 
       			|| ob == me || !me->visible(ob) ) continue;
       			if( ob->query("family/family_name") != "������" ) continue;
			if( ob->is_fighting(me) || me->is_fighting(ob) ) continue;
       			if( ob->query_temp("pfm/qingyin") )
       				return (int)call_other( this_object(), "second_attack", me, ob);
       		}
       		call_out("check_fight", 1 , me, 20);
       		return (int)call_other( this_object(), "first_attack", me, target);
       	}

       	message_vision(HIG"\n$N��ʽһ�䣬�������ҵ�" + perform_name() + HIG"������������ֱϮ$n��\n"NOR, me, target);
       	me->add_temp("apply/attack", 50);
      	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      	if( me->is_fighting(target) )
      		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(4));
      	if( me->is_fighting(target) )
      		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

      	me->add_temp("apply/attack", -50);
      	me->delete_temp("pfm/qingyin");
      	me->start_perform(4, PFM_NAME);	
       	return 1;
       	
}

void check_fight(object me, int i)
{       
        if( !me ) return; 
        if( !me->query_temp("pfm/qingyin") ) return;
        
        i--;
        if( !me->is_fighting() 
        ||  i < 1
        ||  !me->query_temp("weapon")
        ||  me->query_skill_mapped("sword") != "qingyin-jian"
        ||  me->query_skill_mapped("force") != "sancheng-gong") {
        	me->delete_temp("pfm/qingyin");  
        	return;
        }
        call_out("check_fight", 1, me, i);
}

void attacking(object me)
{
	object target = offensive_target(me);
	
       	if( !target 
       	|| !target->is_character() 
       	|| !me->is_fighting(target) 
       	|| !living(target) 
        || environment(target) != environment(me) )
        	return;
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 40);
      	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
      	me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -40);
        	
}

int second_attack(object me, object ob)
{
	int i = me->query_skill("qingyin-jian", 1)/40;
	if( i > 7 ) i = 7;
	
	me->delete_temp("pfm/qingyin");
	ob->delete_temp("pfm/qingyin");
	
       	message_vision(HIG"\n$N�����б����������漴һ����Х�����λö�����$nһ��һ���໥���������Ľ����������������Ƕ�ü����" + perform_name() + HIG"��\n"NOR, me, ob);
        while( i-- ){
        	if( me->is_fighting() )
        		attacking(me);
        	if( ob->is_fighting() )
        		attacking(ob);
        }
       	me->start_perform(5, PFM_NAME);	
       	ob->start_perform(5, PFM_NAME);	
       	return 1;
}

int first_attack(object me, object target)
{
	me->set_temp("pfm/qingyin", 1);
       	message_vision(HIG"\n$N����һ����Х�����б����������Σ�ɢ��һƬ��Ļ��\n"NOR, me);
       	me->add_temp("apply/attack", 50);
      	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      	me->add_temp("apply/attack", -50);
       	me->start_perform(1, PFM_NAME);	
       	return 1;
}

int help(object me)
{
	write(HIG"\n\t����������" + perform_name() + HIG"����"NOR"\n");
	write(@HELP
			��Ȼ�߸���������·���ɽ�¸��١�
			����˫��һ�����������ˮ��ţ�ġ�
			
	���ʷ���֮ҹ��ɽɫ�������죬�����㾲��Ψ��������Խ��ˮ���ص�����
	��Ŀռ䡣����ˮ̶ǰϴ��̨�ϣ����ǻ�㱽���һ�����������뻯�����硣
	�����������˵�������֮�������������ѣ���ȴ�Լ��Ĵ��ڣ��·�������
	����Ȼ�ں�Ϊһ����������������������̫�ա��˾��пɵ���˫��ʹ�ã�
	����������ʽʽ���������ܻ�����أ�
	
	Ҫ��	
		���������ȼ� 300 ���ϣ�
		���������ȼ� 300 ���ϣ�
		���˹����ȼ� 300 ���ϣ�
		������� 6000 ���ϣ� 
		���� 1000 ���ϡ�
HELP
	);
	return 1;
}

