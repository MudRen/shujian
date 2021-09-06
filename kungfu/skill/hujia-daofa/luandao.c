// luandao.c   ���ҵ���֮���ҵ�����.
// Create by lsxk@hsbbs 2007/5/11
#include <ansi.h>

inherit F_SSERVER;
private int remove_effect(object me, int amount);
string perform_name() {return HIR"�ҵ���"NOR;}
int perform(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("���ҵ�����ֻ����ս����ʹ�á�\n");

        if ((int)me->query_skill("hujia-daofa", 1) < 200 )
                return notify_fail("��ĺ��ҵ���������죬���ò������ҵ�������\n");
    
        if (!weapon 
         || weapon->query("skill_type") != "blade"
//         || me->query_skill_mapped("parry") != "hujia-daofa"
         || me->query_skill_mapped("blade") != "hujia-daofa")
                return notify_fail("����书���ò��ԣ��޷�ʹ�á��ҵ�������\n");
    
        if ((int)me->query("neili") < 800 )
                return notify_fail("����������̫��������ʹ�á��ҵ�������\n");

        if ((int)me->query("jingli") < 800 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á��ҵ�������\n");

        if ((int)me->query("max_neili") < 2500 )
                return notify_fail("�����ڵ�������Ϊ����������ʹ�á��ҵ�������\n");

        if ((int)me->query_temp("hjdf/ldj"))
                return notify_fail("������ʹ�á��ҵ�����������\n"); 


        message_vision(HIY "$N��ʱ���α�죬����"+weapon->name()+HIY"���ƴ���,ֱ�ȶ��ַ�������ʱ,�˵���ʤ,�������Ǻ��ҵ���֮���ҵ�����������\n"NOR,me);

        if (me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
        && me->query_temp("lqsg/lq")
       && me->query_skill_mapped("force") == "lengquan-shengong")
            message_vision(HIB"��$N����Ȫ��֮��"HIW"��Ȫ"HIB"����������£�����"+weapon->name()+HIB"�����ط�����ɫ��\n"NOR, me);
        me->start_perform(random(4)+1,"���ҵ�����");
        me->add("neili", -400);
        me->add("jingli", -200);
    
        skill = me->query_skill("hujia-daofa", 1);
        me->add_temp("apply/damage",  skill/4);
        me->add_temp("apply/attack",  skill/4);
        me->set_temp("hjdf/ldj", 1);

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
        me->delete_temp("hjdf/ldj");
        if(living(me) && !me->is_ghost())
           message_vision(HIG"$Nһ�ס��ҵ�����ʹ�꣬�����ָֻ���������\n"NOR, me);
        return 0;
}

int help(object me)
{
   write(WHT"\n���ҵ�����"HIR"�ҵ���"WHT"����"NOR"\n");
   write(@HELP
   �ˡ��ҵ�������Ϊ���ҵ���֮�м����ԣ�������ز�¶��ֻ��
   ���ִ���ʱ�����ڶ����Գ��ش�����Ӷ��˵���ʤ��ʹ�ø���
   ʱ��Ҳ���ʱ�������ʹ���ߵĹ������������ʣ������ǳ���
   ��ʹ���߻����־�ѧ��Ȫ��֮����Ȫ�����������ศ��ɣ�
   �������ˣ�

   Ҫ��  ���� 800 ���ϣ�
           ���� 800 ���ϣ�
           ������� 2500 ���ϣ�
           ���ҵ��� 200 ���ϣ�
           �������� 200 ���ϣ�

HELP
   );
   return 1;
}
