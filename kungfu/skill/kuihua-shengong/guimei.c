//by action 6/7/2008
//��������

#include <ansi.h>
#include <skill.h>
#include <combat.h>

string exert_name(){ return MAG"����"NOR; }
inherit F_SSERVER;

int exert(object me)
{
       	string msg;
       	int i;
	object target;
	
	if(!target)
		target = offensive_target(me);
		
	if( (int)me->query_skill("force",1) < 100 )
                return notify_fail("����ڹ����������ʹ���������ȡ�������\n");  
                
       	if( (int)me->query_skill("kuihua-shengong",1) < 100 )
                return notify_fail("��Ŀ����񹦻��������ʹ���������ȡ�������\n");  
                
       	if( (int)me->query("max_neili",1) < 3000 )
                return notify_fail("���������Ϊ���������ʹ���������ȡ�������\n"); 
                 
       	if( (int)me->query("jingli", 1) < 1000 )
                return notify_fail("�����ھ���������\n");
                
       	if( (int)me->query("neili", 1) < 2000 )
                return notify_fail("����������������\n");
                
       	if (me->query_temp("khsg/gm"))
                return notify_fail("������ʹ�á����ȡ���\n");

       	msg = HIC "$N΢һ������������ķ�����������ͬ����������һ�㣬Ʈ������"
        HIB"  ��������\n\n"NOR; 

       	me->add("neili", -(200+random(300)));
       	me->add("jingli", -(100+random(50)));
       	message_vision(msg, me, target);
       	i = me->query_skill("kuihua-shengong", 1)/20 + me->query_int()/5;
       	i = i*2 - random(i/2);
       	if (me->query_skill("kuihua-shengong", 1) < 150)
       		i = i/2;
       	me->add_temp("apply/dexerity", i);
       	me->add_temp("apply/dodge", i*2);
       	me->add_temp("apply/attack", i/4);
       	me->add_temp("apply/parry", i/4);
       	me->add_temp("apply/constitution", i/5);
       	me->add_temp("apply/strength", i/5);
       	me->set_temp("khsg/gm", i);
       	me->start_perform(2, "�����ȡ�");
       	call_out("remove_effect", 1, me, i, i);
       	return 1;
}

void remove_effect(object me, int count,int dex,int con,int str)
{
        if (!me) 
        	return;
        if( me->query_skill_mapped("force") != "kuihua-shengong" 
        || me->query("neili") < 100
        || count < 1)
        {
           	me->add_temp("apply/dexerity", -dex);
            me->add_temp("apply/dodge", -dex*2);
            me->add_temp("apply/attack", -dex/4);
            me->add_temp("apply/parry", -dex/4);
       	    me->add_temp("apply/constitution", -dex/5);
       	    me->add_temp("apply/strength", -dex/5);
           	me->delete_temp("khsg/gm");
           	tell_object(me,HIW"��ġ�"HIR"������"HIW"��֮��"HIB"�� ��"HIW"������������ϣ�ȫ�����һ�٣��ֳ��������Ρ�\n"NOR);
           	return;
        }
 	call_out("remove_effect", 1 , me, count -1,dex);
}
