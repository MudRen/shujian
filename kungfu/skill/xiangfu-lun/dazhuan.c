// 5lun_npc.c
// Created by snowman@SJ
// Modified by snowman@SJ 28/11/2000
// Modified by snowman@SJ 27/04/2001

#include <ansi.h>

inherit F_SSERVER;

string perform_name(){ return HIY"���ִ�ת"NOR; }

int perform(object me)
{
            object obj, weapon,weapon2;
    	weapon = me->query_temp("weapon");  
    
    	if( !me->is_fighting() )
                return notify_fail("�����ִ�ת��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
  	if ( (int)me->query_skill("longxiang-boruo", 1) < 180 )
        	return notify_fail("����ڹ��ȼ�����������ʹ�á����ִ�ת����\n");
    
    	if ( (int)me->query_skill("xiangfu-lun", 1) < 180 )
        	return notify_fail("��Ľ�ս����ַ�������죬ʹ���������ִ�ת����\n");
    
    	if ( objectp(obj = me->query_temp("dazhuan_npc")) && present(obj, environment(me)) ) {
    		message_vision(HIC "\n$N����һ�죬���֮���������ٻ��˷����ŵ����֣�\n"NOR, me);
    		obj->die();
    		me->start_perform(2 + random(2), "�����ִ�ת��");
        	return notify_fail("���ջ�������ʹ�õġ����ִ�ת����\n");
        }
        
    	if (!weapon || weapon->query("skill_type") != "hammer"
         || me->query_skill_mapped("hammer") != "xiangfu-lun")
        	return notify_fail("�������޷�ʹ�á����ִ�ת����\n");
    	if( weapon->query_amount() < 5 && weapon->query("id") != "fenghuo lun" && weapon->query("hammer_count") < 5 )
        	return notify_fail("����Ҫ������Ӳ���ʹ�á����ִ�ת����\n");
        if ( (int)me->query("max_neili") < 3800 )
        	return notify_fail("����������̫��������ʹ�á����ִ�ת����\n");
    	if ( (int)me->query("neili") < 1000 )
        	return notify_fail("����������̫��������ʹ�á����ִ�ת����\n");
        
    	if( me->query_skill_mapped("force") != "longxiang-boruo" )
        	return notify_fail("��Ŀǰ���ڹ��޷�֧����ʹ�á����ִ�ת����\n");

    	message_vision(HIC "\n$N��Ծ���ᣬ��ʱ���ء����ˡ����֮���������������������˸˸����ֻ���Ӵ������ͬ��λ��Ϯ������

			"HIG"������ "HIY"�� �� �� ת "HIG"������ \n\n"NOR, me);
    	me->start_busy(1);
            me->start_perform(3 + random(3), "�����ִ�ת��");
    	me->receive_damage("neili", 300);
    	me->receive_damage("jingli", 100);  
            obj = new(__DIR__"5lun_npc");
    	if( obj->move(environment(me)) ){
    		me->set_temp("dazhuan_npc", obj);
    		me->add_temp("apply/parry", 100);
    		me->add_temp("apply/armor_vs_force", 200);
                    if(weapon->query("id")=="fenghuo lun"){
                      weapon2 = new("/clone/weapon/5lun_weapon");
                      weapon2->move(obj);
                      obj->set_master_player(me, weapon2);
                     }
                    else{
                      weapon->unequip();
                      weapon->move(obj);
                      obj->set_master_player(me, weapon);
                    }
    	}
    	else write(HIR"\n�����ִ�ת��������֪ͨ��ʦ�� Obj cannot move to environment()\n\n"NOR);
    	return 1;
}

int help(object me)
{
        write(HIY"\n��ս�����֮�����ִ�ת����"NOR"\n");
        write(@HELP
        �������ڽ��ַ�����ɨ���������ԭ��һ�ֲ��ܽ�ս�����ʹ�ó����뻭��
        �ˡ����ִ�ת�������˷�������֮����ȫ������֮�����������������ַ�����
        ת���������������տ�ɽ�������ɵ�֮�������޼���
        
        Ҫ��  ����������ȼ� 180 ���ϣ�
                ��ս����ַ��ȼ� 180 ���ϣ�
                ������� 3800 ���ϣ�
                ���� 1000 ���ϣ�
                �������֡�
HELP
        );
        return 1;
}


