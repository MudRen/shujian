// By Spiderii@ty����
#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
       	string msg;
       	int i;
	object target;
	
	if(!target)
		target = offensive_target(me);
	if( (int)me->query_skill("force",1) < 300 )
                return notify_fail("����ڹ����������ʹ��������\n");  
       	if( (int)me->query_skill("lingbo-weibu",1) < 150 )
                return notify_fail("����貨΢�����������ʹ��������\n");  
       	if( (int)me->query("max_neili",1) < 3000 )
                return notify_fail("���������Ϊ���������ʹ��������\n");  
       	if( (int)me->query("jingli", 1) < 500 )
                return notify_fail("�����ھ���������\n");
       	if( (int)me->query("neili", 1) < 200 )
                return notify_fail("����������������\n");
       	if (me->query_temp("lbwb/ls"))
                return notify_fail("������ʹ������\n");

       	msg = HIC "$NԽ��Խ�죬�����������֮��,��Ϣ���Ų�����ס��ת,ת�ۼ�������һ����\n\n"NOR; 

       	me->add("neili", -(200+random(300)));
       	me->add("jingli", -(100+random(50)));
       	message_vision(msg, me, target);
        i = me->query_skill("lingbo-weibu", 1)/10 + me->query("int")/5;
        i = i - random(i/3);
       	if (me->query_skill("lingbo-weibu", 1) < 450)
                i = i/3;
       	me->add_temp("apply/dexerity", i);
       	me->add_temp("apply/dodge", i*5);
       	me->set_temp("lbwb/ls", i);
       	me->start_perform(2, "����");
       	call_out("remove_effect", 1, me, i*10, i);
       	return 1;
}

void remove_effect(object me, int count,int dex)
{
        if (!me) 
        	return;
        if( me->query_skill_mapped("dodge") != "lingbo-weibu" 
        || me->query("neili") < 100
        || count < 1)
        {
           	me->add_temp("apply/dexerity", -dex);
                me->add_temp("apply/dodge", -dex*5);
           	me->delete_temp("lbwb/ls");
           	message_vision(HIW"$N�������ã�������������\n"NOR, me);
           	return;
        }
 	call_out("remove_effect", 1 , me, count -1,dex);
}
