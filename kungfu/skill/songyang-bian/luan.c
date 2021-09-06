// luan.c
// Created by Numa 2000.1.25

#include <ansi.h>
inherit F_SSERVER;

string perform_name() {return BLU"�ұ޾�"NOR;}

int perform(object me, object target)
{
        object weapon;
        int i, tmp;
        
        if( !target ) target = offensive_target(me);

        if( !target 
          || !me->is_fighting(target)
          || !objectp(target)
          || environment(target)!= environment(me))
                return notify_fail("�ұ޾�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("songyang-bian", 1) < 120 )
                return notify_fail("��������޻�򲻹���\n");

        if( (int)me->query_skill("whip", 1) < 120 )
                return notify_fail("��Ļ����޷���򲻹���\n");
        if( (int)me->query_skill("hanbing-zhenqi", 1) < 120 )
                return notify_fail("��ĺ���������򲻹���\n");
                
        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("���������Ϊ������\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");
        if (me->query_skill_mapped("force") != "hanbing-zhenqi")
                return notify_fail("���޷�ʹ���ұ޾���\n");
        if (!objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "whip"
         || me->query_skill_mapped("parry") != "songyang-bian"
         || me->query_skill_mapped("whip") != "songyang-bian")
                return notify_fail("���޷�ʹ���ұ޾���\n");

        if (me->query_temp("ss_luan"))
                return notify_fail("������ʹ���ұ޾���\n");

        me->add("neili", -200);
        message_vision(BLU "\n$NͻȻ���²������ң����д��ͣ���ʽ�����ٳ���ȫ�����ҪѨ����¶���ɣ�\n$nһ���˻�������֮�£��ִ��������С���֪$N��Ϊ���У��������г���һ�������ұ޾���֮������������Ʋ��ɵ���\n" NOR,me, target);

        tmp = (me->query_skill("songyang-bian",1) + me->query("hanbing-zhenqi",1))/15;
        tmp += random(tmp);
        me->add_temp("apply/dexerity", tmp);
        me->set_temp("ss_luan",1);
        i = me->query_skill("whip")/2;
        if (wizardp(me))
                tell_object(me,"Dexerity Add "+ tmp + "��Callout Waiting Time Is "+ i +"��\n");
        call_out("check_fight", 1, me, target, tmp, i);
        me->start_busy(2+random(3));
        return 1;
}

int check_fight(object me, object ob, int tmp, int i)
{
        object weapon;
//        int num;
//        string msg;

        if (!me)
                return 0;
        if (me->is_ghost() || !living(me) || !me->query_temp("ss_luan") || i <1)
        {
                me->add_temp("apply/dexerity", -tmp);
                call_out("remove_effect",5+random(5),me);
                return 1;
        }
        if (!me->is_fighting() || me->query("neili") <= 100)
        {
                me->add_temp("apply/dexerity", -tmp);
                message_vision(CYN"\n$Nһ���ұ޾�ʹ�գ��������������ڳ��С�\n"NOR,me);
                call_out("remove_effect",5+random(5),me);
                return 1;
        }
        if (userp(me)
        && (me->query_skill_mapped("force") != "hanbing-zhenqi"
        ||  me->query_skill_mapped("whip") != "songyang-bian"
        ||  me->query_skill_mapped("parry") != "songyang-bian"
        ||  !objectp(weapon = me->query_temp("weapon"))
        ||  weapon->query("skill_type") != "whip"))
        {
                me->add_temp("apply/dexerity", -tmp);
                message_vision(CYN"\n$Nһ���ұ޾�ʹ�գ��������������ڳ��С�\n"NOR,me);
                call_out("remove_effect",5+random(5),me);
                return 1;
        }
        if (!ob || ob->is_ghost())
        {
                me->add_temp("apply/dexerity", -tmp);
                message_vision(CYN"\n$Nһ���ұ޾�ʹ�գ��������������ڳ��С�\n"NOR,me);
                call_out("remove_effect",5+random(5),me);
                return 1;
        }

/*        
        if (me->query_skill("whip") > 200 && me->query_skill("whip") < 400)
            num = 10;
        if (me->query_skill("whip") > 400 && me->query_skill("whip") < 600)
            num = 30;
        if (me->query_skill("whip") > 600 && me->query_skill("whip") < 800)
            num = 50;
        if (me->query_skill("whip") > 800)
            num = 70;
        if (wizardp(me) && me->query("env/test"))  tell_object(me,CYN"NumΪ"+num+"��\n"NOR);
        if (random(me->query_skill("whip")/10)>num && random(6) > 3)
        {
                switch(random(5))
                {
                        case 0 : msg = HIY"\n$N��$n���г�����ǿ����������һ��������$n��\n"NOR;
                                 break;
                        case 1 : msg = HIR"\n$n���мȳ��������ջ����ǲ��ܣ���ǿ������$N���ѽ�$w����$n�Ĵ�ҪѨ��\n"NOR;
                                 break;
                        case 2 : msg = HIG"\n$N���Լ��������𽥻��ң��鼱֮�£�������շɳ���$w��ĩ��ȴ��ɨ��$n������Ѩ��\n"NOR;
                                 break;
                        case 3 : msg = HIB"\n$N���һ����������·��ֻ��ƴ��һ����������ˣ�$w���ƶ�Ȼ������$n�����м�֮����\n"NOR;
                                 break;
                        case 4 : msg = HIW"\n$n��$N������Ȼ���������а����кã�����һԽ�����������ϵ��������ű�Ӱ��ʹ$n�޴����Σ�\n"NOR;
                                 break;
                }
                message_vision(msg,me,ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        }
*/        
        call_out("check_fight", 1, me, ob, tmp, i-1);
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("ss_luan");
}

