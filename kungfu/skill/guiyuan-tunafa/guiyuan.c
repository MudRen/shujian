// focus.c, ���� by darken@SJ
// By Spiderii@ty����Ч��
#include <ansi.h>

inherit F_CLEAN_UP;
void remove_effect(object me,int count);
string exert_name(){ return HBBLU"��Ԫ����"NOR; }

int exert(object me)
{      
int skill;
       skill = me->query_skill("guiyuan-tunafa");
if( !me->is_fighting() && (int)me->query_skill("guiyuan-tunafa",1)<350 )
                return notify_fail("��ֻ����ս����ʹ�á���Ԫ��������\n");

        if( (int)me->query_skill("guiyuan-tunafa", 1) < 100 )
                return notify_fail("��Ĺ�Ԫ���ɷ�����Ϊ��������\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if(me->query_temp("tz/focus"))
                return notify_fail("���Ѿ���ʹ���ˡ�\n");

        message_vision(HBBLU"$Nһ�������ϵ������ƺ���ǿ�ˡ�\n" NOR, me);
        me->start_busy(1);
       me->add_temp("apply/strength", me->query_skill("guiyuan-tunafa", 1)/15);
       me->add_temp("apply/attack", me->query_skill("guiyuan-tunafa", 1)/10);
        me->add("neili", -400);
        me->set_temp("tz/focus",skill /10);
call_out("remove_effect", 1, me, skill);
me->start_exert(1, "����Ԫ������");
        return 1;
}
void remove_effect(object me, int count)
{
if (!me) return;
if( count < 1){
me->delete_temp("tz/focus");
        
           me->add_temp("apply/strength", -me->query_skill("guiyuan-tunafa", 1)/15);
           me->add_temp("apply/attack", -me->query_skill("guiyuan-tunafa", 1)/10);
            message_vision(HIW"$N�˹���ϣ��������������ָ��糣��\n"NOR, me);

            return;

        }
call_out("remove_effect", 1 , me ,count -1);
}

