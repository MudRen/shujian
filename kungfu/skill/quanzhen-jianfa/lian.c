// modified by snowman@SJ 05/12/2000
// Modify By River@Sj
// Modify By jpei


#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>

int next1(object me, object target, int i);
int next2(object me, object target, int i);

int perform(object me,object target)
{
        object weapon;
        string msg;
        int ap,dp;
        int i = me->query_skill("haotian-zhang",1) / 2 + me->query_skill("quanzhen-jianfa",1) /2 ;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("����ڹ��������칦���޷�ʹ����������\n");

 if(me->query("quest/quanzhen/sword/lianhuan")!=1)
                return notify_fail("����Ȼ��˵������������������һֱû���������о��ϣ����������ã�\n");

        if( me->query_skill("xiantian-gong", 1) < 120 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ����������\n");

        if( me->query_skill("quanzhen-jianfa", 1) < 120 )
                return notify_fail("��Ľ�����δ���ɣ�����ʹ����������\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "quanzhen-jianfa")
                return notify_fail("������û�н����޷�ʹ����������\n");
   
     if (me->query_skill_prepared("strike") != "haotian-zhang"
            || me->query_skill_mapped("strike") != "haotian-zhang")
                return notify_fail("�������޷�ʹ�á������������й�����\n");  

        if(me->query_skill_mapped("parry") != "quanzhen-jianfa"
        && me->query_skill_mapped("parry") != "haotian-zhang")
                return notify_fail("����мܹ��򲻶ԣ��޷�ʹ����������\n");

        if(me->query("max_neili") < 1200 )
                return notify_fail("���������Ϊ����������ʹ����������\n");
        if(me->query("neili") < 1000 )
                return notify_fail("�������������㣬����ʹ����������\n");
        if(me->query("jingli") < 600 )
                return notify_fail("�����ھ������㣬����ʹ����������\n");
        if(me->query_temp("qzjf/lian"))
                return notify_fail("������ʹ����������\n");

        if(me->query_skill("sword", 1) < 120 )
                return notify_fail("��Ļ�������������죬�����ڽ�����ʹ����������\n");


        msg = HBRED"\n$Nʹ���������������У���Ȼ�������֣��ٽ�ƽ�̣���������â������ȥ�ƾ��죡\n"NOR;
              message_vision(msg, me, target);

        me->start_perform(3, "����������");
        me->add_temp("apply/attack", me->query_skill("quanzhen-jianfa",1) /3);
        me->add_temp("apply/damage", me->query_skill("quanzhen-jianfa",1) /3);
                me->set_temp("qzjf/lian", 1);
             

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        me->add_temp("apply/attack", -me->query_skill("quanzhen-jianfa",1) /3);
        me->add_temp("apply/damage", -me->query_skill("quanzhen-jianfa",1) /3);

                me->add("neili", -150);

        if ( me->query_skill("xiantian-gong", 1) > 120)
                next1(me, target, i);
        else 
                me->delete_temp("qzjf/lian");
        return 1;
}

int next1(object me, object target, int i)

{
        string msg;
        int damage, ap,dp;
        object weapon;

        if (!me) return 0;

        weapon = me->query_temp("weapon");
        if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
                me->delete_temp("qzjf/lian");
                return 0;
        }
        msg = HIR"\n������$N�����ǰ��һ��ӡ��$n��ǰ��������������¡�"NOR;
        ap = me->query("combat_exp", 1) * me->query_con(1)/10000;
        dp = target->query("combat_exp", 1) * target->query_con(1)/10000;
        if((userp(target)&& random(ap + dp) > dp/2 )|| !userp(target)){
                msg += HIR"$nֻ���ڵ�һ�����ײ����ֱײ���Լ���ð���ǡ�\n"NOR;
                damage = me->query_skill("quanzhen-jianfa",1)*3;
                damage += me->query_skill("sword")*3;
                damage += random(damage);
                if ( damage > 3000 )
                        damage = 3000 + (damage - 1000)/10;
  
                target->add("neili",-(300+random(150)));
                target->receive_damage("qi", damage, me);

                target->receive_wound("qi", damage/3, me);
                msg += damage_msg(damage, "����");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target, random(2));
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"HIR+ damage+ WHT"���˺���\n"NOR); 

        me->add_temp("apply/attack", me->query_skill("haotian-zhang",1) /3);
        me->add_temp("apply/damage", me->query_skill("haotian-zhang",1) /3);

        if(random(3))            target->add_condition("no_perform", 1);
        if(random(3))            target->add_condition("no_exert", 1);
           if(!userp(target))    target->add_busy(2);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        me->add_temp("apply/attack", -me->query_skill("haotian-zhang",1) /3);
        me->add_temp("apply/damage", -me->query_skill("haotian-zhang",1) /3);

                me->add("neili",-200);
                me->add("jingli",-80);
                me->start_perform(3, "����������");
        }
        else {
                msg  += CYN"\n$nһ����¿�����Σ��֮�ж������һ����\n"NOR;
                message_vision(msg, me, target);
                me->add("neili", -80);
                me->add_busy(random(2));
        }
        if (me->query_skill("quanzhen-jianfa", 1) > 160)
                next2(me, target, i);
        else
                me->delete_temp("qzjf/lian");
        return 1;
}

