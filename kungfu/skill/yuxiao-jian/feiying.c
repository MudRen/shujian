// feiying.c
// YUJ@SJ 2002-07-12

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int lvl,j, qi2;

        lvl = me->query_skill("yuxiao-jian", 1);
        lvl += me->query_skill("tanzhi-shentong", 1);
        lvl += me->query_skill("luoying-zhang", 1);
        lvl += me->query_skill("lanhua-shou", 1);
        lvl += me->query_skill("xuanfeng-tui", 1);
        lvl += me->query_skill("suibo-zhuliu", 1);
        lvl /= 6;


        if (!target) target = offensive_target(me);

        if (!objectp(target)
        || !me->is_fighting(target))
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�÷�Ӱ��\n");

        weapon = me->query_temp("weapon");

        if (!weapon || !(weapon->id("xiao")))
                return notify_fail("������û������޷�ʩչ����Ӱ��\n");

        if (me->query_skill("yuxiao-jian", 1) < 350)
                return notify_fail("������｣��������죬�޷�ʩչ����Ӱ��\n");

        if (me->query_skill("qimen-bagua", 1) < 180)
                return notify_fail("������Ű��Բ�����죬�޷�ʩչ����Ӱ��\n");

        if (me->query_skill("tanzhi-shentong", 1) < 350)
                return notify_fail("��ĵ�ָ��ͨ������죬�޷�ʩչ����Ӱ��\n");

        if (me->query_skill("lanhua-shou", 1) < 350)
                return notify_fail("���������Ѩ�ֲ�����죬�޷�ʩչ����Ӱ��\n");

        if (me->query_skill("luoying-zhang", 1) < 350)
                return notify_fail("�����Ӣ���Ʋ�����죬�޷�ʩչ����Ӱ��\n");

        if (me->query_skill("xuanfeng-tui", 1) < 350)
                return notify_fail("�������ɨҶ�Ȳ�����죬�޷�ʩչ����Ӱ��\n");

        if (me->query_skill("bihai-chaosheng", 1) < 350)
                return notify_fail("��ı̺���������򲻹����޷�ʩչ����Ӱ��\n");

        if (me->query_skill("suibo-zhuliu", 1) < 350)
                return notify_fail("����沨������򲻹����޷�ʩչ����Ӱ��\n");

        if ( me->query_skill_mapped("sword") != "yuxiao-jian"
        || (me->query_skill_mapped("parry") != "yuxiao-jian"&&me->query_skill_mapped("parry") != "tanzhi-shentong")
        || me->query_temp("thd/feiying"))
                return notify_fail("����ʱ�޷�ʹ�÷�Ӱ������\n");

        if (me->query("max_neili") < 7500)
                return notify_fail("��������������޷�ʩչ����Ӱ��\n");

        if (me->query("neili") < 4000)
                return notify_fail("��������������޷�ʩչ����Ӱ��\n");

        if (me->query("jingli") < 2500)
                return notify_fail("��ľ����������޷�ʩչ����Ӱ��\n");

        me->set_temp("thd/feiying", 1);
        message_vision(HIW"\n$N����һ������ʹ���һ���������Ӱ������$n��\n\n"NOR,me, target);

        lvl = to_int( lvl/3.0 * lvl/350.0);//4 -> 3

 if( me->query("quest/jiuyin2/pass")
  && me->query_skill("jiuyin-baiguzhua",1) >450
  && me->query_skill("cuixin-zhang",1) >450 )
 {   j=1;
 target->add_busy(2);
 if(!userp(target))   target->set_temp("must_be_hit",1);
  }
