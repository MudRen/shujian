// modified by snowman@SJ 05/12/2000
// By Spiderii�����޸ġ���ͼʡ�¡���grin
// by spiderii@ty ����Ч��
#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>

int perform(object me,object target)
{
        object weapon;
        string msg;
        int i = me->query_skill("huifeng-jian",1) / 4;

        if( !target ) target = offensive_target(me);

         if( !objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("����ķ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query_skill_mapped("force") != "linji-zhuang")
                return notify_fail("����ڹ����Ƕ����ķ����޷�ʹ������ķ���\n");
        if( me->query_skill("linji-zhuang", 1) < 150 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ������ķ���\n");
        if( me->query_skill("huifeng-jian", 1) < 150 )
                return notify_fail("��Ľ�����δ���ɣ�����ʹ������ķ���\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "huifeng-jian")
                return notify_fail("������û�н����޷�ʹ������ķ���\n");

        if(me->query_skill_mapped("parry") != "huifeng-jian")
                return notify_fail("����мܹ��򲻶ԣ��޷�ʹ������ķ���\n");
        if(me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ����������ʹ������ķ���\n");
        if(me->query("neili") < 1000 )
                return notify_fail("�������������㣬����ʹ������ķ���\n");
        if(me->query("jingli") < 750 )
                return notify_fail("�����ھ������㣬����ʹ������ķ���\n");
        if(me->query_temp("miejue"))
                return notify_fail("������ʹ������ķ���\n");
        if(me->query_skill("sword", 1) < 150 )
                return notify_fail("��Ļ�������������죬�����ڽ�����ʹ������ķ���\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        msg = HIW "$NƮ�����ʹ�����Ҿ������𽣡��ķ�����ʱ�������Ʈ�ݶ�������ǧ�������裬����ͷ����������\n"NOR;
        me->start_perform(1+random(4),"������ķ���"); 
        if((random(me->query_skill("dodge",1)) * me->query_int()) >
        (target->query_skill("dodge",1) * target->query_int())/2) {
                msg = msg + HIG "���$n���һ��������֮��������������$N���˸����ֲ�����\n" NOR;
                target->add_busy(random(i/10) + 2);
                me->add_temp("apply/attack", i);
                me->add_temp("apply/damage",  i);
                me->add_temp("apply/sword",  i);
                me->set_temp("miejue", 1);
                call_out("next1", 1, me, target, i);
        }
        else
                msg = msg + CYN "����$n�侲�Ƿ���˿����Ϊ����õ���������������ֵ�����©���������\n" NOR;

        message_vision(msg, me, target);
        return 1;
}

int next1(object me, object target, int i)
{
        string msg;
        int damage;
        object weapon;

        if (!me) return 0;

        weapon = me->query_temp("weapon");
        if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
                me->add_temp("apply/attack", -i);
                me->add_temp("apply/damage",  -i);
                me->add_temp("apply/sword",  -i);
                me->delete_temp("miejue");
                return 0;
        }

        msg = HIC "$N����һ��������������ټ�ʮ��ׯ,��ϡ��𽣡�,ʹ�����������ķ���\n"NOR;

        if((random(me->query("max_neili")) + me->query_skill("force",1)) >
            (target->query("max_neili") + target->query_skill("force",1))/4 ){
                msg = msg + HIG"$nֻ��$N�𽣡���������쳣�������ѹ��������\n"NOR;
                damage = me->query_skill("huifeng-jian",1);
                damage += me->query_skill("sword",1);
                damage += random(damage);

                target->add("neili",-(500+random(150)));
                target->add_condition("no_exert",1+random(2));    // �𽣡���������쳣�������ѹ������
                target->add_condition("no_perform",1+random(2)); //���˵�2�������Ż�����Ч����
                message_vision(msg, me, target);
                COMBAT_D->report_status(target, random(2));
                me->add("neili",-300);
                me->add("jingli",-100);
        } else {
                msg  =  msg + CYN"$n��Σ���ң����²������䣬���㿪����\n"NOR;
                message_vision(msg, me, target);
                me->add_busy(1+random(2));
        }
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage",  -i);
        me->add_temp("apply/sword",  -i);
        me->delete_temp("miejue");

        
        return 1;
}
string perform_name(){ return HIW"����ķ�"NOR; }

int help(object me)
{
        write(HIW"\n�ط������֮������ķ�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 2000 ���ϣ�
                ��ǰ���� 750 ���ϣ�
                �ط�������ȼ� 150 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 150 ���ϣ�
                �����ڹ�Ϊ�ټ�ʮ��ׯ��
                ��������Ϊ�ط��������
                �����м�Ϊ�ط��������
                �ֱֳ�����

HELP
        );
        return 1;
}


