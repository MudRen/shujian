// feidao.c   ���ҵ���֮���ɵ�����.
// Create by lsxk@hsbbs 2007/5/11
#include <ansi.h>

inherit F_SSERVER;
private int remove_effect(object me, int amount);
string perform_name() {return HIC"�ɵ���"NOR;}
int perform(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("���ɵ�����ֻ����ս����ʹ�á�\n");

        if ((int)me->query_skill("hujia-daofa", 1) < 100 )
                return notify_fail("��ĺ��ҵ���������죬���ò������ɵ�������\n");
    
        if (!weapon 
         || weapon->query("skill_type") != "blade"
         || me->query_skill_mapped("parry") != "hujia-daofa"
         || me->query_skill_mapped("blade") != "hujia-daofa")
                return notify_fail("����书���ò��ԣ��޷�ʹ�á��ɵ�������\n");
    
        if ((int)me->query("neili") < 400 )
                return notify_fail("����������̫��������ʹ�á��ɵ�������\n");

        if ((int)me->query("jingli") < 400 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á��ɵ�������\n");

        if ((int)me->query_temp("hjdf/fdj"))
                return notify_fail("������ʹ�á��ɵ�����������\n"); 


        message_vision(HIC "$N��ʱһ����ȣ�����"+weapon->name()+HIC"����һ��,ʹ�����ҵ���֮���ɵ�����������\n"+
        "���ҵ�����������һ���������֣������˳��к�Ѱ������������֮��$N��·����ʹ��������������Ȼ����������\n"+
        "���Ժ�ÿ��һ�б��ǹ����������֮��������֮��˾�ǧ��Ҳ��\n"NOR, me);

        if (me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
        && me->query_temp("lqsg/lq")
        && me->query_skill_mapped("force") == "lengquan-shengong")
            message_vision(HIW"��$N����Ȫ��֮��"HIB"��Ȫ"HIW"����������£�����"+weapon->name()+HIW"�����ط��Ű�ɫ��\n"NOR, me);
        me->start_perform(random(3),"���ɵ�����");
        me->add("neili", -200);          
        me->add("jingli", -100);
    
        skill = me->query_skill("hujia-daofa", 1);
        me->add_temp("apply/damage",  skill/4);
        me->add_temp("apply/attack",  skill/4);
        me->set_temp("hjdf/fdj", 1);

        me->start_call_out( (: call_other, __FILE__, "check_fight", me, skill, weapon :), 1);
        return 1;
}

void check_fight(object me, int amount, object weapon)
{  
        object wep;

        if (!me) return;
        wep = me->query_temp("weapon");  
        if(!me->is_fighting()
         || !living(me)
         || me->is_ghost()
         || me->query_skill_mapped("parry") != "hujia-daofa"
         || !wep
         || weapon != wep )
           remove_effect(me, amount);
        else call_out("check_fight", 1, me, amount, weapon);
}

private int remove_effect(object me, int amount)
{         
        int skill;
        skill = (int)me->query_skill("hujia-daofa", 1);
 
        me->add_temp("apply/damage",  -skill/4);
        me->add_temp("apply/attack",  -skill/4);
        me->delete_temp("hjdf/fdj");
        if(living(me) && !me->is_ghost())
           message_vision(HIW"$Nһ�ס��ɵ�����ʹ�꣬�����ָֻ�������״̬��\n"NOR, me);
        return 0;
}

int help(object me)
{
   write(WHT"\n���ҵ�����"HIC"�ɵ���"WHT"����"NOR"\n");
   write(@HELP
   �ˡ��ɵ�������Ϊ���ҵ���֮�������ԣ���ȴ�����˺��ҵ���
   �ľ��衰������죬Ѱ�������������ˡ���ʹ��ʱ���ܶ�ʱ
   ����������������������ʣ����Ⲣ����ȫ����ֻ�е�����
   �ɹ����������󣬲���������ʾ�����е�����������ʹ���߻�
   ���־�ѧ��Ȫ��֮����Ȫ�����������ศ��ɣ��������ˣ�

   Ҫ��  ���� 400 ���ϣ�
           ���� 400 ���ϣ� 
           ���ҵ��� 100 ���ϣ�
           �������� 100 ���ϣ�
           �������ҵ���Ϊ�мܣ�

HELP
   );
   return 1;
}