else j = 0;


        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", lvl);

        message_vision(HIG"$N���е�"+weapon->query("name")+HIG"��������ˮһ�㣬��$n�����ع�ȥ��"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
        message_vision(HIG"$nֻ��������˷�������Ӱ����֪���룡\n"NOR,me, target);
        weapon->unequip();
        me->prepare_skill("hand");
        me->prepare_skill("strike");
        me->prepare_skill("cuff");
        me->prepare_skill("finger");
        me->prepare_skill("leg");
        me->prepare_skill("claw");

        if (me->is_fighting(target)) {
                message_vision(HIC"\n$N��"+weapon->query("name")+HIC"������䣬˫��������������$n��ȥ��"NOR,me, target);
                me->prepare_skill("hand", "lanhua-shou");
                qi2 = target->query("qi");
                me->add_temp("apply/hand", lvl*2);
                COMBAT_D->do_attack(me, target, 0, userp(target)?1:3);
                me->add_temp("apply/hand", -lvl*2);
                if (target->query("qi") < qi2)
                        message_vision(HIC"$N���÷�����$n��С����ԪѨ��$n���������޷��������ۣ�\n"NOR,me, target);
        }
        if ( me->is_fighting(target)) {
                message_vision(HIM"\n$Nٿ��ת��Ϊ�ƣ�$n���õ�������Ӱ������ʵʵ�޷�׽����"NOR,me, target);
                me->prepare_skill("hand");
                me->prepare_skill("strike","luoying-zhang");
                qi2 = target->query("qi");
                me->add_temp("apply/strike", lvl*2);
                COMBAT_D->do_attack(me, target, 0, userp(target)?1:3 );
                me->add_temp("apply/strike", -lvl*2);
                if (target->query("qi") < qi2)
                        message_vision(HIM"$NͻȻ����$n��������Ѩ�ϣ�$n���ɵ����˿���Ѫ��\n"NOR,me, target);
        }

 if ( me->is_fighting(target)) {
message_vision(HIB"\n$N�Ʒ�һ���צ��ͻȻʹ�������澭�ϵĹ���"HIW"�������׹�צ��"HIB"��"NOR,me, target);

  if(j>0) {
  message_vision(HIG"\n��"HIW"�����׹�צ"HIG"���Ǻڷ�˫ɷ�ĳ����书���˿�$NͻȻʹ��������$n⧲���������ʱ��ץ���˼���������"NOR,me, target);
  target->set_temp("must_be_hit",1);
  me->add_temp("apply/strike", lvl*2);
           }
                me->prepare_skill("hand");
                me->prepare_skill("strike","luoying-zhang");
                qi2 = target->query("qi");
                me->add_temp("apply/strike", lvl*2);
                COMBAT_D->do_attack(me, target, 0, 3 );
                me->add_temp("apply/strike", -lvl*2);
 if(j>0)        me->add_temp("apply/strike", -lvl*2);               
target->delete_temp("must_be_hit");
                if (target->query("qi") < qi2)
                        message_vision(HIB"$NͻȻצ��$nǰ�ģ�$n���ɵ����´󺧡�\n"NOR,me, target);
        }



        if ( me->is_fighting(target)) {
                message_vision(HIR"\n$N��δ���ƣ�����ɨҶ���Ѿ�����$n��ǰ��"NOR, me, target);
                me->prepare_skill("strike");
                me->prepare_skill("leg","xuanfeng-tui");
                qi2 = target->query("qi");
                me->add_temp("apply/leg", lvl*2);
                COMBAT_D->do_attack(me, target, 0,3 );
                me->add_temp("apply/leg", -lvl*2);
                if (target->query("qi") < qi2)
                        message_vision(HIR"$N�����ü��ȣ�$n�������ˣ���Ͼ������\n"NOR,me, target);
        }
        if (me->is_fighting(target)) {
                message_vision(HIY"\n$N���Ƴ�ָ������$n��ǰ��Ѩ��"NOR,me, target);
                me->prepare_skill("leg");
                me->add_temp("apply/finger", lvl*2);
                me->prepare_skill("finger","tanzhi-shentong");
                me->add_temp("apply/finger", -lvl*2);
                qi2 = target->query("qi");
                COMBAT_D->do_attack(me, target, 0, 3);
                if (target->query("qi") < qi2)
                        message_vision(HIY"$NͻȻһָ��$n̫��Ѩ��ȥ��$nҡҡ�λΣ��ٲ�ά�衣\n"NOR,me, target);
        }





        message_vision(HIW"\n$N��Ӱʹ�꣬��һ�ν�"+weapon->query("name")+HIW"�û����С�\n"NOR,me, target);
        weapon->wield();
        me->start_busy(random(2));
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", -lvl);
        me->add("neili", -450);
        me->add("jingli", -180);
        me->start_perform(2+random(2), "����Ӱ��");
        me->delete_temp("thd/feiying");
        return 1;
}

string perform_name(){ return HIW"��Ӱ"NOR; }

int help(object me)
{
        write(HIW"\n���｣��֮����Ӱ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 4000 ���ϣ�
                ������� 7500 ���ϣ�
                ��ǰ���� 2500 ���ϣ�
                ���｣���ȼ� 350 ���ϣ�
                ���Ű��Եȼ� 180 ���ϣ�
                ��ָ��ͨ�ȼ� 350 ���ϣ�
                ������Ѩ�ֵȼ� 350 ���ϣ�
                ��Ӣ���Ƶȼ� 350 ���ϣ�
                ����ɨҶ�ȵȼ� 350 ���ϣ�
                �̺��������ȼ� 350 ���ϣ�
                �沨�����ȼ� 350 ���ϣ�
                �ֳ��

HELP
        );
        return 1;
}


