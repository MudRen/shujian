// By Darken@SJ

#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;

string perform_name() { return HIG"������ת"NOR; }

int perform(object me)
{
       string msg;
       int i;

       if( !me->is_fighting() && (me->query_skill("suibo-zhuliu",1) < 400 ))
                return notify_fail("������תֻ����ս����ʹ�á�\n");
       if( (int)me->query_skill("bihai-chaosheng",1) < 150 )
                return notify_fail("��ı̺����������������ʹ����������ת��\n");  
       if( (int)me->query_skill("suibo-zhuliu",1) < 150 )
                return notify_fail("����沨�������������ʹ����������ת��\n");  
       if( (int)me->query_skill("qimen-bagua",1) < 150 )
                return notify_fail("������Ű��Ի��������ʹ����������ת��\n");  
       if( (int)me->query("jingli", 1) < 500 )
                return notify_fail("�����ھ���������\n");
       if( (int)me->query("neili", 1) < 200 )
                return notify_fail("����������������\n");
       if (me->query_temp("thd/is_fast"))
                return notify_fail("������ʹ��������ת��\n");

       msg = HIW "$Nһ����Х��ʹ���һ����ľ�ѧ������ת����̤�Ű��Է�λ����������ʵʵ���������ȣ�����Ȼ�ӿ죡\n\n"NOR; 

       me->add("neili", -(200+random(300)));
       me->add("jingli", -(100+random(50)));
       message_vision(msg, me);
       i = me->query_skill("qimen-bagua", 1)/10 + me->query_skill("qimen_baguazhen",1)/20 + me->query_skill("dodge")/10;
       me->add_temp("apply/dexerity", i);
       me->set_temp("thd/is_fast", i);
       me->set_temp("double_attack", 1);
       if (me->query_skill("suibo-zhuliu",1) < 400) me->start_perform(1, "������ת");
       call_out("remove_effect", 1, me, i, i);
       return 1;
}
void remove_effect(object me, int count, int dex)
{
        if (!me) return;
        if( me->query_skill_mapped("dodge") != "suibo-zhuliu" 
         || (!me->is_fighting() && (me->query_skill("suibo-zhuliu",1) < 400 ))
         || me->query("neili") < 100
         || count < 1){
                me->add("neili", - (25 + random(25)));
                me->add_temp("apply/dexerity", -dex);
                me->delete_temp("thd/is_fast");
                me->delete_temp("double_attack");
                message_vision(HIW"$N�������ã�������������\n"NOR, me);
                return;
        }
        call_out("remove_effect", 1 , me, count -1, dex);
}

int help(object me)
{
        write(HIG"\n��������ת����"NOR"\n");
        write(@HELP

        ��ҩʦ����֮��������ʹ�����Ű�������沨����������ʹ�ж�����ֳ�
        �����ϣ��޷�Ԥ�⣬������������Լ����еĻ��ʣ�ͬʱҲ�ӿ칥�����ٶ�
        �Ƕ��ַ���ʤ������������һ������⼼�ɣ������°빦����

        Ҫ��  �̺������ȼ� 150 ���ϣ�
                ���Ű��Եȼ� 150 ���ϣ�
                �沨�����ȼ� 150 ���ϣ�
                ÿ�غ�����������
                �沨�����ȼ� 400 ���ϣ��ɷ�ս��ʩչ��
                �沨�����ȼ� 400 ����ʹ��ʱ��������ʱ�䡣
HELP
        );
        return 1;
}

