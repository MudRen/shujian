// leiting �������
//����ֻ�Ǹ������ļ���
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	    object weapon;
	 if( !target ) target = offensive_target(me);
  
    if( !target  
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("�����������ֻ����ս����ʹ�á�\n");
/*
        if(me->query("eff_qi") > me->query("max_qi")*2/3)
		return notify_fail("Ŀǰ������Ǻ�Σ����û��Ҫʹ�á������������\n");
  */      
	if( (int)me->query_skill("songshan-jian", 1) < 160 )
		return notify_fail("�����ɽ������������죬�޷�ʹ���������������\n");

	if( (int)me->query_skill("force", 1) < 160 )
		return notify_fail("����ڹ��ȼ����������޷�ʹ���������������\n");

	if (me->query_skill_mapped("force") != "hanbing-zhenqi")
		return notify_fail("��Ŀǰ���ڹ��޷�ʹ���������������\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "sword"
	|| me->query_skill_mapped("sword") != "songshan-jian")
		return notify_fail("���޷�ʹ���������������\n");
              
	if( (int)me->query("max_neili") < 2500)
		return notify_fail("���������Ϊ̫��޷�ʹ���������������\n");

     	if( (int)me->query_temp("ssj/leiting") )
		return notify_fail("���Ѿ������������ʹ�á������������\n");   
        
	if( (int)me->query("neili") < 1000)
		return notify_fail("����������̫����ʹ�����������������\n");
		
 message_vision(HIW"\n$N��������"+weapon->name()+HIW"�������׼��$n�ؿڣ��������Ĺ������˵�������֮�ϡ�
$N��������������������ƳԱ��˷�ķ���һ�㣬��һ��֮���������������֮�ơ�\n"NOR,me,target);
  	         me->set_temp("ssj/leiting",1);
//if(!userp(target)) target->add_busy(2);
 	me->add("jingli", -80);
if(me->query_skill("songshan-jian",1)<=450 )
        me->start_perform(3, "�������");

        return 1;
}

string perform_name(){ return YEL"�������"NOR; }

int help(object me)
{
        write(YEL"\n��ɽ����֮�������������"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 2500 ���ϣ�
                ��ǰ���� 1000 ���ϣ�
                ��ɽ�����ȼ� 160 ���ϣ�
                �ڹ�    �ȼ� 160 ���ϣ�
                ��Ч�ڹ��ȼ� 250 ���ϣ�
                ��������Ϊ��ɽ������
                �����ڹ�Ϊ����������
                ���ֱֳ�����


HELP
        );
        return 1;
}
