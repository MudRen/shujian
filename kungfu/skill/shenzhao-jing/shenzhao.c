// By Spiderii�޸� shenzhao.c

#include <ansi.h>
void remove_effect(object me,int skill);

int exert(object me)
{      
       int skill;
       skill = me->query_skill("shenzhao-jing");
	if ( !me->is_fighting())
		return notify_fail("��ֻ����ս����ʹ�á����ա���\n");

	if( (int)me->query_skill("shenzhao-jing", 1) < 120 )
		return notify_fail("������վ���Ϊ�������޷�ʹ�á����ա���\n");

	if (me->query_skill_mapped("force") != "shenzhao-jing")
		return notify_fail("�����ڹ��С����ա���\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("��Ŀǰ������̫���ˣ��޷�ʹ�á����ա���\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ��ô�����ʹ�á����ա���\n");

	if( me->query_temp("sjz_power"))
		return notify_fail("���������á����ա���\n");

	message_vision(HIW"\n$N����һ��������Ϣ���������������������ӣ���ʱ�о�����������Ȼ���ˣ���Ȼ������\n\n" NOR, me);
        if(me->query_skill("shenzhao-jing",1)<=450) me->start_busy(1);
       me->add_temp("apply/dodge", me->query_skill("shenzhao-jing", 1)/4);
       me->add_temp("apply/parry", me->query_skill("shenzhao-jing", 1)/4);
       me->add_temp("apply/attack", me->query_skill("shenzhao-jing", 1)/4);
       if(me->query("env/����"))
       	       me->add_temp("apply/armor", me->query_skill("shenzhao-jing", 1));
       	
	me->add("neili", -400);
	me->set_temp("sjz_power",1);
	call_out("remove_effect", 1, me, skill);
	me->start_exert(2, "�����ա�");
	return 1;
}
void remove_effect(object me, int skill)
{
	
	 if (objectp(me)) {
                if (me->is_fighting()) {
                        call_out("remove_effect", 1, me, skill);
                        return;
                }

           me->delete_temp("sjz_power");
	    
           me->add_temp("apply/dodge", -me->query_skill("shenzhao-jing", 1)/4);
           me->add_temp("apply/parry", -me->query_skill("shenzhao-jing", 1)/4);
           me->add_temp("apply/attack", -me->query_skill("shenzhao-jing", 1)/4);
    
        if(me->query("env/����"))
           me->add_temp("apply/armor", -me->query_skill("shenzhao-jing", 1));
	    message_vision(HIR"\n$N����������һ������ɢȥ�˻���������\n"NOR, me);
	    return;

	}
}


int help(object me)
{
        write(WHT"\n���վ������ա���"NOR"\n");
        write(@HELP
        ��������ī��÷���������������̶����һ���ڹ����ؾ�
        ����ϰ�ô��ڹ������ִ��ڵ��ƣ����ƿ��Ķ��꣬���վ�
        ��ϰ�õڶ����硣������Ե�õ�����ָ�㣬�ɸ���һ��¥
        
        Ҫ��:   ���� 1500 ���ϣ�
        Ч��:   Ч��һ���ӹ�����
                Ч�������Ӷ�ܡ�
        
HELP
        );
        return 1;
}

