// ���������  action@SJ 2008/12/28
//modified by zhuifeng@SJFY 2010/07/17

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target,object tweapon)
{
        int i;

        if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("����������С�ֻ����ս����ʹ�á�\n");
                
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á���������С���\n");   
        tweapon = target->query_temp("weapon");
	      if( !tweapon )
		            return notify_fail("�Է�û��ʹ���κα��������޷�ʹ�á����־�����\n");
                
        if( (int)me->query_skill("zhemei-shou", 1) < 200 )
                return notify_fail("�����ɽ��÷�ֻ�������죬�޷�ʹ������������С�������\n");     
                
        if( (int)me->query_skill("hand", 1) < 200 )
                return notify_fail("��Ļ����ַ���������죬�޷�ʹ������������С�������\n");   
                
        if( (int)me->query_skill("force", 1) < 200 )
                return notify_fail("����ڹ���Ϊ���㣬�޷�ʹ������������С�������\n");                                                         

        if (me->query_skill_mapped("force") != "bahuang-gong" )
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("����ʹ�õ��ڹ����ԣ��޷�ʹ������������С���\n");  
                
        if ( me->query_skill_mapped("parry") != "zhemei-shou"
	            && me->query_skill_mapped("hand") != "zhemei-shou")
		            return notify_fail("�������޷�ʹ�á���������С���\n");
		            
		    if (me->query_skill_prepared("hand") != "zhemei-shou"
	             || me->query_skill_mapped("hand") != "zhemei-shou")
	              return notify_fail("�������޷�ʹ�á���������С���\n");

        if( (int)me->query_temp("rubairen") > 0 )
                return notify_fail(HIW"��ո��ù�����������С�����һ����ʹ�ðɡ�NOR\n"NOR);
                
        if( (int)me->query("max_neili", 1) < 3000 )
                return notify_fail("������������Ϊ���㣬�޷�ʹ������������С���\n");

        if( (int)me->query("neili", 1) < 2000 )
                return notify_fail("����������̫�����޷�ʹ������������С���\n");
                
        if( me->query("jingli") < 2000 )
		            return notify_fail("�����ھ�������, �޷�ʹ������������С�! \n");
		            
        i = me->query_skill("zhemei-shou",1);
        
        if( userp(me)&&tweapon && i > 150 && living(target)
	                   && random(me->query("combat_exp")) > target->query("combat_exp")/2 ) {
	                   	
		message_vision(HIC"$N�����]Ϣ��ʹ�����չ��^������������С���˫�ֿ�����$n�ɶ�������˫��������Ѹ�ٿ�ס$n����"+tweapon->name()+HIW"��\n"NOR, me,target);
		
		    if( random(me->query("str")) > target->query("str")/3 ) {
			        me->add("neili", -500);
			        me->start_perform(2+random(1),"����������С�");
			        message_vision(HIC"$nֻ��һ�������˱Ƕ������D�r�X����ǰһ��������һ�飬$n����"+tweapon->name()+HIC"Ó�ֶ�����\n"NOR, me,target);
			        tweapon->unequip();
			        tweapon->move(environment(target));
		}
		else {
			message_vision(HIC"����$n�Ŀ�������·�ߵ���D�����̲�ȡ�؄ݣ�ʹ$N�]�܊Z�±��У�\n"NOR, me,target);
              me->start_perform(3,"����������С�");
              me->add("neili", -500);
              me->start_busy(1+random(1));
		}
	} 
        return 1;
}

string perform_name(){ return HIC"���������"NOR; }

int help(object me)
{
	write(YEL"\n��ɽ��÷��֮"HIC"����������С���"NOR"\n");
	write(@HELP
	���չ���ɽͯ��֮������

	Ҫ��
	��ǰ���� 2000 ���ϣ�
	������� 3000 ���ϣ�
	��ǰ���� 2000���ϣ�
	��ɽ��÷�ֵȼ� 200 ���ϣ�
	�˻�����Ψ�Ҷ��𹦵ȼ� 200 ���ϣ�
	��ڤ�񹦵ȼ� 200 ���ϣ�
	�ڹ���Ч�ȼ� 200 ���ϣ�
HELP
	);
	return 1;
}
