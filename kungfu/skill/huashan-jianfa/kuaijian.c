// kuaijian.c ���콣
// by darken@SJ
// modified olives@SJ
// Update By lsxk@hsbbs 2007/6/14
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string perform_name() {return HIG"���콣"NOR;}

int perform(object me, object target)
{
        if( !target || target == me) target = offensive_target(me);

        if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���콣ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
        if (me->query_skill_mapped("force") != "zixia-gong"
          &&me->query_skill_mapped("force") != "huashan-qigong" )
                return notify_fail("����ڹ������޷�ʹ�á����콣����\n");

        if( (int)me->query_dex() < 65 )
                return notify_fail("�������������������㣬����ʹ�ÿ��콣��\n");
        
        if( (int)me->query_skill("zixia-gong", 1) < 350
          &&(int)me->query_skill("huashan-qigong", 1) < 350)
                return notify_fail("��������ڹ����δ�����޷�ʩչ���콣��\n");

        if( (int)me->query_skill("dodge",1) < 350 )
                return notify_fail("���콣��Ҫ�������Ṧ��ϣ�������Чʩչ��\n");

        if( (int)me->query_skill("sword",1) < 350 )
                return notify_fail("�㽣��δ��¯����֮����������ʹ�ÿ��콣��\n");

        if( (int)me->query("neili") <= 6000 )
                return notify_fail("�����������ʹ�ÿ��콣��\n");

        if( me->query("jingli") <= 4000 )
                return notify_fail("��ľ�������ʹ�ÿ��콣��\n");

        if( me->query_temp("hsj_kf",))
                return notify_fail("���������ÿ��콣��\n");

        if(!me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword" 
        || me->query_skill_mapped("sword") != "huashan-jianfa")
                return notify_fail("�������޽�����ʹ�ÿ��콣����\n");

        message_vision(HIG"$N����һ����Х��б�ж�ǰ����������ֱ����Ѹ���ޱȣ�δ�������У�
�������ѷ�������������$N����Խ��Խ�죬����Ҳ�ǽ��졣����һ��
����һ����������ķ���ҲԽ��Խǿ��һ�����ʽ�����콣����̼�
ȫ��$n�����к���\n"NOR, me, target);
        me->set_temp("hsj_kf",1);
        me->add("neili",-1000);
        me->add_temp("apply/attack",me->query_skill("huashan-jianfa",1)/6);
        me->add_temp("apply/damage",me->query_skill("huashan-jianfa",1)/8);
        
   if(me->query_skill("zixia-gong",1)>=550 ) 
   	    target->apply_condition("no_perform", 2+ random(2));

        call_out("kuangfeng", 0, me, target);
        me->start_perform(999,"�����콣��");
        return 1;
}

void kuangfeng(object me, object target)
{
        int i;
        object weapon;
        
        if (!me) return;
        weapon= me->query_temp("weapon");
       
        if(me->is_busy() && me->query("quest/huashan") != "����"){
            message_vision(HIG"$N�ġ����콣��ίʵ�켫��һ�������Ƭ�̼����ʹ�ꡣ\n"NOR, me);
            me->add_temp("apply/damage",-me->query_skill("huashan-jianfa",1)/8);
            me->add_temp("apply/attack",-me->query_skill("huashan-jianfa",1)/6);
            me->delete_temp("hsj_kf");
            me->start_busy(3+random(3));
            me->start_perform(2+random(3),"�����콣��");
            return;
        }
        if (me->is_fighting(target) &&
//           !me->is_busy()          &&
            (int)me->query("jingli") > 1000 &&
            (int)me->query("neili") > 2000 &&
           objectp(target) && 
           !target->is_ghost() &&
           !me->is_ghost() && 
           me->query_temp("hsj_kf")<27 &&
           environment(me) == environment(target) &&
           weapon &&
           weapon->query("skill_type") == "sword"  
            ) {
          message_vision(HIG"�Թ�����ֻ���������ˣ����ϡ����ϱ�����ε��������ۣ����������ĺ��ˡ�\n"NOR, me);
          if((int)me->query_temp("hsj_kf")%3==0 && me->query("quest/huashan") == "����" && random(2)){
              message_vision(HBRED"$n���������˿�Ľ��У����°����Ծ���ȫ�����ػ���$N���������ƣ�\n"NOR, me, target);
              target->add_temp("lost_attack",1+random(2));
          }
          for (i = 0; i < 3; i++) {
           if (me->is_fighting(target)) {
            if (me->query("quest/huashan") == "����" ||   me->query_skill("zixia-gong",1)>=550 ){
               me->add_temp("apply/attack",me->query_skill("huashan-jianfa",1)/3);
               me->add_temp("apply/damage",me->query_skill("huashan-jianfa",1)/5);
               COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
               me->add_temp("apply/attack",-me->query_skill("huashan-jianfa",1)/3);
               me->add_temp("apply/damage",-me->query_skill("huashan-jianfa",1)/5);
            }
            else
               COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
           }
          }
          me->add("neili", -200-random(50));
          me->add("jingli", -100-random(30));
          me->add_temp("hsj_kf",1);
          call_out("kuangfeng", 2, me, target);
          return;
        }
        message_vision(HIG"$N�ġ����콣��ίʵ�켫��һ�������Ƭ�̼����ʹ�ꡣ\n"NOR, me);
        me->add_temp("apply/damage",-me->query_skill("huashan-jianfa",1)/10);
        me->add_temp("apply/attack",-me->query_skill("huashan-jianfa",1)/6);
        me->delete_temp("hsj_kf");
        if(me->query("gender")!="����")
        me->start_busy(2+random(3));
        else me->start_busy(1+random(2));
        me->start_perform(2+random(3),"�����콣��");
}

int help(object me)
{
	write(WHT"\n��ɽ������"HIG"���콣"WHT"����"NOR"\n");
	write(@HELP
    ���콣�����б�������������֮�죬����֮�Ͽ������κ��书����
    ����ϸ��£����˻�ɽ���ھ��������־�ѧ����ɽ���ڵ����ռ�����
    ���й���һ������У�һ���ǳɣ�����������ˮ���ʹ���������Թ�
    ��Ҳ��Ϊ�佣��֮��������Ȼ�����ж�ʹ���ߵĽ����������ڹ�Ҫ
    ���ĸߡ���ɽ���ڵ���Ҳ��ʹ�ã�������ȴ��������֮�����ĳɡ�
    ��ϼ���ȼ�550����������ӳɡ�
    ָ�perform kuaijian

    Ҫ�󣺻�ɽ���� ���� ��ϼ�� 350��
          ����������65��
          ��������350����
          �����Ṧ350����
          ������65���ϣ�
          ��ǰ����6000���ϣ�
          ��ǰ����4000���ϡ�
HELP
	);
	return 1;
}
