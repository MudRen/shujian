// by darken@SJ
// modified by Olives@SJ 5/4/2001
// �����������bug
// By Spiderii@ty����Ч��
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <combat_msg.h>

string perform_name(){ return HBBLU"�����ơ�"NOR; }
int perform(object me, object target)
{
        int p, j,h;
        string msg;
        j = me->query_skill("tiezhang-zhangfa", 1);

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
          || !me->is_fighting(target)
          || !living(target)
          || environment(target)!= environment(me))
                return notify_fail("�����ơ�ֻ����ս���жԶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����ơ���\n");

        if( (int)me->query_skill("tiezhang-zhangfa", 1) < 350 )
                return notify_fail("������Ʋ�����죬ʹ�������ƾ�����\n");
/*
        if( (int)me->query_skill("guiyuan-tunafa", 1) < 350 )
                return notify_fail("���Ԫ���ɷ�������ʹ�������ƾ�����\n");
*/
        if( (int)me->query_skill("shuishangpiao", 1) < 350 )
                return notify_fail("��ˮ��Ʈ�ȼ�������ʹ�������ƾ�����\n");

        if( (int)me->query("jiali") < 200 )
                return notify_fail("�����������ʹ�������ƾ�����\n");
/*
        if (me->query_skill_mapped("force") != "guiyuan-tunafa")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
*/
        if( (int)me->query_str() < 60 )
                return notify_fail("�������������ǿ����ʹ���������ơ�����\n");

        if( (int)me->query_con() < 60 )
                return notify_fail("�����񻹲�����׳��ʹ���������ơ�����\n");

        if( (int)me->query_dex() < 60 )
                return notify_fail("�����������Ѹ�ݣ�ʹ���������ơ�����\n");

        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa"
         || me->query_skill_mapped("strike") != "tiezhang-zhangfa"
         || me->query_skill_mapped("parry") != "tiezhang-zhangfa"
         || me->query_temp("weapon"))
                return notify_fail("�������޷�ʹ�á����ơ���\n");

        if( (int)me->query("max_neili") < 7000)
                return notify_fail("����������̫����ʹ���������ơ���\n");

        if( (int)me->query("neili") < 5000 )
                return notify_fail("����������̫����ʹ���������ơ���\n");

        j *= 7;
        j += me->query("jiali")*8;
        j -= target->query_con()*10;
        j = j + random(j/4);

h = target->query("str");
if (h < 50) h =  target->query("con");
if (h < 50) h =  target->query("dex");
if (h < 50) h =  target->query("int");


        msg = HBBLU "\n$N�����������ۼ������ϣ�˿�����κλ��ɣ�ƽƽ����$n������ȥ��\n"NOR;
        msg+= HBBLU "$nȫ��������ȫ����������ס��ֻ��Ӳ��Ӳ������һ�С�\n"NOR;

if(h <50)  if (random(me->query_str()) > target->query_str()/3
        &&  random(me->query_dex(1)) > target->query_dex(1)/3
        &&  random(me->query("neili")) > target->query("neili")/3
        &&  random(me->query_skill("force")) > target->query_skill("force") /3 )
        {
                msg += HBRED"$n��$N��һ�ƴ��Ѫ��ģ����\n"NOR;
                me->kill_ob(target);
                target->set_temp("last_damage_from", me);
                //target->set("max_qi", -1);���д��������һ���
                // darken�ϴ���д���˰ɣ�
//���˾����ˡ�                target->set("eff_qi",-1);
                target->set("qi",-1);
//                 if (userp(target) && userp(me)) me->apply_condition("killer",200);

        }
         else
        {
                target->receive_wound("qi", j /3 );
                target->receive_damage("qi",j);
                msg += HBRED"ֻ��$nһ���Һ���������˼��ص��ˣ�\n"NOR;
        }
        p = (int)target->query("qi")*100/(int)target->query("max_qi");
        msg += "( $n"+eff_status_msg(p)+" )\n";
        me->add("neili", -2500-random(500));
        message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+ j+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"HIR+ j+ WHT"���˺���\n"NOR);
        me->start_busy(4);
        me->start_perform(7,"�����ơ�");
        return 1;
}

