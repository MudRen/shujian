// /kungfu/skill/liuyang-zhang/jie.c 
//modified by zhuifeng@SJFY 2010/07/17

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target )
{
        string msg;
        int pow;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("��Ҫ��˭����������\n");

        if(target == me)
                return notify_fail("���޷����Լ�����������\n");

        if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
                return notify_fail("�����ɽ�����Ʋ�����죬���ܽ���������\n");

        if(!target->query_condition("shengsi_poison"))
        return notify_fail("�Է���û����������������Ҫ�����ڡ�\n");

        if( (int)me->query("neili") < 3000 )
                return notify_fail("����������̫�������ܽ���������\n");

 if(me->query("family/family_name") != "��ң��"&& me->query("family/family_name") != "���չ�") 
           return notify_fail("���ֲ������չ���������������ν���������\n");

        me->add("neili", -3000);
        msg = HIC "$Nʹ����ɽ�����ƣ��������������ַ������ٵ�����$n�������Ѩ��\n"NOR;

        pow=((int)me->query_skill("liuyang-zhang",1)
             +(int)me->query_skill("bahuang-gong",1))/5;
        pow=pow+random(pow);

        if(target->query_condition("shengsi_poison")<=pow)
        {
         target->clear_condition("shengsi_poison");
         msg +=HIW"$N���˲���ͷ�Ĵ󺹣�����һ����������$n�������е�����"
               +"���Ѿ�ȫ���γ��ˡ�\n"NOR;
        } else
        {
        target->apply_condition("shengsi_poison",
                                target->query_condition("shengsi_poison")-pow);
        msg +=HIR"$Nͷ���������ƣ�Ƭ�̾���$N��$n���������У�һ���$Nվ����"
                  +"������¶��Ȼ֮ɫ��\n"
                  +"����$N��û���ҵ��취��ȫ�γ�$n���ϵ���������\n"NOR; 
        }
        me->start_busy(pow/10);       

        message_vision(msg, me, target);
        return 1;
}
string perform_name(){ return HIC"��������"NOR; }

int help(object me)
{
	write(YEL"\n��ɽ������֮��������������"NOR"\n");
	write(@HELP

	Ҫ��
	��ǰ���� 3000 ���ϣ�
        ������� 3000 ���ϣ�
        �˻�����Ϊ�Ҷ��𹦵ȼ� 200 ���ϣ�
        �ڹ���Ч�ȼ� 200 ���ϣ�
HELP
	);
	return 1;
}