// bing.c ��ڤ���� ֮ ���ľ�
// modified by action@SJ 2009/2/5

#include <ansi.h>

inherit F_SSERVER;
string exert_name(){ return HIB"���ľ�"NOR; }

int exert(object me, object target)
{
        int attackp, defendp;

        if( !target ) target = offensive_target(me);

         if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("�����ľ���ֻ����ս����ʹ�á�\n");
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á����ľ�����\n");   
                
        if( (int)me->query_skill("liuyang-zhang", 1) < 250 )
                return notify_fail("�����ɽ�����ƻ�������죬ʹ���������ľ���������\n");
                
        if (me->query_skill_prepared("strike") != "liuyang-zhang"
            || me->query_skill_mapped("strike") != "liuyang-zhang")
                return notify_fail("�������޷�ʹ�á����ľ������й�����\n");  

        if( (int)me->query_skill("beiming-shengong", 1) < 250 )
                return notify_fail("��ı�ڤ�񹦵ȼ���������ʹ���������ľ���������\n");
                
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("����ڹ������޷�ʹ�á����ľ�����\n");  
                
        
        if( (int)me->query("neili") < 3000 )
                return notify_fail("����������㣬����ʩչ�����ľ�����\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("����������㣬����ʩչ�����ľ�����\n");

        if( (int)me->query("jingli") < 1000 )
                return notify_fail("��ľ������㣬����ʩչ�����ľ�����\n");

        if( target->is_busy()) 
                 return notify_fail("�Է����Թ˲�Ͼ�أ��㲻æʩչ�����ľ�����\n");
                

        attackp = me->query_skill("liuyang-zhang", 1) + me->query_skill("beiming-shengong", 1) + me->query_skill("force",1) / 3;
        defendp = target->query_skill("force") + target->query_skill("dodge");

        message_vision( HIG"$N����["HIB"����"HIG"]��������������������Ө��˸��"HIB"����"NOR+HIG"���ں�����ҫ�У���$nϮ����\n"NOR, me, target );

        if( attackp > defendp / 2 + random(defendp) / 2 || (!userp(target)&& me->query_skill("beiming-shengong")>=451 )) {
                message_vision( HIW"������ҫ��"HIB"����"HIW"Χ����$n��ȫ���������۳�"WHT"����"NOR+HIW"����$n�������У�\n"NOR, me, target );

                target->start_busy(3+random(3));
                target->apply_condition("no_fight",1+random(2));

        }
        else {
                message_vision(HIC"$n������ǰ����һ��"HIB"����"NOR+HIC"���Լ�Ϯ��������һ�����ܶ㿪�ˡ�\n"NOR, me, target);
        }

        me->set_temp("bingxin",15+random(15));   
        me->add("neili", -200);
        me->start_busy(2);
        return 1;
}

int help(object me)
{
	write(HIW"\n��ڤ��֮�����ľ�����"NOR"\n\n");
        write(@HELP
	Ҫ��  �������  3000 ���ϣ�
          ��ǰ����  2000  ���ϣ�
          ��ǰ����  1000  ���ϣ�
          ��ڤ��  250  �����ϣ�
          ��ɽ������  250  �����ϣ�
          �����Ʒ�Ϊ��ɽ�����ƣ�
          ���Ʒ�Ϊ��ɽ�����ƣ�
HELP
        );
        return 1;
}
