// �����Ʒ� -- ������һ
// Modified by snowman@SJ 19/12/2000
// By Spiderii ����450 lv��س�tianlei
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string perform_name(){ return HBBLU"������һ"NOR; }
int perform(object me, object target)
{
        int j;

        if( !target ) target = offensive_target(me);
        if( !target 
          || !me->is_fighting(target)
          || !objectp(target)
          || environment(target)!= environment(me))

                return notify_fail("��������һ��ֻ����ս���жԶ���ʹ�á�\n");



        if( me->query_temp("weapon")) {
            if( me->query_temp("tzzf") ){
                if ( (int)me->query_skill("tiezhang-zhangfa",1) < 220 ) 
                    return notify_fail("�������ֲ���ʹ�á�������һ����\n");
                 }
            else 
                return notify_fail("�������ֲ���ʹ�á�������һ����\n");
        }

        if( (int)me->query_skill("tiezhang-zhangfa", 1) < 200 )
                return notify_fail("��������Ʒ���������죬ʹ������������һ��������\n");

/*        if( (int)me->query_skill("guiyuan-tunafa", 1) < 200 )
                return notify_fail("��Ĺ�Ԫ���ɷ��ȼ�������ʹ������������һ��������\n");

        if (me->query_skill_mapped("force") != "guiyuan-tunafa")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
*/
        if( (int)me->query_skill("force") < 230 )
                return notify_fail("����ڹ��ȼ�����������ʹ�á�������һ����\n");

        if( (int)me->query_str() < 33 )
                return notify_fail("�������������ǿ����ʹ������������һ������\n");

        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa"
         || me->query_skill_mapped("strike") != "tiezhang-zhangfa"
         || me->query_skill_mapped("parry") != "tiezhang-zhangfa")
                return notify_fail("�������޷�ʹ�á�������һ����\n");                                                                                 

/*        if( me->query_skill_mapped("force") != "guiyuan-tunafa")
                return notify_fail("�����ڵ��ڹ��ò��ˡ�������һ����\n");   
*/        
        if( (int)me->query("max_neili") < 1500)
                return notify_fail("����������̫����ʹ������������һ����\n");      

        if( (int)me->query("neili") < 1000 )
                return notify_fail("����������̫����ʹ������������һ����\n");


   j = (int)me->query_skill("tiezhang-zhangfa", 1);
        message_vision(HIW"\n$N����������ͻȻ����΢�࣬�����������ͽ�ֱ��$n��\n"NOR, me, target);

       if(me->query_temp("tzzf")) 
           j = j + random(j);
        me->add_temp("apply/strike", j);
        me->add_temp("apply/damage", j/2);
        me->add_temp("apply/attack", j);
        me->set_temp("tz/heyi", 1);
       if((int)me->query_temp("tzzf")) COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        else COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        me->set_temp("tz/heyi", 2);
        if(me->is_fighting(target)){
           if(random(me->query("combat_exp",1)) > target->query("combat_exp", 1)/2
           || me->query_temp("tzzf") )
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                else
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        }
        me->delete_temp("tz/heyi");
        me->add_temp("apply/strike", -j);
        me->add_temp("apply/damage", -j/2);
        me->add_temp("apply/attack", -j);
        if( me->query_skill("tiezhang-zhangfa",1) > 450 ){
                tell_object(me, HIY"\n������������һ�䣬��ʼ�����ش��ġ�������������\n"NOR);
                me->start_call_out( (: call_other, __DIR__"tianlei", "tianlei_hit", me, 2 :), 1 );
        }
        me->add("neili", -500);
        me->add("jingli", -100);
        me->start_busy(random(2));
        me->start_perform(5,"��������һ��");
        return 1;
}

int help(object me)
{
        write(WHT"\n�����Ʒ���������һ����"NOR"\n");
        write(@HELP
        ������ǧ�����ƹ���ʮ������֮һ��������������һ���������Ͷ��ޱȡ�
        ���Ҿݰ��л���˵�������������ڴ���֮�����һʽɱ�У�
        
        Ҫ��  ���� 1000 ���ϣ�      
                ������� 1500 ���ϣ�
                ���� 100 ���ϣ�  
                �������� 33 ���ϣ�
                �����Ʒ��ȼ� 140 ���ϣ�
                ��Ԫ���ɷ��ȼ� 140 ���ϣ�    
                �����ޱ�����
HELP
        );
        return 1;
}
