// roudao.c ���ҵ���֮���ᵶ����
// Create By lsxk@hsbbs 2007/5/12

#include <ansi.h>

inherit F_SSERVER;
string perform_name() {return HIG"�ᵶ��"NOR;}
int perform(object me, object target)
{
        string msg;
        object weapon = me->query_temp("weapon");
        int busy;

        if( !target ) target = offensive_target(me);

         if( !objectp(target)
          ||!target->is_character()
          ||!me->is_fighting(target) )
                return notify_fail("���ᵶ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("hujia-daofa", 1) < 100 )
                return notify_fail("��ĺ��ҵ���������죬����ʹ�á��ᵶ������\n");

        if ((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������������죬����ʹ�á��ᵶ������\n");

        if ((int)me->query_skill("force", 1) < 100 )
                return notify_fail("��Ļ����ڹ�������죬����ʹ�á��ᵶ������\n");

        if (!weapon
         || weapon->query("skill_type") != "blade"
         || me->query_skill_mapped("blade") != "hujia-daofa")
//         || me->query_skill_mapped("parry") != "hujia-daofa")
                return notify_fail("�����ʹ�ú��ҵ�������ʹ�á��ᵶ������\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("����������̫��������ʹ�á��ᵶ������\n");

        if( target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        msg = HIG "$N��ʽһ�侹ʹ�����ҵ���֮���ᵶ����!����һ����$N����������û�����������ȴ���ᾢ�����о�����$n�����ߣ���\n";

        me->add("neili", -200);
        me->add("jingli", -140);
        busy = (int)me->query_skill("hujia-daofa", 1)/30;
        if(random(me->query("combat_exp")) >  target->query("combat_exp")*2/5
           ||random(me->query_skill("force"))>target->query("force")/2 ){
                msg += "���$pһ�����⣬����$P�����޷����У����°����Ծ�����\n" NOR;
                target->start_busy(4+random(4));
                me->start_perform(6,"���ᵶ����");
               me->set_temp("hjdf/rdj",1);
                call_out("check_fight", 1, me, target, weapon, 7); 
        } else {
                msg += "$p���һ�������������Ṧ������$P�ĵ��з�Χ����Ҳ������������\n" NOR;
                me->start_busy(2);
                target->add("neili",-600);
                target->apply_condition("no_perform",1);
        }
        message_vision(msg, me, target);
        return 1;
}

void check_fight(object me,object target,object weapon,int count)
{
        if (!target) return;
       if( !me
        || !me->is_fighting(target)
        || weapon != me->query_temp("weapon")
        || me->query_skill_mapped("blade") != "hujia-daofa"
        || count < 1){
                if (me) {
                        me->delete_temp("hjdf/rdj");
                }
                return;
       }
       call_out("check_fight", 1, me,target,weapon,count -1);
}

int help(object me)
{
   write(WHT"\n���ҵ�����"HIG"�ᵶ��"WHT"����"NOR"\n");
   write(@HELP
   �ˡ��ᵶ�����������ھ�����Ϻ��ҵ����������ʽ������һ�����ֲ�����
   ������ʮ��������������ڹ���Ϊ��Խ�ȵ�����񣬳ɹ��ʾ�Խ�ߣ�

   Ҫ��  ���� 400 ���ϣ�
           ���ҵ��� 100 ���ϣ�
           �������� 100 ���ϣ�
           �����ڹ� 100 ���ϣ�

HELP
   );
   return 1;
}