int next2(object me, object target, int i)
{
        string msg;
        int damage, ap, dp;
        object weapon;
        if( !me ) return 0;
        weapon = me->query_temp("weapon");
        if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
                me->delete_temp("qzjf/lian");
                return 0;
        }

        msg = HIC"\n����$nƣ�ڷ���֮�ʣ�$N���г����������̣�����ȴ��һ��ɨ����\n"NOR;
        ap = me->query("combat_exp", 1) * me->query_str(1);
        dp = target->query("combat_exp", 1) * target->query_str(1);
      if((userp(target)&& random(ap + dp) > dp)|| !userp(target)){

                damage = me->query_skill("quanzhen-jianfa",1)*5;
                damage += me->query_skill("sword",1)*2;
                damage += random(damage);
                if ( damage > 5000 )
                        damage = 5000 + (damage - 1000)/10;
   

                target->add_temp("apply/attack", -80);
                target->add_temp("apply/dodge", -80);
                target->add_temp("apply/armor", -100);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                msg += damage_msg(damage, "����");

                message_vision(msg, me, target);

                COMBAT_D->report_status(target, random(2));
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"HIR+ damage+ WHT"���˺���\n"NOR); 

        me->add_temp("apply/attack", me->query_skill("xiantian-gong",1) /2);
        me->add_temp("apply/damage", me->query_skill("xiantian-gong",1) /2);

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        me->add_temp("apply/attack", -me->query_skill("xiantian-gong",1) /2);
        me->add_temp("apply/damage", -me->query_skill("xiantian-gong",1) /2);
                me->add("neili",- 150);
                me->add("jingli",-80);
                me->start_perform(3 + random(2),"����������");
                call_out("back", 5 + random(me->query("jiali") / 20), target);
        } 
        else {
                msg = msg + HIW "$nһ�����ذδУ�Ծ�����ɣ������ܹ���\n" NOR;
                message_vision(msg, me, target);
                me->add("neili", -70);
                me->add_busy(random(2));
        }
        me->delete_temp("qzjf/lian");
        return 1;
}

void back(object target)
{
        if (!target) return;
        target->add_temp("apply/attack", 80);
        target->add_temp("apply/dodge", 80);
        target->add_temp("apply/armor", 100);
}

string perform_name(){ return HIG"������"NOR; }
int help(object me)
{
        write(HIG"\nȫ�潣��֮������������"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 1200 ���ϣ�
                ��ǰ���� 600 ���ϣ�
                ȫ�潣���ȼ� 120 ���ϣ�
                ���칦�ȼ� 120 ���ϣ�
                ���������ȼ� 120 ���ϣ�
                ��������Ϊȫ�潣����
                �����м�Ϊȫ�潣��������ƣ�
                �����ڹ�Ϊ���칦��
HELP
        );
        return 1;
}
